// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
        
//         sort(meetings.begin(),meetings.end());

//         int ans = meetings[0][0] - 1 ; // starting gap 
//         int maxEnd = meetings[0][1];

//         for(int i=1; i<meetings.size(); i++){

//             if(maxEnd < meetings[i][0])
//                 ans += meetings[i][0] - maxEnd - 1 ;

//             maxEnd = max(maxEnd,meetings[i][1]);
//         }

//         // ans += days - maxEnd;  // last gap  
//         //    ans += days - meetings.back()[1]; -> wrong 

//         return ans ;
//     }
// };

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        // agr diff array se ho rha hai 
        // toh map se optimise ho hi jayega

        map<int,int> diff;

        for(auto &i:meetings){

            int s = i[0] , e = i[1];
            diff[s]++;
            diff[e+1]--;
        } 

        int ans = 0 ;
        int sum = 0 ;
        int prevDay = 1 ;

        for(auto [day,count]:diff){

            if(sum == 0)
                ans += day - prevDay ;

            sum += count ;
            prevDay = day ;
        }

        // last gap // DRY RUN 
        if (prevDay <= days) {
            ans += days - prevDay + 1;  
        }
            
        return ans ;
    }
};