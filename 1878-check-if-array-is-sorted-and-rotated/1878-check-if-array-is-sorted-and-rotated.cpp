class Solution {
public:
    bool check(vector<int>& nums) {
        
        // hr baar rotate & check 

/*        int n = nums.size();
        vector<int> v(nums);
        sort(v.begin(),v.end());

        for(int i=0; i<n; i++){

            rotate(v.begin(),v.begin()+1,v.end());
            if(v == nums)
                return true ;
        }

        return false ;      
*/  

//  pivot find & check both sides 
// t.c 101/109
// nums = [2,4,1,3]   false hai isme , matlab relative position bhi check 


        // int n = nums.size();
        // int maxi = -1 , maxIndex = -1 ;
        // for(int i=0; i<n; i++){

        //     if(nums[i] >= maxi){
        //         maxi = nums[i];
        //         maxIndex = i ;
        //     }
        // }


        // for(int i=0; i<maxIndex-1; i++){

        //     if(nums[i] > nums[i+1])
        //         return false ;
        // }

        // for(int i=maxIndex+1; i<n-1; i++){

        //     if(nums[i] > nums[i+1])
        //         return false ;

        // }

        // return true ;

        int n = nums.size();
        int rotations = 0;
        
        // Count number of positions where next
        //  element is smaller than current
        // In a sorted rotated array, this can happen at most once
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                rotations++;
            }
        }
        
        return rotations <= 1;
    }
};