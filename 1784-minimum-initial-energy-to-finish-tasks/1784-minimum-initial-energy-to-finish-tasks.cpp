class Solution {
public:
    static bool comp(vector<int>& a,vector<int> &b){

        return (a[1] - a[0]) > (b[1]-b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
        // difference ke basis pr sorting 
        /* Sort the array in the descending order of (minimum - actual).
                (minimum - actual) is the amount of energy that remains after 
                finishing a task. So we should try to accumulate as much energy
                as possible in the beginning to complete the tasks coming up
                ahead. Hence, sort the array in descending order based on the 
                amount of energy that will be remaining.*/

        sort(tasks.begin(),tasks.end(),comp);
        int ans = 0 ;
        int having = 0 ;

        for(auto &i:tasks){

            if(having >= i[1])
                having -= i[0];

            else{
                int req = i[1] - having ;
                having += req - i[0];
                ans += req ;
            }
        }

        return ans ;
    }
};