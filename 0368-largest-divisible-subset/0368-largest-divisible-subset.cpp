class Solution {
public:
    void solve(vector<int>& nums,vector<int>& path,
                    vector<int>& ans,int index){
        
        if(index >= nums.size()){

            if(ans.size() < path.size()){
               ans = path ;
               }

            return ;
        }

        // include 
        if(path.empty() || nums[index]%path.back() == 0){

           path.push_back(nums[index]);
           solve(nums,path,ans,index+1);
           path.pop_back();
        }
        
         // exclude
        solve(nums,path,ans,index+1);      
    }



    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        // vector<int> ans ;
        // vector<int> path ;

        // sort(nums.begin(),nums.end());
        // // jisse ki last wale se hi check krna padega in path 

        // solve(nums,path,ans,0);

        /*
        Recursion mein dp nhi kr skte , usme array as a state hai 
        jo problem hai 
        Isliye bottom up se socho 
        Pehle maximum length find kari , phir usme hi dekha ki 
        jisee length update ho rhi hai , uska index bhi store karlo 
        for building the path array 

        Same isse LIS bhi print hojayega 
        */

        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1) ; // for storing length , ending at nums[i]
        vector<int> prevIdx(n,-1);

        // path build krne ke liye 
        int maxLen = 0 ;
        int lastIdxWithMaxLen = -1 ;

        for(int i=0; i<n; i++){

            // shuru se sab se length of path check 
            for(int j=0; j<i; j++){
                
                if(nums[i]%nums[j] == 0){
                    // dp[j] + 1 , nums[j] ke aage ye add 

                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j] + 1 ;
                        prevIdx[i] = j ;
                    }

                }
            }

            if(dp[i] > maxLen){
                maxLen = dp[i];
                lastIdxWithMaxLen = i ;
            }
        }

        vector<int> ans(maxLen) ;
        int i = maxLen-1; 
        while(lastIdxWithMaxLen != -1){

            ans[i] = nums[lastIdxWithMaxLen];
            lastIdxWithMaxLen = prevIdx[lastIdxWithMaxLen];
            i--;
        }

        return ans ;        
    }
};