class Solution {
public:
    bool isPossible(vector<int>& nums, int p,int mid){

        int pairs = 0 ;
        int i = 1 ; 

        while(i < nums.size()){

            if(nums[i]-nums[i-1] <= mid){
                i += 2 ;
                pairs++;
            }

            else i++;
        }

        return pairs >= p ;
    }


    int minimizeMax(vector<int>& nums, int p) {
        
        // maxi of mini 
        // mini of maxi 
        // Binary Search On Answer 
        // pairs count krenge , if ans = 2 ,
        //  matlab <=2 diff ke p pairs possible hai kya 
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int s = 0 ;
        int e = nums[n-1] - nums[0] ;

        int ans = e ;
        while(s <= e){

            int mid = s + (e-s)/2 ;

            if(isPossible(nums,p,mid)){
                ans = mid;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};