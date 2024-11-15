class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int prefixLen = 1;
        for(int i = 1; i < n; i++) {

            if(arr[i] >= arr[i-1]) 
                    prefixLen++;

            else break;
        }
        
        if(prefixLen == n) return 0;
        
        int suffixLen = 1;
        for(int i = n-2; i >= 0; i--) {

            if(arr[i] <= arr[i+1]) 
                    suffixLen++;
            
            else break;
        }
        
        // prefix ya suffix ko chorkar sab remove 
        int ans = n - max(prefixLen, suffixLen);
        
        int i = 0;
        int j = n - suffixLen;

        while(i < prefixLen && j < n) {

            if(arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            } 
            
            else j++;
        }
        
        return ans;
    }
};
