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
    void solve(TreeNode* root, int target,int &ans,vector<long long> &sums){

        if(!root)   return ;

        for(auto &s:sums){
            s += root->val ;
            // cout << s << endl ;
            if(s == target) ans++;
        }
        
        sums.push_back(root->val);
        if(root->val == target) ans++ ;

        solve(root->left,target,ans,sums);
        solve(root->right,target,ans,sums);

        sums.pop_back();
        for(auto &s:sums){
            s -= root->val ;
        }

    }

    int pathSum(TreeNode* root, int targetSum) {
        
        int ans = 0 ;
        vector<long long> sums ;
        solve(root,targetSum,ans,sums);
        return ans ;
    }
};