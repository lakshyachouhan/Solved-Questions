class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int ans = 0 ;

        for(int i=low; i<=high; i++){

            string curr = to_string(i);
            if(curr.size() & 1)
                continue ;

            int begin = 0 , end = 0 ;
            for(int j=0; j<curr.size(); j++){

                if(j >= curr.size()/2)
                    end += curr[j] - '0';

                else begin += curr[j] - '0' ;
            }

            if(begin == end)
                ans++;
        }

        return ans ;
    }
};