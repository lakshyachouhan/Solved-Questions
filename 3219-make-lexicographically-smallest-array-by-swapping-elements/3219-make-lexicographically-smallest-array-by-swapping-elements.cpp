class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        // I -> Bubble Sort 
        // hr element ko usse chote element jo condition satisfy kr rha hai 
        // usse replace or swap 
        // change kyoki agr nums = [5,100,44,45,16,30,14,65,83,64]
        // limit = 15       o/p :  [5,100,14,16,30,44,45,64,83,65]
 /*       int n = nums.size();
        bool change = 1; 

        while(change){

            change = 0 ;
            for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                if(nums[j] < nums[i] && abs(nums[j]-nums[i]) <= limit){
                    swap(nums[j],nums[i]);
                    change = 1 ;
                }
            }
        }

    }
        
        return nums ; 
*/

        // sorting + grouping 
        int n = nums.size();
        vector<pair<int,int>> v ;
        for(int i=0; i<n; i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());
        // ab grouping limit ke basis pr
        vector<vector<pair<int,int>>> grouped ;
        grouped.push_back({v[0]});

        for(int i=1; i<n; i++){
            
            // or v[i].first -  v[i-1].first
            if(v[i].first - grouped.back().back().first <= limit){
                grouped.back().push_back(v[i]);
            }

            else grouped.push_back({v[i]});
        }

        for(int i=0; i<grouped.size(); i++){

            // ab ye ek grp hai , isme koi bhi khi bhi arrange kr skte hai 
            // toh ascending mein arrange 
            
            vector<int> indexes ;
            for(auto [ele,index]:grouped[i]){
                indexes.push_back(index);
            }

            sort(indexes.begin(),indexes.end());
            for(int j=0; j<grouped[i].size(); j++)
                nums[indexes[j]] = grouped[i][j].first; 
        }

        return nums ;
    }
};