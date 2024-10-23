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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*> q ;
        vector<int> sum ;
        q.push(root);

        while(!q.empty()){

            int s = q.size();
            int curr = 0 ;

            for(int i=0; i<s; ++i){

                 auto front = q.front();
                 q.pop();

                 curr += front->val ;
                 if(front->left) q.push(front->left);
                 if(front->right)   q.push(front->right);

            }

           sum.push_back(curr);
        }

        q.push(root);
        int level = 1 ;
        root->val = 0 ;


        // Parent node pr uske child ke answer update 
        // total mein se uske child ki value - 
        // & update 
        while(!q.empty()){

            int s = q.size();

            for(int i=0; i<s; ++i){

                 auto front = q.front();
                 q.pop();
                 int curr = sum[level] ;

                 if(front->left){
                    q.push(front->left);
                    curr-= front->left->val ;
                 }

                 if(front->right){
                    q.push(front->right);
                    curr-= front->right->val ;
                 }

                 if(front->left)    front->left->val = curr;
                 if(front->right)   front->right->val = curr ;
            }

        level++;

        if(level == sum.size()) break ;
        }

        return root ;
    }
};