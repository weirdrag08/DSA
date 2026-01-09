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

    void dfs(TreeNode* root, int depth, int &maxDepth, int &nodeCount){
        if(root == NULL){
            return;
        }
        //A new node found at larger depth, set maxDepth = current depth & reset count = 0, as a deeper point has been found
        if(depth > maxDepth){
            maxDepth = depth;
            nodeCount = 0;
        }
        if(depth == maxDepth){
            nodeCount += 1;
        }
        dfs(root-> left, depth + 1, maxDepth, nodeCount);
        dfs(root-> right, depth + 1, maxDepth, nodeCount);
    }

    int getLCA(TreeNode* root, TreeNode* &res, int depth, int &maxDepth, int &nodeCount){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        if(depth == maxDepth){
            count += 1;
        }
        count += getLCA(root-> left, res, depth + 1, maxDepth, nodeCount);
        count += getLCA(root-> right, res, depth + 1, maxDepth, nodeCount);

        //Check if a valid LCA has been found, i.e. first root with all the nodes at maxDepth in it's subtree.
        if(count == nodeCount && res == NULL){
            res = root;
        }

        return count;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //maxDepth which is available, #nodes at max depth
        int maxDepth = 0, nodeCount = 0;
        dfs(root, 0, maxDepth, nodeCount);
        TreeNode* res = NULL;
        getLCA(root, res, 0, maxDepth, nodeCount);
        return res;
    }
};
