class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        for(auto &d:dominoes)
            sort(d.begin(),d.end());

        sort(dominoes.begin(),dominoes.end());

        int ans = 0 ;
        for(int i=0; i<dominoes.size();){

            int j=i+1 ;
            int equal = 1 ;
            while(j<dominoes.size() && dominoes[i] == dominoes[j])
                j++,equal++;

            if(equal > 1)
                ans += (equal * (equal-1))/2 ;

            i = j ;
        }

        return ans ;
    }
};