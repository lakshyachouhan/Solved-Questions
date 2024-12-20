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
    TreeNode* buildTree(vector<int> &v,int i){

        if(i >= v.size())
            return NULL ;

        int value = v[i];
        TreeNode* root = new TreeNode(value);
        root->left = buildTree(v,2*i+1);
        root->right = buildTree(v,2*i+2);

        return root ; 
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q ;
        q.push(root);
        vector<int> v ;
        bool odd = 0 ;

        while(!q.empty()){

            int n = q.size();
            vector<int> curr ;

            for(int i=0; i<n; i++){

                TreeNode* front = q.front();
                q.pop();
                
                curr.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            if(odd) reverse(curr.begin(),curr.end());
            v.insert(v.end(),curr.begin(),curr.end());

            odd = !odd ;
        }

        // for(auto ele:v) cout << ele << "  " ;

        return buildTree(v,0);
    }
};