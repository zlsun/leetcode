
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>

#include <zlog.h>

using namespace std;

template <class T>
using V = vector<T>;
template <class T>
using v = V<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using vv = VV<T>;

using Vi = V<int>;
using vi = Vi;
using VVi = VV<int>;
using vvi = VVi;
using Pii = pair<int, int>;
using pii = Pii;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n = nullptr): val(x), next(n) {}
    struct Builder {
        ListNode* p;
        Builder(ListNode* p = nullptr): p(p) {}
        Builder(int val, Builder b = Builder())
            : p(new ListNode(val, b.p)) {}
        Builder(const initializer_list<int>& ilist)
            : p(from(ilist)) {}
        operator ListNode* () const {
            return p;
        }
    };
    template <class T>
    static ListNode* from(const T& t) {
        ListNode* root = nullptr;
        ListNode* pre = nullptr;
        for (auto& x : t) {
            if (!root) {
                root = new ListNode(x);
                pre = root;
            } else {
                pre->next = new ListNode(x);
                pre = pre->next;
            }
        }
        return root;
    }
    static ListNode* from(const initializer_list<int>& ilist) {
        return from(vi{ilist});
    }
    vi to() const {
        vi v;
        const ListNode* cur = this;
        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        return v;
    }
    bool equal(ListNode* b) const {
        return to() == b->to();
    }
    void print() const {
        zlog to();
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(
        int x,
        TreeNode* l = nullptr,
        TreeNode* r = nullptr
    ): val(x), left(l), right(r) {}
    struct Builder {
        TreeNode* p;
        Builder(TreeNode* p = nullptr): p(p) {}
        Builder(int d, Builder l = Builder(), Builder r = Builder())
            : p(new TreeNode(d, l.p, r.p)) {}
        operator TreeNode* () const {
            return p;
        }
    };
    bool equal(TreeNode* t) const {
        if (!t) return false;
        bool sameLeft = (!left && !t->left)
            || (left && t->left && left->equal(t->left));
        bool sameRight = (!right && !t->right)
            || (right && t->right && right->equal(t->right));
        return val == t->val && sameLeft && sameRight;
    }
    void print(int level = 0) const {
        zloga(true, false) string(level * 2, ' '), val;
        if (left) left->print(level + 1);
        if (right) right->print(level + 1);
    }
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(
        int x,
        TreeLinkNode* l = nullptr,
        TreeLinkNode* r = nullptr,
        TreeLinkNode* n = nullptr
    ): val(x), left(l), right(r), next(n) {}
    struct Builder {
        TreeLinkNode* p;
        Builder(TreeLinkNode* p = nullptr): p(p) {}
        Builder(int d, Builder l = Builder(), Builder r = Builder())
            : p(new TreeLinkNode(d, l.p, r.p)) {}
        operator TreeLinkNode* () const {
            return p;
        }
    };
    bool equal(TreeLinkNode* t) const {
        if (!t) return false;
        bool sameLeft = (!left && !t->left)
            || (left && t->left && left->equal(t->left));
        bool sameRight = (!right && !t->right)
            || (right && t->right && right->equal(t->right));
        return val == t->val && sameLeft && sameRight;
    }
};

struct Assert {
    int lineno;
    Assert(int l): lineno(l) {}
    Assert& operator , (bool ok) {
        if (ok) {
            zlog lineno, "Assert passed";
        } else {
            zlog lineno, "Assert failed";
        }
        return *this;
    }
};

#define ASSERT Assert(__LINE__),
