class Solution {
public:
    vector<TreeNode*> nodes;
    
    // Step 1: Inorder traversal
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    
    // Step 2: Build balanced BST
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode* root = nodes[mid];
        
        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};
