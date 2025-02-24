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
    TreeNode* solve(int postIndex,int preStart,int preEnd,vector<int>& preorder, vector<int>& postorder){

        if(preStart > preEnd)   return NULL ;
        if(preStart == preEnd)  return new TreeNode(preorder[preStart]);

        TreeNode* root = new TreeNode(preorder[preStart]);

        int nextNode = preorder[preStart+1] ;  // jo ki left Subtree ka root hoga  // NLR
        // iski position find in postOrder ( LRN ) , i.e N ko find 

        int j = postIndex ;
        while(postorder[j] != nextNode) 
                j++;

        int num = j - postIndex + 1 ; // itni nodes left mein hogi root ke 

        // preStart+1 wala left ka root , + uska subtree 
        root->left = solve(postIndex,preStart+1,preStart+num,preorder,postorder);

        // preStart+num+1 right ka root , aur postIndex+num se uska subtree build/find
        root->right = solve(postIndex+num,preStart+num+1,preEnd,preorder,postorder);

        return root ;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        return solve(0,0,n-1,preorder,postorder);
    }
};