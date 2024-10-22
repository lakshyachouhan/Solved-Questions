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

 #define ll long long 
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector<ll> v ;
        queue<TreeNode*> q ;
        q.push(root);
        q.push(NULL);
        ll curr = 0 ;

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            if(front == NULL){
                v.push_back(curr);
                curr = 0 ;
                if(!q.empty())  q.push(NULL);
            }

            else{
                curr += front->val ;
                if(front->left) q.push(front->left);
                if(front->right)    q.push(front->right);
            }
        }

        if(v.size() < k)    return -1 ;
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};