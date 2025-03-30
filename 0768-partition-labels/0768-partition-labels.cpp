class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // Got hint from CodeChef C que of some contest
        // same pattern tha  
        unordered_map<char,int> startIndex , lastIndex ;

        for(int i=0; i<s.size(); i++){
            
            char ch = s[i] ;
            if(startIndex.find(ch) == startIndex.end())
                startIndex[ch] = i ;

            lastIndex[ch] = i ;
        }

        vector<pair<int,int>> v ;
        for(auto &[ch,idx]:startIndex){

            int end = lastIndex[ch] ;
            v.push_back({idx,end});
        }

        sort(v.begin(),v.end());
        
        vector<pair<int,int>> merged ;
        merged.push_back(v[0]);

        for(int i=1; i<v.size(); i++){

            if(merged.back().second > v[i].first){
                merged.back().second = max(merged.back().second,v[i].second);
            }

            else{
                merged.push_back(v[i]);
            }
        }

        vector<int> ans ;
        for(auto &p:merged){
            ans.push_back(p.second - p.first  + 1) ;
        }

        return ans ;
    }
};