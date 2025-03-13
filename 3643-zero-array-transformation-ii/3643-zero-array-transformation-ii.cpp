class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries,int mid){

        int n = nums.size();
        vector<int> diff(n,0);

        for(int i=0; i<mid; i++){

            int s = queries[i][0];
            int e = queries[i][1];
            int val = queries[i][2];

            if(e+1 < n)
                diff[e+1] -= val ;

            diff[s] += val ;
        }

        for(int i=1; i<n; i++)
            diff[i] += diff[i-1];

        for(int i=0; i<n; i++){

            if(diff[i] >= nums[i]){
                // matlab subtract ke baad 0 bna skte hai 
            }

            else return false ;
        }

        return true ;
    }


    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        // same que GFG pr ek contest mein aya tha pehle 
        // B.S

        int s = 0 ;
        int e = queries.size();

        int ans = -1 ;
        while(s <= e){

            int mid = s+(e-s)/2 ;

            if(isPossible(nums,queries,mid)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};