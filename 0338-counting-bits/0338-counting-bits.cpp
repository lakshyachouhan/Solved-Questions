class Solution {
public:
    int countOnes(int n){

        int ans = 0 ;
        while(n){
            ans++;
            n = n & (n-1) ;
        }

        return ans ;
    }

    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++){

            ans[i] = countOnes(i);
        }

        return ans ;
    }
};