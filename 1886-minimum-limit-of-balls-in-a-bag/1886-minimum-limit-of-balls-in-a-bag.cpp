class Solution {
public:
    bool isPossible(int mid ,vector<int>& nums, int maxOperations){

        int count = 0 ;

        for(auto ele:nums){

            int currKoMidBananeKeLiyeOperations = ceil(ele/(double)mid) - 1 ;
            count += currKoMidBananeKeLiyeOperations ;

            if(count > maxOperations)   return false ;
        }

        return true ;
    }


    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int maxi = *max_element(nums.begin(),nums.end());
        int s = 1 , e = maxi ;
        int ans = -1 ;

        while(s <= e){

            int mid = s+(e-s)/2 ;
            if(isPossible(mid,nums,maxOperations)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }

};