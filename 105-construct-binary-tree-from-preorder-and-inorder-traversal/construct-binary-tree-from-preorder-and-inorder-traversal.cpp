class Solution {
public:
    int findposition(vector<int> &inorder, int element, int start, int end){
        for(int i = start; i <= end; i++){
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder,
                    int &preorderindex, int inorderstart, int inorderend, int n){

        if(preorderindex >= n || inorderstart > inorderend){
            return NULL;
        }

        int element = preorder[preorderindex++];
        TreeNode* root = new TreeNode(element);

        int position = findposition(inorder, element, inorderstart, inorderend);

        root->left  = solve(preorder, inorder, preorderindex,
                            inorderstart, position - 1, n);
        root->right = solve(preorder, inorder, preorderindex,
                            position + 1, inorderend, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preorderindex = 0;
        return solve(preorder, inorder, preorderindex, 0, n - 1, n);
    }
};
