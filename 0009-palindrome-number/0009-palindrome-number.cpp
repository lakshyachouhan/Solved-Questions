class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        int temp = x;
        while(x>0)
        {   if(sum > INT_MAX/10) return false ; 
            sum = sum*10+x%10;
            x = x/10;
        }
       cout << sum ;
        return (temp==sum);
    }
};