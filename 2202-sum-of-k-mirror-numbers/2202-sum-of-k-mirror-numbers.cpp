class Solution {
public:
    
    bool isPalindrome(string &str) {
        
        int s = 0 , e = str.size()-1 ;

        while(s <= e){

            if(str[s] != str[e])
                return false ;

            s++,e--;
        }

        return true ;
    }

    string convertToBaseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string ans = "";
        while(num > 0) {
            ans += to_string(num%k);
            num /= k;
        }

        return ans;
    }

    long long kMirror(int k, int n) {

        long long sum = 0;
        int L = 1;  // length of palindrome no.

        while(n > 0) {
            int half_length = (L+1)/2;
            
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {

                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if(L % 2 == 0) 
                    pal = first_half + second_half;
                
                // eg. 121 odd length , first = 12 second = 21.substr(1)
                else  pal = first_half + second_half.substr(1);
            

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPalindrome(baseK)) {

                    sum += pal_num; 
                    n--;
                    if(n == 0)
                        break ;

                }
            }

            L++;
        }

        return sum;
    }
};


