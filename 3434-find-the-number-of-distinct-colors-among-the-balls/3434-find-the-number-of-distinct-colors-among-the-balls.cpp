class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        vector<int> ans ;
        unordered_map<int,int> ballColor, colorsFreq ;

        for(auto i:queries){

            int ball = i[0];
            int color = i[1];

            if(ballColor.count(ball)){
                int currColor = ballColor[ball] ;
                colorsFreq[currColor]--;
                if(colorsFreq[currColor] == 0)
                    colorsFreq.erase(currColor);
            }

            colorsFreq[color]++;
            ballColor[ball] = color ;
            ans.push_back(colorsFreq.size());
        }

        return ans ;
    }
};