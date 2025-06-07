class Solution {
public:
    string clearStars(string s) {
        
        map<char,vector<int>> mp ;
        // uss character ki positions ke indexes 
        // remove ke liye last wala hi remove 
        // smallest -> mp.begin()

        for(int i=0; i<s.size(); i++){

            char ch = s[i];

            if(ch == '*'){

                // remove the leftmost smallest 
                auto it = mp.begin();
                auto &indexes = it->second ;

                // cout << ch << " " << i << " " << indexes.size()<< endl ;
                int remove = indexes.back();
                s[remove] = '#';
                indexes.pop_back();

                if(indexes.size() == 0)
                    mp.erase(it);
            }

            else
                 mp[ch].push_back(i);
        }

        string ans ;
        for(auto ch:s){

            if(ch != '*' && ch != '#')
                ans.push_back(ch);
        }

        return ans ;
    }
};