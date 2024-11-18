class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> curr(code);
        curr.insert(curr.end(),code.begin(),code.end());

        if(k > 0){

            for(int i=0; i<n; i++){
                
                code[i] = 0 ;
                for(int j=i+1; j<=i+k; j++) code[i] += curr[j];
            }
        }

        else if(k < 0){
            
            k *= -1 ;
            for(int i=0; i<n; i++){
                
                code[i] = 0 ;
                for(int j=i+n-1; j>i+n-1-k; j--) code[i] += curr[j];
            }
        }

        else fill(code.begin(),code.end(),0);

        return code ;
    }
};