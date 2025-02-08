class NumberContainers {
public:
    unordered_map<int,int> mp ; // stores value for each index
    unordered_map< int,set<int> > elePositions ;

    NumberContainers() {}
    
    void change(int index, int number) {
        
        if(mp.count(index)){
            // pehle element store tha 
            int previousEle = mp[index];
            elePositions[previousEle].erase(index);
        }

        elePositions[number].insert(index);
        mp[index] = number ;
    }
    
    int find(int number) {
        
         if(elePositions.count(number)){

            if(elePositions[number].empty()){
                return -1 ;
            }

            else return *elePositions[number].begin();
        }

        else return -1 ;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */