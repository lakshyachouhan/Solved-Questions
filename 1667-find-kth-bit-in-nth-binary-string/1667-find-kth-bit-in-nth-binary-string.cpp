class Solution {
public:
    char findKthBit(int n, int k) {
        
        string prev = "0";
        string curr = "0" ;

        for(int i=2; i<=n; i++){

            curr = prev + '1';
            for(int i=0; i<prev.size(); i++){
                prev[i] = prev[i] ==  '0' ? '1' : '0' ; 
            } 

            reverse(prev.begin(),prev.end());
            curr += prev ;
            prev = curr ;
        }

        return curr[k-1];
    }
};