//The main idea is to find the path and compare
//
//What can I learn from this answer?
//  The findPath() function is well written. This is the way to use stack to do dfs.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &v){
        if(root == nullptr) return false;
        if(root == p){
            v.push_back(p);
            return true;
        }
        v.push_back(root);
        if(findPath(root->left, p, v)) return true;
        if(findPath(root->right,p, v)) return true;
        v.pop_back();
        
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;
        findPath(root, p, p1);
        findPath(root, q, p2);
        TreeNode *res = root;
        for(int i=0;i<p1.size() && i<p2.size();i++){
            if(p1[i] != p2[i]){
                return res;
            }
            res = p1[i];
        }
        return res;
    }
};
