// For adding a val or operation 1 , there are no choices ,
// do just what is asked 

// For operation 2 ,
// there is a tradeoff between S.C & t.C 
// we have two choices , which array to iterate 
// and which array to store in the map 

class FindSumPairs {
public:
    vector<int> arr1 , arr2 ;
    unordered_map<int,int> mp ;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        arr1 = nums1 ;
        
        for(int i=0; i<nums2.size(); i++){

            arr2.push_back(nums2[i]);
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        
        int ele = arr2[index];
        mp[ele]--;
        if(mp[ele] == 0)
            mp.erase(ele);

        arr2[index] += val ;
        mp[arr2[index]]++;
    }
    
    int count(int tot) {
        
        int ans = 0 ;
        for(auto ele:arr1){

            int req = tot - ele ;

            if(mp.count(req))
                ans += mp[req];
        }

        return ans ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */