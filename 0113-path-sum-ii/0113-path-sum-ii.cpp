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
    void fun(TreeNode*root1,int sum,int targetSum,vector<int>&ans,vector<vector<int>>&res){
        if(root1==nullptr)
          return;
        sum+=root1->val;
        ans.push_back(root1->val);
        if(root1->left==nullptr&&root1->right==nullptr){
            if(sum==targetSum)
             res.push_back(ans);
             ans.pop_back();
             return; 
        }
        fun(root1->left,sum,targetSum,ans,res);
        fun(root1->right,sum,targetSum,ans,res);
        ans.pop_back();
        return; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>ans;
        vector<vector<int>>res;
        fun(root,0,targetSum,ans,res);
        return res;
    }
};