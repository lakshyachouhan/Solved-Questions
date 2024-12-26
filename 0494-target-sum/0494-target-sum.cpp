class Solution {
public:
     map<pair<int,int>,int > mp ;
     int solve(vector<int>& nums, int target,int i,int sum){

        if(i >= nums.size()){
            if(target == sum)   return 1 ;
            else return 0 ;
        }

        if(mp.find({i,sum}) != mp.end())
            return mp[{i,sum}];

        int add = solve(nums,target,i+1,sum+nums[i]);
        int sub = solve(nums,target,i+1,sum-nums[i]);

        return mp[{i,sum}] = add + sub ;
     }

     int solveTab(vector<int>& nums, int target){
        map<pair<int,int>,int > mp ;
        mp[{nums.size(),target}] = 1 ;

        for(int i=nums.size()-1; i>=0; i--){
            for(int sum=-1000; sum<=1000; sum++){

        int add = mp[{i+1,sum+nums[i]}];
        int sub = mp[{i+1,sum-nums[i]}];

        mp[{i,sum}] = add + sub ;

            }
        }

        return mp[{0,0}];
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        // int ans = solve(nums,target,0,0);

        int ans = solveTab(nums,target);
        return ans ;
    }
};