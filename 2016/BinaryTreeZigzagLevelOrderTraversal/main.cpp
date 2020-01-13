//This is a very simple variant of BFS tree traversal
//Can simply use a counter to identify odd/even of each
//level and decide if need to reverse current level or not.

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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(root == NULL) return ans;
            queue<TreeNode*> q;
            q.push(root);
            TreeNode *last  = root;
            int level = 0;
            vector<int> cnt_lvl;
            while(!q.empty()){
                root = q.front();
                q.pop();
                cnt_lvl.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                if(root == last){
                    last = q.back();
                    if(level % 2 == 1){
                        reverse(cnt_lvl.begin(), cnt_lvl.end());
                    }
                    ans.push_back(cnt_lvl);
                    cnt_lvl.clear();
                    level++;
                }
            }
            return ans;
        }
};
