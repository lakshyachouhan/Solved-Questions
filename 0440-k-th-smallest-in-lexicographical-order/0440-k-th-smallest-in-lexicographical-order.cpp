#define ll long long
class Solution {
    int countSteps(int n, int prefix) {
        if (prefix > n) {
            return 0;
        } 
        else if (prefix == n) {
            return 1;
        }
        
        ll minPrefix = prefix, maxPrefix = prefix;
        int count = 1;  // Initialize count to include the prefix itself
        while (true) {
            minPrefix = (long)10 * minPrefix;
            maxPrefix = (long)10 * maxPrefix + 9;
            if (n < minPrefix) break;
            if (minPrefix <= n && n <= maxPrefix) {
                count += (n - minPrefix + 1);
                break;
            } else {
                count += (maxPrefix - minPrefix + 1);
            }
        }
        
        return count;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int step = countSteps(n, curr);
            if (step <= k) {
                // matlab iske beech mein ya andar nhi hai
                curr++;
                k -= step;
            } 
            
            else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
