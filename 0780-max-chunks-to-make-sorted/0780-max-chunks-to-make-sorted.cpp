class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int prefix = 0 ; // jo normally sorted mein hota 
        int sum = 0 ; // jo abhi curr arr ka hai
        int ans = 0 ;

        for(int i=0; i<arr.size(); i++){

            prefix += i ;
            sum += arr[i];

            if(sum == prefix){
                ans++;
            }
        }

        return ans ;
    }
};