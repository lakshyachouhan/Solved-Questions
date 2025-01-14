class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();
        vector<bool> marking(n,0);
        int count = 0 ;
        vector<int> ans(n);

        for(int i=0; i<n; i++){

            // agr kisi bhi array ne pehle mark kr diya tha toh 
            // increment it 
            // otherwise mark it 

            if(marking[A[i]] == 1)  count++;
            else marking[A[i]] = 1 ;

            if(marking[B[i]] == 1)  count++;
            else marking[B[i]] = 1 ;

            ans[i] = count ;
        }

        return ans ;        
    }
};