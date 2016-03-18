#include <zlog.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode* from(const vi& t) {
        ListNode* root = NULL;
        ListNode* pre = NULL;
        for (auto& x : t) {
            if (root == NULL) {
                root = new ListNode(x);
                pre = root;
            } else {
                pre->next = new ListNode(x);
                pre = pre->next;
            }
        }
        return root;
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
    bool equal(ListNode* b) {
        return to() == b->to();
    }
};

struct TreeNode {
    struct Builder {
        TreeNode* p;
        Builder(TreeNode* p = nullptr): p(p) {}
        Builder(int d, Builder l = Builder(), Builder r = Builder())
            : p(new TreeNode(d, l.p, r.p)) {}
        operator TreeNode* () const {
            return p;
        }
    };
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l = NULL, TreeNode* r = NULL) : val(x), left(l), right(r) {}
    bool equal(TreeNode* t) {
        if (t == NULL) return false;
        bool sameLeft = (left == NULL && t->left == NULL)
            || (left && t->left && left->equal(t->left));
        bool sameRight = (right == NULL && t->right == NULL)
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
