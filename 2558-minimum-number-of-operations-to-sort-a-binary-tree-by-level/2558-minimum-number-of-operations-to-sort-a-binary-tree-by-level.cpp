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
    int countSwaps(vector<int> &v){

        int ans = 0;
        vector<int> sorted(v);
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> pos ;
        for(int i=0; i<v.size(); i++)
            pos[v[i]] = i ;

        for(int i=0; i<v.size(); i++){

            int currHonaChiayeTha = sorted[i];

            if(currHonaChiayeTha != v[i]){
                ans++;

                int v_pos = pos[currHonaChiayeTha];
                pos[v[i]] = v_pos ;   // nyi pos v[i] ki
                swap(v[v_pos],v[i]);
            }
        }

        return ans ;
    }


    int minimumOperations(TreeNode* root) {
        
        int ans = 0 ;
        queue<TreeNode*> q ;
        q.push(root);

        while(!q.empty()){

            vector<int> v ;
            int n = q.size();

            for(int i=0; i<n; i++){

                auto front = q.front();
                q.pop();

                v.push_back(front->val);

                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }

            ans += countSwaps(v);
        }

        return ans ;
    }
};