class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
    
    // Purane wale ka start , currEnd se chota hai &
    // purane wale ka end , currStart se bada hai  
    // TOH OVERLAPPING HAI
    
        
        auto it = st.upper_bound({start,end});
        if(it != st.end() && it->second < end)
            return false ;

        st.insert({end,start});
        return true ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */