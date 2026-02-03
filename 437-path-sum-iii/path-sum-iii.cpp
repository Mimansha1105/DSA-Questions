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
void solve(TreeNode* root, int targetSum, long long sum,
           unordered_map<long long,int> &mp, int &count) {
    if(!root) return;

    sum += root->val;

    if(mp.find(sum - targetSum) != mp.end())
        count += mp[sum - targetSum];

    mp[sum]++;

    solve(root->left, targetSum, sum, mp, count);
    solve(root->right, targetSum, sum, mp, count);

    mp[sum]--;
}

    int pathSum(TreeNode* root, int targetSum) {
   unordered_map<long long,int> mp;
    mp[0] = 1;
    int count = 0;
    solve(root, targetSum, 0, mp, count);
    return count;
    }
};