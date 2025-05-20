class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int ans = -1 ;
        for(int i=0; i<nums.size(); i++){

            int sum = 0 ;
            int ele = nums[i];
            while(ele){
                sum += ele%10 ;
                ele /= 10 ;
            }

            if(sum == i)
                return i ;
        }

        return -1 ;
    }
};