class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        // Find the dominant element -> max. occurences 
        // Make the valid split 

        unordered_map<int,int> mp ;
        int maxOcc = 0 , dominantEle = -1 ;

        for(auto &ele:nums){

            mp[ele]++;

            if(mp[ele] > maxOcc){
                maxOcc = mp[ele];
                dominantEle = ele ;
            }
        }

        int count = 0 ;
        int n = nums.size() ;

        for(int i=0; i<n; i++){

            if(nums[i] == dominantEle)
                count++;

            if(count > (i+1)/2 && 
                mp[dominantEle]-count > (n-i-1)/2)
                return i ;
        }

        return -1 ; 
    }
};