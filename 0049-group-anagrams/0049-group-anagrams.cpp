class Solution {
public:
// POTD
    std::array<int,256> hash(string str){
        std::array<int,256> hash = {0};

        for(char ch:str)
           hash[ch]++;

       return hash ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // stl array 
      map<std::array<int,256>,vector<string>> mp ;

      for(auto s:strs){

          mp[hash(s)].push_back(s);
      }

      vector<vector<string>> ans ;

      for(auto i:mp){
          ans.push_back(i.second);
      }

      return ans ;
    }
};