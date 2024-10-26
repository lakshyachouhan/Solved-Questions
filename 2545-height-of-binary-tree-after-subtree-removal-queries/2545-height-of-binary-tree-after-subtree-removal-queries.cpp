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
    unordered_map<int,int> nodeLevel , nodeHeight , maxHeight1 , maxHeight2 ;
    int height(TreeNode* root,int level){

        if(!root)
            return 0 ;

        nodeLevel[root->val] = level ;

        int lh = height(root->left,level+1);
        int rh = height(root->right,level+1);

        nodeHeight[root->val] = max(lh,rh) + 1 ;
        int curr = nodeHeight[root->val] ;

        if(maxHeight1[level] < curr){
            maxHeight2[level] = maxHeight1[level] ;
            maxHeight1[level] = curr ;
        }

        else if(maxHeight2[level] < curr)   maxHeight2[level] = curr ;

        return curr ;        
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        vector<int>  ans ;
        int total = height(root,0)-1;  // nodes-1

        for(int data:queries){

            int level = nodeLevel[data];
            int height = nodeHeight[data];

            int ansHeight ;
            if(maxHeight1[level] == height)
                ansHeight = maxHeight2[level] + level - 1 ;

            else ansHeight = maxHeight1[level] + level - 1 ;

            ans.push_back(ansHeight);
        }

        return ans ;
    }
};