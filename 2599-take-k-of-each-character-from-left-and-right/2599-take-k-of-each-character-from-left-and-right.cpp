class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        int n = s.length();
        for (char c : s) {
            count[c - 'a']++;
        }   

        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }

        // count - window -> kitne char window se bahar hai 
        // toh kya usme atleast k sabke hai 
        // agr nhi toh poorane wale include karo 
        vector<int> window(3, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            while (left <= right &&
                   (count[0] - window[0] < k || count[1] - window[1] < k ||
                    count[2] - window[2] < k)) {
                window[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return n - ans;
    }
};
