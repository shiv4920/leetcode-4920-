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
    TreeNode*ans=nullptr;
public:
    int fun(TreeNode* Node, TreeNode* p, TreeNode* q){
        if(Node == nullptr)
          return 0;
        int left = fun(Node->left,p,q);
        int right = fun(Node->right,p,q);
        int self = 0;
        if(Node == p||Node == q){
            self=1;
        }
        int total=left+self+right;
        if(total ==2 &&ans == nullptr){
            ans = Node;
        }
        return total;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=nullptr;
        fun(root,p,q);
        return ans;
    }
};