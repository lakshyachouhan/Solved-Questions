class Solution {
public:
    int kthFactor(int n, int k) {
        
        vector<int> fromBack ;

        for(int i=1; i*i<=n; i++){

            if(n%i == 0){
                k--;
                if(k == 0)  return i ;

                int div = n/i ;
                if(n%div == 0 && div != i)
                    fromBack.push_back(div);
            }
        }

        int index = fromBack.size()-k ;

        if(fromBack.size() >= k)    
            return fromBack[index];

        else return -1 ;
    }
};