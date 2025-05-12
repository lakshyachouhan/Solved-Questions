class Solution {
public:
    void solve(vector<int>& freq,vector<int> &ans,int num,int i){

        if(i > 2){
            ans.push_back(num);
            return ;
        }

        for(int j=0; j<=9; j++){
            
            if(freq[j] == 0)
                continue ;

            if(i == 0 && j == 0) 
                continue ;

            if(i == 2 && j%2 != 0)
                continue ;

            freq[j]--;
            num = num*10 + j;
            solve(freq,ans,num,i+1);
            freq[j]++;
            num /= 10 ;
            
        }
    }


    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> ans ;
        vector<int> freq(10,0);

        for(auto ele:digits)
            freq[ele]++;

        int num = 0 ;
        solve(freq,ans,num,0);
        return ans;
    }
};