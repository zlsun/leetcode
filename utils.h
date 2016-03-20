
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>

#include <zlog.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    struct Builder {
        ListNode* p;
        Builder(ListNode* p = nullptr): p(p) {}
        Builder(const std::initializer_list<int>& ilist)
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
    static ListNode* from(const std::initializer_list<int>& ilist) {
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
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
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
    Assert& operator , (bool ok)
    {
        if (ok) {
            zlog lineno, "Assert passed";
        } else {
            zlog lineno, "Assert failed";
        }
        return *this;
    }
};

#define ASSERT Assert(__LINE__),
