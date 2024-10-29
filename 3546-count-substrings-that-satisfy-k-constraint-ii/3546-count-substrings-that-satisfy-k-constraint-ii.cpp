class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {

        int n = s.size();
        int one = 0, zero = 0;

        vector<long long> v(n, 0);      // leftmost valid position  jha se start hoke i pr end horhi hai 

        vector<long long> pref(n, 0);  // all valid substring ending at i from 0 
        vector<long long> ans;
        int l = 0, r = 0, mid, temp;

        while(r < n) {

            if(s[r] == '0') zero++;
            if(s[r] == '1') one++;
            
            while(one > k && zero > k) {
                if(s[l] == '1') one--;
                if(s[l] == '0') zero--;
                l++;
            }

            v[r] = l;

            pref[r] = (r - l + 1);
            r++;
        }

        // prefix sum 
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1];
        }

        for(const auto &i: queries) {
            l = i[0], r = i[1], temp = i[1] + 1;
            
            // Binary search to find first position where valid substring starts after query start
            // lower bound of l in v array
            while(l <= r) {
                mid = (l + r) / 2;
                if(i[0] <= v[mid]) {
                    temp = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }

            cout << "temp " << temp << endl ; 
            long long subarraysInThatRange = pref[i[1]];  // All valid substrings up to end
            cout << subarraysInThatRange << "  after  " ;
            if(temp - 1 >= 0) subarraysInThatRange -= pref[temp - 1];  // Remove substrings before range
            // temp se r tak ki hai lekin l se chaiye , toh l to temp bhi count
            cout << subarraysInThatRange << "   " ;

            temp = temp - i[0];
            cout << "remaining in left  " << temp << endl ;
            subarraysInThatRange += (long long)temp * (temp + 1) / 2;

            ans.push_back(subarraysInThatRange);
        }
        return ans;
    }
};