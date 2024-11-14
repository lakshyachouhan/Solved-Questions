class Solution {
public:

    bool isPossible(int mid,int n,vector<int> &quantities){

        int count = 0 ;
        for(auto items:quantities){

            // while(items > 0){
            //     items -= mid ;
            //     count++;

            //     if(count > n)   return false ;
            // }

            count += items/mid ;
            count += items%mid != 0 ? 1 : 0;

            if(count > n)   return false ;
        }

        return count <= n ;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int s = 1 , e = *max_element(quantities.begin(),quantities.end());
        int ans = e+1 ;

        while(s <= e){

            int mid = s+(e-s)/2 ;

            if(isPossible(mid,n,quantities)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};