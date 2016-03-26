/** 173. Binary Search Tree Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* node = nodes.top(); nodes.pop();
        int res = node->val;
        node = node->right;
        while (node) {
            nodes.push(node);
            node = node->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    {
        TreeNode* tree = TreeNode::Builder {};
        BSTIterator i = BSTIterator(tree);
        while (i.hasNext()) cout << i.next() << " ";
        cout << endl;
    }
    {
        TreeNode* tree = TreeNode::Builder {
            40, {20, 10, 30}, {60, {50, 41, nullptr}, 70}
        };
        BSTIterator i = BSTIterator(tree);
        while (i.hasNext()) cout << i.next() << " ";
    }
    return 0;
}
