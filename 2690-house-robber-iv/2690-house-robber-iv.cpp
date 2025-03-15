class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){

        // kya k adjacent houses ko rob kr skte hai 
        // jinki values mid se kam ya equal hai

        int count = 0 ;
        int i = 0 ;
        while(i < nums.size()){

            if(nums[i] <= mid){
                i += 2 ;
                count++;
            }

            else i++;
        } 

        if(count >= k)
            return 1;

        i = 1 ;
        count = 0;
         while(i < nums.size()){

            if(nums[i] <= mid){
                i += 2 ;
                count++;
            }

            else i++;
        }

        return count >= k ;

    }


    int minCapability(vector<int>& nums, int k) {
        
        int s = *min_element(nums.begin(),nums.end());
        int e = *max_element(nums.begin(),nums.end());

        int ans = e ;
        while(s <= e){

            int mid = s + (e-s)/2;
            if(isPossible(nums,k,mid)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};