class Solution {
public:
    bool canBeValid(string s, string locked) {

        if (s.size() % 2 != 0) return false;

        int open = 0, close = 0, free = 0;

        for (int i = 0; i < s.size(); i++) {

            if (locked[i] == '0')   free++;
            else if (s[i] == '(')   open++;
            else close++;

            if (close > open + free) return false;
        }

        open = 0, close = 0, free = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            
            if (locked[i] == '0')   free++;
            else if (s[i] == '(')   open++;
            else close++;

            if (open > close + free) return false;
        }

        return true;
    }
};
