//This solution does not give back the 100% desired answer
//The idea is to use the result of all the combination
//of generateTrees(r) and generateTrees(n-1-r) to come up with 
//the result of n.
//
//The problem is the way to label nodes, without a global variable
//I have trouble label each node with different ids because I do 
//not have information of what numbers have been used. 
//
//So this solution will give back right strucutres, but not right lebels.

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans, left, right;
        if(n == 0) {
            ans.push_back(nullptr);
            return ans;
        }
        TreeNode *root = NULL;
        for(int i=0;i<n; i++){
            left = generateTrees(i);
            right = generateTrees(n-1-i);
            for(auto &&cl : left)
                for(auto &&cr : right){
                    root = new TreeNode(n);
                    root->left = cl;
                    root->right = cr;
                    ans.push_back(root);
                }
        }
        return ans;
    }
};


 //The idea of this solution is to restric the number labels
 //that can be used.
 //This is differnt from the above solution in that by using
 //boght start and end markers, program is given a chance to
 //say what the current node's val will be. Because the [s, e]
 //range is strictly ordered, this will create a BST.

 //why do I have to use start and end range.
 //what is it I am missing without the start and end range?
 //how can I find all possible binary search tree?
class Solution {
    vector<TreeNode*> generateTrees(int s, int e){
        vector<TreeNode*> left, right, ans;
        if( s > e) {
            ans.push_back(nullptr);
            return ans;
        }
        
        for(int i=s; i<=e; i++){
            left = generateTrees(s, i-1);
            right = generateTrees(i+1, e);
            for(auto &&itl : left)
                for(auto &&itr: right){
                    TreeNode *root = new TreeNode(i);
                    root->left = itl;
                    root->right = itr;
                    ans.push_back(root);
                }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

//How can you generate all possible binary tree?
// - we already did. This gives all possible binarytrees.
// http://blogs.msdn.com/b/ericlippert/archive/2010/04/22/every-tree-there-is.aspx
