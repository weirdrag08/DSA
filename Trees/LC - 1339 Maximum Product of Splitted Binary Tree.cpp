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
    const int MOD = 1e9 + 7;
    int calculateSum(TreeNode * root){
        int sum = root-> val;
        if(root-> left != NULL){
            sum += calculateSum(root-> left);
        }
        if(root-> right != NULL){
            sum += calculateSum(root-> right);
        }
        return sum;
    }

    int dfs(TreeNode * root, int totalSum, long long &res){
        int leftSum = 0, rightSum = 0;
        if(root-> left != NULL){
            leftSum = dfs(root-> left, totalSum, res);
        }
        if(root-> right != NULL){
            rightSum = dfs(root-> right, totalSum, res);
        }

        //Cut the Left Edge
        long long leftCutSum = 1LL * leftSum * (totalSum - leftSum);
        
        //Cut the Right Edge
        long long rightCutSum = 1LL * rightSum * (totalSum - rightSum);

        res = max(res, max(leftCutSum, rightCutSum));
        return root-> val + leftSum + rightSum;
    }

    int maxProduct(TreeNode* root) {
        int sum = calculateSum(root);

        long long res = 0;
        dfs(root, sum, res);
        return (int) (res % MOD);
    }
};
