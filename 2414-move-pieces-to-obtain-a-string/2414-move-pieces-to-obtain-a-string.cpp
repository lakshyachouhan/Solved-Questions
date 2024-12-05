class Solution {
public:
    bool canChange(string start, string target) {
       
        string s, t;
        for (char c : start) if (c != '_') s += c;
        for (char c : target) if (c != '_') t += c;

        if (s != t) return false;

        int n = start.size();
        int j = 0;

        for (int i = 0; i < n; ++i) {
            if (start[i] == '_') continue;
            while (target[j] == '_') ++j;


            if (start[i] == 'L' && i < j) return false; 

            if (start[i] == 'R' && i > j) return false; 
            ++j;
        }

        // start mein right pehle aana chaiye target se 
        // & left baad mein aana chaiye target se 

        return true;
    }
};
