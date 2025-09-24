#define ll long long 

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator==0)
             return "0";
        
        string ans;
        // Handle sign
        if ((numerator<0)^(denominator< 0)) ans+='-';

        // Convert to long to avoid overflow (INT_MIN)
        ll num = abs((ll)numerator);
        ll den = abs((ll)denominator);

        ll q = num/den;
        ll r = num%den;
        ans += to_string(q);

        if (r==0) 
            return ans;

        ans += '.';
        unordered_map<ll, int> mp;
        string frac;

        for(int i=0; r != 0; i++) {

            if (mp.count(r)) {
                frac.insert(mp[r], "(");
                frac+= ')';
                break;
            }
            
            mp[r]=i;
            r*=10;
            frac+=('0'+r/den);
            r%=den;
        }

        return ans+frac;
    }
};