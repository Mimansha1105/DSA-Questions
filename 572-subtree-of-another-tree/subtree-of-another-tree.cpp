
class Solution {
public:
bool sametree(TreeNode* a, TreeNode* b){
    if(a==NULL && b==NULL)
    return true;
    if(a==NULL || b==NULL)
    return false;
   if(a->val != b->val)
    return false;
    return sametree(a->left, b->left) && sametree(a->right, b->right);

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
        return false;
        if(subRoot==NULL)
        return false;
       if(sametree(root, subRoot))
       return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};