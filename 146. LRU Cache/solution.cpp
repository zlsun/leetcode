/** 146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> pos;
    void use(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
public:
    LRUCache(int capacity): capacity(capacity) {}
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            use(key);
            return cache[key];
        }
        return -1;
    }
    void set(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

int main() {
    LRUCache c(2);
    c.set(1, 1);
    c.set(2, 2);
    ASSERT c.get(2) == 2;
    ASSERT c.get(1) == 1;
    c.set(3, 3);
    ASSERT c.get(1) == 1;
    ASSERT c.get(2) == -1;
    ASSERT c.get(3) == 3;
    return 0;
}
