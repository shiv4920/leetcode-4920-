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
    vector<vector<int>> levelOrder(TreeNode* root) {
     if(root==nullptr)
      return {};   
     queue<TreeNode*>ans;
     vector<vector<int>>res;
     ans.push(root);
     while(!ans.empty()){
        int n=ans.size();
        vector<int>tmp;
        while(n--){
            TreeNode*t=ans.front();
            ans.pop();
            tmp.push_back(t->val);
            if(t->left!=nullptr)
              ans.push(t->left);
            if(t->right!=nullptr)
              ans.push(t->right);  
        }
        res.push_back(tmp);
     }  
     return res; 
    }
};