class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int mid){

        int d = 1 ;
        int i = 0;
        int curr = 0 ;
        while(i<weights.size()){

            if(curr+weights[i] > mid){
                d++;
                curr = 0 ;                
            }

            curr += weights[i];
            i++;
        }
        
        return d <= days ;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        
        int s = *max_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);

        int ans = -1 ;
        while(s <= e){

            int mid = s+(e-s)/2 ;
            if(isPossible(weights,days,mid)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};