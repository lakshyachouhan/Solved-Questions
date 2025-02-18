class Solution {
public:
    string ans = "999999999";
    void solve(string &pattern,vector<bool> &used,string& build,int i){

        // cout << build << " ->  " << " " ;
        if(i == pattern.size()){
            
            if(ans > build)
                ans = build ;

            return ;
        }

        int prev = build.back() - '0';
        if(pattern[i] == 'D'){
            for(int num=prev-1; num>=1; num--){

                if(!used[num]){
                    build.push_back(num + '0');
                    used[num] = 1 ;
                    solve(pattern,used,build,i+1);
                    build.pop_back();
                    used[num] = 0 ;
                }
            }
        }

        else{
            for(int num=prev+1; num<=9; num++){

                if(!used[num]){
                    build.push_back(num + '0');
                    used[num] = 1 ;
                    solve(pattern,used,build,i+1);
                    build.pop_back();
                    used[num] = 0 ;
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        
        string build ;
        vector<bool> used(10,0);
        used[0] = 1 ;

        for(int num=1; num<=9; num++){

            if(!used[num]){
                    build.push_back(num + '0');
                    used[num] = 1 ;
                    solve(pattern,used,build,0);
                    build.pop_back();
                    used[num] = 0 ;
            }
        }
        
        return ans ;
    }
};