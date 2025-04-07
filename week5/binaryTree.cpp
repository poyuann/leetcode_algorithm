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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return rebuild(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
        }
        TreeNode* rebuild(int leftpre, int rightpre, int leftin, int rightin, vector<int> &preorder, vector<int> &inorder) {
            if (leftpre > rightpre || leftin > rightin) return nullptr;
            TreeNode *root = new TreeNode(preorder[leftpre]);
            int rootin = leftin;
            while (rootin <= rightin && inorder[rootin] != preorder[leftpre]) ++rootin;
            int leftsize = rootin - leftin;
            root->left = rebuild(leftpre + 1, leftpre + leftsize, leftin, rootin - 1, preorder, inorder);
            root->right = rebuild(leftpre + leftsize + 1, rightpre, rootin + 1, rightin, preorder, inorder);
            return root;
        }
    };