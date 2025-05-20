class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        // diff array technique 
        int n = nums.size();
        vector<int> diff(n,0);

        for(auto &q:queries){
            
            int l = q[0] , r = q[1];
            diff[l]++;

            if(r+1 < n)
                diff[r+1]-- ;
        }

        for(int i=1; i<n; i++){
                diff[i] += diff[i-1];
        }

        for(int i=0; i<n; i++){

            // if(diff[i] >= nums[i])
                // toh shi hai 

            if(diff[i] < nums[i])
                return false ;
        }

        return true ;
    }
};