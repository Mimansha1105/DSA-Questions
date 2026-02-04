class Solution {
public:
    void createMapping(vector<int>& inorder,
                       unordered_map<int,int> &nodeToIndex) {
        for(int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int &postIndex, int inorderStart, int inorderEnd,
                    unordered_map<int,int> &nodeToIndex) {

        if(postIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);

        int position = nodeToIndex[element];

        root->right = solve(inorder, postorder, postIndex,
                            position + 1, inorderEnd, nodeToIndex);

        root->left = solve(inorder, postorder, postIndex,
                           inorderStart, position - 1, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> nodeToIndex;
        createMapping(inorder, nodeToIndex);

        int postIndex = postorder.size() - 1;

        return solve(inorder, postorder, postIndex,
                     0, inorder.size() - 1, nodeToIndex);
    }
};
