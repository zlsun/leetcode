/** 341. Flatten Nested List Iterator
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

**/

#include <iostream>
#include "../utils.h"
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
private:
    bool is_integer;
    int integer;
    vector<NestedInteger> list;
public:
    NestedInteger(int i = 0): is_integer(true), integer(i) {}
    NestedInteger(const vector<NestedInteger>& l): is_integer(false), list(l) {}
    struct Builder;

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return is_integer;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return integer;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return list;
    }
};

struct NestedInteger::Builder {
    NestedInteger i;
    Builder(int i): i(i) {}
    Builder(NestedInteger i): i(i) {}
    Builder(initializer_list<Builder> l) {
        vector<NestedInteger> v;
        for (auto b : l) {
            v.push_back(b);
        }
        i = NestedInteger(v);
    }
    operator NestedInteger () const {
        return i;
    }
    operator vector<NestedInteger> () const {
        return i.getList();
    }
};

class NestedIterator {
private:
    const vector<NestedInteger>& nestedList;
    vector<NestedInteger>::const_iterator iter;
    NestedIterator* innerIter;
public:
    NestedIterator(const vector<NestedInteger>& nestedList)
        : nestedList(nestedList)
        , iter(nestedList.begin())
        , innerIter(nullptr)
    {
        genInner();
    }

    ~NestedIterator() {
        delete innerIter;
    }

    void genInner() {
        delete innerIter;
        innerIter = nullptr;
        if (hasNext() && !iter->isInteger()) {
            innerIter = new NestedIterator(iter->getList());
        }
    }

    int next() {
        if (innerIter && innerIter->hasNext()) {
            int n = innerIter->next();
            if (!innerIter->hasNext()) {
                ++iter;
                genInner();
            }
            return n;
        }
        int n = iter->getInteger();
        ++iter;
        genInner();
        return n;
    }

    bool hasNext() {
        if (innerIter) {
            if (innerIter->hasNext()) return true;
            ++iter;
            genInner();
            return hasNext();
        }
        return iter != nestedList.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

vi flatten(NestedIterator i) {
    vi v;
    while (i.hasNext()) {
        v.push_back(i.next());

    }
    return v;
}

int main() {
    using B = NestedInteger::Builder;
    ASSERT flatten(NestedIterator(B {})) == Vi {};
    ASSERT flatten(NestedIterator(B {{}})) == Vi {};
    ASSERT flatten(NestedIterator(B {{}, 3})) == Vi {3};
    ASSERT flatten(NestedIterator(B {{}, {}, 3})) == Vi {3};
    ASSERT flatten(NestedIterator(B {1, 2})) == Vi {1, 2};
    ASSERT flatten(NestedIterator(B {1, {2, 3}})) == vi {1, 2, 3};
    ASSERT flatten(NestedIterator(B {{1, 2}, 3, {4, 5}})) == vi {1, 2, 3, 4, 5};
    ASSERT flatten(NestedIterator(B {{1, 2}, {3}, {4, 5}})) == vi {1, 2, 3, 4, 5};
    return 0;
}
