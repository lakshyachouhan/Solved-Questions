class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        
        unordered_map<int,int> freq;
        int ans = 0 ;

        vector<pair<int,int>> v ; // {value,label}
        for(int i=0; i<values.size(); i++){

            v.push_back({values[i],labels[i]});
        }

        sort(v.rbegin(),v.rend());
        int count = 0 ;
        for(int i=0; i<v.size(); i++){

            int val = v[i].first , l = v[i].second ;

            if(freq[l] < useLimit){

                ans += val ;
                freq[l]++;
                count++;
            }

            if(count == numWanted)
                break ;
        }

        return ans ;

    }
};