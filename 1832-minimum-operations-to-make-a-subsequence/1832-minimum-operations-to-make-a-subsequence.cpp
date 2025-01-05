class Solution {
public:
    int LIS(vector<int> &v){

        if(v.empty())
            return 0 ;

        vector<int> ans ;
        ans.push_back(v[0]);

        for(int i=1; i<v.size(); i++){

            if(v[i] > ans.back())
                ans.push_back(v[i]);

            else{
                auto it = lower_bound(ans.begin(),ans.end(),v[i]) - ans.begin();
                ans[it] = v[i];
            }
        }

        // cout << ans.size() << endl ;
        // for(auto ele:ans)
        //     cout << ele << "  " ;

        return ans.size();
    }

    int minOperations(vector<int>& target, vector<int>& arr) {
        
        // LCS -> lekin usmme TLE O(N * M)

        // target mein jo elements hai vo distinct hai 
        // matlab ek element ek se hi map hoga 
        // aur jha map hua uske aage ke kitne aa skte hai
        // aage ke matlab bade index wale 

        unordered_map<int,int> mp ;

        for(int i=0; i<target.size(); i++)
            mp[target[i]] = i ;

        vector<int> v ;
        for(auto ele:arr){

            if(mp.count(ele))
                v.push_back(mp[ele]);

            // target wala index store us element ka 
        }

        int maxLen = LIS(v);
        return target.size() - maxLen ;
    }
};