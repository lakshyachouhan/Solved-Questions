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
class FindElements {
public:
    TreeNode* root ;
    unordered_set<int> st ;

    FindElements(TreeNode* root) {
        this->root = root ;
        buildTree(root,0);
    }

    void buildTree(TreeNode* root,int data){

        if(!root)
            return ;

        st.insert(data);
        root->val = data ;

        buildTree(root->left,2*data + 1);
        buildTree(root->right,2*data +2);
    }
    
    bool find(int target) {
        
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */