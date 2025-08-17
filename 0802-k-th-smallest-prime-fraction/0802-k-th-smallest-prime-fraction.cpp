class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b){
        
        double frac1 = a.first/(a.second*1.0) ;
        double frac2 = b.first/(b.second*1.0) ;

        return frac1 < frac2 ;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<pair<int,int>> fraction ;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                fraction.push_back({arr[i],arr[j]});
            }
        }

        sort(fraction.begin(),fraction.end(),comp);

        vector<int> ans ; 
        ans.push_back(fraction[k-1].first);
        ans.push_back(fraction[k-1].second);

        return ans ;
    }
};

// Solution::comp ;