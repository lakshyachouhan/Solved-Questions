#define ll long long 

class Solution {
public:
    ll MOD = 1e9+7;

    int countBalancedPermutations(string& s) {
        int n = s.size(), sum = 0;
        vector<int> cnt(10);
        for (char c : s) {
            int d = c - '0';
            cnt[d]++;
            sum += d;
        }
        if (sum & 1) return 0;

        int targ = sum >> 1, maxo = (n+1)>>1;
        vector<vector<ll>> comb(maxo+1, vector<ll>(maxo+1)), dp(targ+1, vector<ll>(maxo+1));
        for (int i = 0; i <= maxo; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++)
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }

        dp[0][0] = 1;
        int ps = 0, ts = 0;
        for (int d = 0; d < 10; d++) {
            ps += cnt[d];
            ts += cnt[d]*d;
            for (int o = min(ps,maxo); o >= max(0, ps-(n-maxo)); o--) {
                int e = ps - o;
                for (int csum = min(ts,targ); csum >= max(0, ts-targ); csum--) {
                    ll val = 0;
                    for (int j = max(0, cnt[d]-e); j <= min(cnt[d], o) && j*d <= csum; j++) {
                        ll ways = comb[o][j] * comb[e][cnt[d]-j] % MOD;
                        val = (val + ways * dp[csum-j*d][o-j]) % MOD;
                    }
                    dp[csum][o] = val;
                }
            }
        }
        return dp[targ][maxo];
    }
};
