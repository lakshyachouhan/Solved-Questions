class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;
            if (s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        if ((xy + yx)&1) return -1;

        // finally return the number of swaps 
        // we are dividing by 2 because
        // in one swap , we count one from s1 and one from s2
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};