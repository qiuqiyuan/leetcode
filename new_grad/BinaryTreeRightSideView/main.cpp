//This is very much just BFS
//The trick is to remember the last element of each level. 
//When done processing this very last element, we are 
//at the end; the new q.back() is the new last of the level. 

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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* l_last = root; // level last;
        while(!q.empty()){
            root = q.front();
            q.pop();
            
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            
            if(root == l_last){
                ans.push_back(l_last->val);
                l_last = q.back();
            }
        }
        return ans;
    }
};

