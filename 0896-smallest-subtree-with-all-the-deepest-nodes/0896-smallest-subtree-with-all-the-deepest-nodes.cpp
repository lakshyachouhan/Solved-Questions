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
    TreeNode* LCA(TreeNode* root,TreeNode* &p,TreeNode* &q){

        if(!root)
            return NULL ;

        if(root == p || root == q)
            return root ;

        TreeNode* leftAns = LCA(root->left,p,q);
        TreeNode* rightAns = LCA(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL)
            return NULL ;

        else  if(leftAns != NULL && rightAns == NULL)
            return leftAns ;

        else  if(leftAns == NULL && rightAns != NULL)
            return rightAns ;

        return root ;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        // Level Wise Bfs + LCA
        vector<TreeNode*> lastLevel;
        queue<TreeNode*> q ;
        q.push(root);

        while(!q.empty()){

            int s = q.size();
            lastLevel.clear();

            for(int i=0; i<s; i++){

                auto front = q.front();
                q.pop();
                lastLevel.push_back(front);

                if(front->left) q.push(front->left);
                if(front->right)  q.push(front->right);
            }

        }

        if(lastLevel.size() == 1)
            return lastLevel[0];

        return LCA(root,lastLevel[0],lastLevel.back());

    }
};