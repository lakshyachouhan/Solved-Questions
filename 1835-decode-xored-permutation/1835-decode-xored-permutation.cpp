class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        // enc[1]^enc[3]^... gives xor of perm[1, n - 1],
        //  xor it with xor(1,n) to get perm[0]
        // alternate elements 1 se le toh perm[0] mil jayega 
        // & 0 se le toh perm[n-1]  mil jayega

        int total_xor = 0 ;
        int n = encoded.size() + 1 ;

        for(int i=1; i<=n; i++)
            total_xor ^= i ;

        int X = 0 ;
        for(int i=1; i<encoded.size(); i+=2){
            X ^= encoded[i];
        } 

        vector<int> perm ;
        int first = X ^ total_xor ;
        perm.push_back(first);

        for(int i=0; i<encoded.size(); i++){

            int next = perm.back() ^ encoded[i];
            perm.push_back(next);
        }

        return perm ;
    }
};