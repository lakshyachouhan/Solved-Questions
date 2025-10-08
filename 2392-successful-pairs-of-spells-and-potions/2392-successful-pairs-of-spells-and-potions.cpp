class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        // Brute  : Two loops 
        // 2nd : Binary Search : sort potion array and check lb of success/spells[i] , and take the above elements than this 

        // 3rd : Most optimised  : two pointer approach 
        // sort both arrays  
        // iterate from last in potion and start in spells 
        // agr i wala j ke saath pair bana rha hai , toh i se bade elements bhi bana denge 

        vector<int> ans ;
        sort(potions.begin(),potions.end());

        for(int i=0; i<spells.size(); i++){

            double req = (success*1.00)/spells[i] ;
            auto it = lower_bound(potions.begin(),potions.end(),req);

            int count = potions.end() - it ;
            ans.push_back(count);

        }

        return ans ;

    }
};