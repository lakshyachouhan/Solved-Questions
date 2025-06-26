// LC 3337
#define ll long long
const ll MOD = 1e9 + 7;

class Solution {
public:
    vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {

        vector<vector<ll>> ans(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < 26; k++) {

                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; j++) {
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;

                }
            }
        }

        return ans;
    }

    vector<vector<ll>> matrixExpo(vector<vector<ll>> base, int power) {
                                                                                    
        vector<vector<ll>> ans(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) 
                ans[i][i] = 1; // identity

        while (power > 0) {
            if (power & 1) ans = multiply(ans, base);
            base = multiply(base, base);
            power >>= 1;
        }

        return ans;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

        vector<ll> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<vector<ll>> trans(26, vector<ll>(26, 0));
        // ek step mein i kis kis mein convert ho skta hai
        // i wale se kon kon se bn rhe hai 
        // unki ++
        for (int i = 0; i < 26; i++) {

            for (int j = 1; j <= nums[i]; j++) 
                trans[i][(i + j) % 26] = (trans[i][(i + j) % 26] + 1) % MOD;
            
        }

        // t tranformations ke baad , kon kise finally bn rha hai
        // a-> b , b->c in one , but in two a->c directly 
        vector<vector<ll>> mat = matrixExpo(trans, t);

        vector<ll> newFreq(26, 0);
        for (int i = 0; i < 26; i++) {

            for (int j = 0; j < 26; j++) 
                newFreq[j] = (newFreq[j] + freq[i] * mat[i][j]) % MOD;
            
        }

        ll ans = 0;
        for (int i = 0; i < 26; i++) 
            ans = (ans + newFreq[i]) % MOD;
        

        return ans;
    }
};
