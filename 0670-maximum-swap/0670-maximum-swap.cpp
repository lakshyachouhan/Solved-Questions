class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int n = s.size();

        if(n == 1)  return num ;

        vector<int> rightMax(n) ;  // indexes store right se maximum ele. ke 
        rightMax[n-1] = n-1;

        for(int i=n-2; i>=0; i--){

            if(s[rightMax[i+1]]-'0' >= s[i+1]-'0')
                rightMax[i] = rightMax[i+1];

            else rightMax[i] = i+1 ; 
        }

        for(int i=0; i<n; i++){

            if(s[rightMax[i]] - '0' > s[i]-'0'){
                swap(s[rightMax[i]],s[i]);
                break ;
            }
        }

        // cout <<s<<endl;

        return stoi(s) ;
    }
};