class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
    sort(nums.begin(),nums.end());
    int closest = nums[0]+nums[1]+nums[2] ; // any three
    int n = nums.size();

    for(int i=0; i<n; i++){

        int j = i+1;
        int k = n-1;
        while(j<k){

            int curr = nums[i]+nums[j]+nums[k];

            // check kon jyada closest 
            if(abs(target-curr) < abs(target-closest))
              closest = curr;

            if(curr < target)
              j++;
            else k-- ;
        }
    }
        return closest ;
    }
};