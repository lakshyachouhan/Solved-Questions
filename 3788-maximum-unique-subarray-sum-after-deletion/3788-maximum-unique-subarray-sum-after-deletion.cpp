class Solution {
public:
    int maxSum(vector<int>& nums) {

        // Two cases :
        // all are -ve -> return max. element
        // else return sum of all +ve unique elements 
        
        unordered_map<int,bool> vis ; 
        int sum = 0 ;
        int maxi = -1e9 ;

        for(auto ele:nums){

            if(ele > 0 && vis.count(ele) == 0){
                vis[ele] = 1 ;
                sum += ele ;
            }

            maxi = max(maxi,ele);
        }

        return maxi < 0 ? maxi : sum ;
    }
};