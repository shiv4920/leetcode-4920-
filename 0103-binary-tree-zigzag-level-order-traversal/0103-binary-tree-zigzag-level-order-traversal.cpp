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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
          return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        bool lefttoright=1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>tmp(n);
            int i=0;
            int j=n-1;
            while(n--){
                TreeNode*t=q.front();
                q.pop();
                if(lefttoright==1){
                    tmp[i]=t->val;
                    i++;
                }else{
                    tmp[j]=t->val;
                    j--;
                }
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(tmp);
            lefttoright=!lefttoright;
        }
     return res;
    }
};