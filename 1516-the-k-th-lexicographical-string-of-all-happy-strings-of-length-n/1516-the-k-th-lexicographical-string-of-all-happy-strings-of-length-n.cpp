class Solution {
public:
    void solve(int n,int k,vector<string>& v,string &build){

        if(build.size() >= n){
            v.push_back(build);
            return ; 
        }

        // 3 options hai 
        for(int i=0; i<3; i++){
                
            if(build.empty() || build.back() != i+'a'){
                
                build.push_back(i+'a');
                solve(n,k,v,build);
                build.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        
        vector<string> v ;
        string build ;
        solve(n,k,v,build);

        if(v.size() < k)    return "";
        return v[k-1];
    }
};