class Solution {
public:
    bool isVowel(char ch){

        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u'
         || ch == 'i' ;
    }

    string sortVowels(string s) {
        
        vector<char> v ;
        vector<int> indices ;
        for(int i=0; i<s.size(); i++){

            if(isVowel(s[i])){
                v.push_back(s[i]);
                indices.push_back(i);
            }
        }

        sort(v.begin(),v.end());
        int ci = 0 ;
        for(int i=0; i<indices.size(); i++){

            s[indices[i]] = v[ci];
            ci++;
        }

        return s ;
    }
};