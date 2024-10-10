class ProductOfNumbers {
public:
    vector<int> prefix ;
    int product ;

    ProductOfNumbers() {
        this->product = 1 ;    
    }
    
    void add(int num) {
        
        product *= num ;
        prefix.push_back(product);

        if(product == 0){
            product = 1 ;
            fill(prefix.begin(),prefix.end(),0);
        }
    }
    
    int getProduct(int k) {
        
        int n = prefix.size();
        int ansIndex = n - k - 1;  // last k elements ke ek piche wala

        if(ansIndex < 0)
            return prefix[ansIndex+1] != 0 ? product : 0 ; 

        if(prefix[ansIndex] == 0 && prefix[n-k] == 0)
            return 0;

        else if(prefix[ansIndex] == 0 && prefix[n-k] != 0)
            return product ; 

        return product/prefix[ansIndex];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */