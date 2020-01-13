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
    vector<vector<int>> all_path(TreeNode* node){
        vector<vector<int>> ans, left, right;
        if(node == NULL) return ans;
        left = all_path(node->left);
        right = all_path(node->right);
        left.insert(left.end(), right.begin(), right.end());
        if(left.empty()){
            ans.push_back(vector<int>({node->val}));
        }
        for(auto &&it:left){
            vector<int> v({node->val});
            v.insert(v.end(), it.begin(), it.end());
            ans.push_back(v);
        }
        return ans;
    }
    int get_sum(const vector<int> &v){
        int sum = 0;
        for(auto &&it:v){
            sum += it;
        }
        return sum;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths = all_path(root);
        vector<vector<int>> ans;
        for(auto &&it:paths){
            if(get_sum(it) == sum) ans.push_back(it);
        }
        return ans;
    }
};

// This is a recursive version
// without the right condition, I may fail the following case:
// tree = [1, 2], sum = 1;
// My ans: [[1]] Exp: []
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans, left, right;
        if(root == NULL) return ans;
        left = pathSum(root->left, sum - root->val);
        right = pathSum(root->right, sum - root->val);
        left.insert(left.end(), right.begin(), right.end());
        //Tricky last condition, need to make sure only the leaf node
        //get inserted.
        if(left.empty() && root->val == sum && (!root->left && !root->right)){
            ans.push_back(vector<int>({root->val}));
        }
        for(auto &&it : left){
            vector<int> v({root->val});
            v.insert(v.end(), it.begin(), it.end());
            ans.push_back(v);
        }
        return ans;
    }
};
