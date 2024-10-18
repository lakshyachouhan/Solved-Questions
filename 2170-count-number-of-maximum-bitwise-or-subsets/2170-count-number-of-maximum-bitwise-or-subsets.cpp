class Solution {
public:
    void solve(vector<int>&nums,int i,int curr,int &count,int& maxi){

        if(i >= nums.size()){

            if(curr == maxi)
                    count++;
   
            return  ;
        }    

        solve(nums,i+1,curr,count,maxi);

        curr |= nums[i];
        solve(nums,i+1,curr,count,maxi);
    }


    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++)    maxi |= nums[i] ;

        int count = 0 ;
        solve(nums,0,0,count,maxi);
        return count  ;
    }
};