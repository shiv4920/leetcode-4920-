class Solution {
public:
    int ans = 0;

    int fun(TreeNode* node, int &count) {
        if (node == nullptr)
            return 0;

        int leftCount = 0;
        int rightCount = 0;

        int leftSum = fun(node->left, leftCount);
        int rightSum = fun(node->right, rightCount);

        count = leftCount + rightCount + 1;

        int sum = leftSum + rightSum + node->val;

        if (sum / count == node->val)
            ans++;

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        fun(root, count);
        return ans;
    }
};