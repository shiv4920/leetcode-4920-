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
    bool fun(TreeNode*root1){
        if(root1==nullptr)
          return true;
        bool nullfound=false;
        queue<TreeNode*>q;
        q.push(root1);
        while(!q.empty()){
            TreeNode*t=q.front();
            q.pop();
            if(t==nullptr){
              nullfound=true;
            }
            else{
              if(nullfound){
               return false;
              }
              q.push(t->left);
              q.push(t->right);
            }
        }  
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
       return fun(root); 
    }
};