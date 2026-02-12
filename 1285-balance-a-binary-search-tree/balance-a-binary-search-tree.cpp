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
void inordertraversal(TreeNode* root,vector<int> &inorderval){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left,inorderval);
    inorderval.push_back(root->val);
    inordertraversal(root->right,inorderval);
}
TreeNode* bstaagyeoye(int s, int e, vector<int>inorderval){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
      TreeNode* temp = new TreeNode(inorderval[mid]);
    temp->left=bstaagyeoye(s,mid-1,inorderval);
    temp->right=bstaagyeoye(mid+1, e,inorderval);
    return temp;


}
    TreeNode* balanceBST(TreeNode* root) {
    vector<int> inorderval;
    inordertraversal(root,inorderval);
    int n=inorderval.size();
    return bstaagyeoye(0,n-1,inorderval);    
    }
};