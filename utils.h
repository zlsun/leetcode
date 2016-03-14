#include <zlog.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode* from(const std::vector<int>& t) {
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
    std::vector<int> to() const {
        std::vector<int> v;
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
