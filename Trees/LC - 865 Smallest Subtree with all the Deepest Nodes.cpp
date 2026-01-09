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

    void dfs(TreeNode *root, int depth, int &maxDepth){
        if(root == NULL){
            return;
        }
        dfs(root-> left, depth + 1, maxDepth);
        dfs(root-> right, depth + 1, maxDepth);
        maxDepth = max(maxDepth, depth);
    }

    int countNodesAtMaxDepth(TreeNode* root, int depth, int &maxDepth){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        if(depth == maxDepth){
            count += 1;
        }
        count += countNodesAtMaxDepth(root-> left, depth + 1, maxDepth);
        count += countNodesAtMaxDepth(root-> right, depth + 1, maxDepth);
        return count;
    }

    int getValidRoot(TreeNode *root, TreeNode* &validRoot, int depth, int &maxDepth, int &count){
        if(root == NULL){
            return 0;
        }
        int nodeCount = 0;
        if(depth == maxDepth){
            nodeCount += 1;
        }
        nodeCount += getValidRoot(root-> left, validRoot, depth + 1, maxDepth, count);
        nodeCount += getValidRoot(root-> right, validRoot, depth + 1, maxDepth, count);
        if(count == nodeCount && validRoot == NULL){
            validRoot = root;
        }
        return nodeCount;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = 0, count = 0;
        dfs(root, 0, maxDepth);
        count = countNodesAtMaxDepth(root, 0, maxDepth);
        TreeNode* validRoot = NULL;
        cout << maxDepth << " " << count << '\n';
        getValidRoot(root, validRoot, 0, maxDepth, count);
        return validRoot;
    }
};
