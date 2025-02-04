class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        int n = security.size();
        vector<int> increasing(n,1);
        vector<int> decreasing(n,1);

        for(int i=1; i<n; i++){

            if(security[i] >= security[i-1])
                increasing[i] += increasing[i-1];

            else increasing[i] = 1; 
        }

        for(int i=1; i<n; i++){

            if(security[i] <= security[i-1])
                decreasing[i] += decreasing[i-1]  ;

            else decreasing[i] = 1; 
        }

        // for(int i=0; i<n; i++){

        //     cout << i << " -> " << increasing[i] << "  " << decreasing[i] << endl ;
        // }

        // ith ke liye increasing[i+time] >= time+1 ke 
        // & decreasing[i] >= time+1

        vector<int> ans ;
        for(int i=time; i<=n-time-1; i++){

            if(increasing[i+time] >= time+1 && decreasing[i] >= time+1)
                ans.push_back(i);
        }

        return ans ;
    }
};