class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
        unordered_map<string,int> freq ;

        int size = s.size()/k ;
        for(int i=0; i<s.size(); i+=size){

            string curr = s.substr(i,size);
            freq[curr]++;
        }

        for(int i=0; i<t.size(); i+=size){

            string curr = t.substr(i,size);
            
            if(freq[curr])
                freq[curr]--;

            else return false ;
        }

        return true ;
    }
};