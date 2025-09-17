class compare{
    public:
    bool operator()(pair<int,string>& a,pair<int,string>& b){

        if(a.first == b.first)
            return a.second > b.second ;

        return a.first < b.first ;
    }
};

class FoodRatings {
public:
    map<string,int> foodRating ;
    map<string,vector<string>> foodCuisines ; // for updating rating of food
    map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,compare>>   cuisinetoRatingFood ;
    // highest rating , lexi smaller if same 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        foodRating.clear();
        cuisinetoRatingFood.clear();

        for(int i=0;i<foods.size(); i++){

            string f = foods[i] , c = cuisines[i];
            int val = ratings[i];

            foodRating[f] = val ;
            foodCuisines[f].push_back(c);
            cuisinetoRatingFood[c].push({val,f});
        }
    }
    
    void changeRating(string food, int newRating) {
        
        foodRating[food] = newRating ;
        for(auto &c:foodCuisines[food]){

            cuisinetoRatingFood[c].push({newRating,food});
        }
    }
    
    string highestRated(string cuisine) {
        
        auto &maxHeap = cuisinetoRatingFood[cuisine] ;
        while(!maxHeap.empty()){

            auto [rating,food] = maxHeap.top();
            
            if(foodRating[food] != rating)
                maxHeap.pop();

            else return food;             
        }

        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */