---------------------------------------------------------
  572. Subtree of Another Tree
Solved
Easy
Topics
Companies
Hint
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
---------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compareTree(TreeNode* root, TreeNode* subRoot){
        if (!subRoot) {
            if (!root)
                return true;
            else
                return false;
        }
        if (!root) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        bool rcomp=compareTree(root->right, subRoot->right);
        bool lcomp=compareTree(root->left, subRoot->left);

        return (rcomp && lcomp);
    }
    void ttTree(TreeNode* root, TreeNode* subRoot, bool &valid) {
        if (!root) {
            return;
        }
        bool rcomp=compareTree(root->right, subRoot);
        bool lcomp=compareTree(root->left, subRoot);
        valid = valid || (rcomp || lcomp);
        ttTree(root->right, subRoot, valid);
        ttTree(root->left, subRoot, valid);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { 
        bool valid=false;
        if(compareTree(root, subRoot)) {
            return true;
        }
        ttTree(root, subRoot, valid);
        return valid;
    }
};
