class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        // DRY RUN Karo 
        // first aur last element toh hr baar sum mein ayenge
        // and - , toh cancel bhi hojaege 
        // phir jab line draw kr rhe hai 
        // toh adjacent wale hi endpoints hai , unka sum add

        int n = weights.size();
        vector<int> v(n - 1);

        for (int i = 0; i < n - 1; i++){
            // saare endpoints ka sum 
            v[i] = weights[i] + weights[i + 1];
        }
            

        sort(v.begin(), v.end());
        // maximum last  + 
        // minimum starting -  

        long long ans = 0;
        
        for (int i = 0; i < k - 1; i++){
            ans += v[n-i-2] - v[i];
        }
            
        return ans;
    }
};
