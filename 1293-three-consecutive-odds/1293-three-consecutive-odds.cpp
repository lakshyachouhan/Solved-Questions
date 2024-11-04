class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        for(int i=0; i<arr.size(); ){

            int count = 0;
            int j = i ;
            while(j<arr.size() && (arr[j]&1)){
                // cout << arr[j] << " " ;
                count++;
                if(count == 3)
                  return true ;

                j++;  
            }

            i = j+1;
        }

        return false ;
    }
};