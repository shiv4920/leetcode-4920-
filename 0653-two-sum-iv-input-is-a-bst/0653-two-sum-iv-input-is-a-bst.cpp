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
     void fun(TreeNode*root1,vector<int>&ans){
        if(root1==nullptr)
          return;
        fun(root1->left,ans);
        ans.push_back(root1->val);
        fun(root1->right,ans);
        return;  
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        fun(root,ans);
        int n=ans.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(ans[i]+ans[j]<k){
                i++;
            }else if(ans[i]+ans[j]>k){
                j--;
            }else{
                return true;
                break;
            }
        }
        return false;
    }
};