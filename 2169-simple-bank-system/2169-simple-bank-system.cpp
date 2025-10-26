#define ll long long 

class Bank {
public:
    vector<ll> v ;
    int n ;

    Bank(vector<long long>& balance) {
        
        n = balance.size();
        v = balance ;
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(account1 >= 1 && account1 <= n && account2 >=1 && account2 <=n){

            if(v[account1-1] >= money){

                v[account1-1] -= money ;
                v[account2-1] += money ;

                return true ;
            }

            else return false ;
        }

        return false ;
    }
    
    bool deposit(int account, long long money) {
        
        if(account >= 1 && account <= n){

            v[account-1] += money ;
            return true ;
        }

        else return false ;
    }
    
    bool withdraw(int account, long long money) {
        
        if(account >= 1 && account <= n){

            if(v[account-1] >= money){
                v[account-1] -= money ;
                return true ;
            }

            else return false ;            
        }

        else return false ;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */