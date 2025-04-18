class Solution {
public:
    string solveIteratively(int n){

        if(n == 1)
            return "1" ;

        string curr = "1" ;

        for(int i=2; i<=n; i++){

            string ans = "";

            char ch = curr[0];
            int count = 1 ;
            for(int j=1; j<curr.size(); j++){

                if(curr[j] == ch)
                    count++;

                else{
                    // previous insert , and new start 
                    ans += to_string(count) + ch ; 
                    count = 1 ;
                    ch = curr[j];
                }
            }

            ans += to_string(count) + ch ; 
            curr = ans ;
        }

        return curr ;
    }


    string countAndSay(int n) {
        
        if(n == 1)
            return "1" ;

        // string curr = countAndSay(n-1);
        // string ans = "";

        // char ch = curr[0];
        // int count = 1 ;
        // for(int j=1; j<curr.size(); j++){

        //     if(curr[j] == ch)
        //         count++;

        //     else{
        //         // previous insert , and new start 
        //         ans += to_string(count) + ch ; 
        //         count = 1 ;
        //         ch = curr[j];
        //     }
        // }

        // ans += to_string(count) + ch ; 

        // return ans ;

        return solveIteratively(n);
    }
};