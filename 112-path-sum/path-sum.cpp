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
bool PathSum(TreeNode* root, int targetSum, int sum){
  bool isthere=false;
    
      if(root==NULL){
        return false;
      } 
      sum+=root->val;
        if(root->left==NULL && root->right==NULL && sum==targetSum){
          return true;
          }
       isthere = PathSum(root->left, targetSum, sum) ||
             PathSum(root->right, targetSum, sum);
 return isthere;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
   return PathSum(root,targetSum,0);

    }
};