class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        // Brute -> find just greater element in t for each p 
        // opt -> sort t and use b.s for finding in t 
        // m opt -> two pointer , greedy 

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int ti = 0 ;
        int ans = 0 ;
        for(int i=0; i<players.size(); i++){

            while(ti < trainers.size() && trainers[ti] < players[i])
                ti++;

            if(ti < trainers.size() && players[i] <= trainers[ti]){
                ans++;
                ti++;
            }
            
            else break ;
        }

        return ans ;
    }
};