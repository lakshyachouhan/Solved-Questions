class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(goal.size() != s.size())
            return 0 ;

        s = s + s;
        return s.find(goal) != string::npos ;
    }
};