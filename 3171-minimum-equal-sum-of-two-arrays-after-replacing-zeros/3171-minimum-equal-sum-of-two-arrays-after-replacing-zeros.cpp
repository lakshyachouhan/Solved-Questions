#define ll long long 

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        ll ans = -1 ;
        ll sum1 = accumulate(nums1.begin(),nums1.end(),0LL);
        ll z1 = count(nums1.begin(),nums1.end(),0);

        ll sum2 = accumulate(nums2.begin(),nums2.end(),0LL);
        ll z2 = count(nums2.begin(),nums2.end(),0);

        // cout << sum1 << "  " << z1 << endl ;
        // cout << sum2 << "  " << z2 << endl ;

        if(sum1 == sum2){

            if(z1 == 0 && z1 == z2)
                return sum1 ;

            if(z1 != 0 && z2 != 0)
                return sum1 + max(z1,z2);

            else return -1 ;
        }

        else if(sum1 > sum2){

            ll diff = sum1 - sum2 ;
            diff += z1 ;  // jitne z1 the unko 1 man liya hai 

            if(diff >= z2 && z2 != 0)
                return sum2 + diff ;

            else if(diff < z2 && z1 != 0) 
                return sum2 + z2 ;

            return -1 ;
        }

        else{

            ll diff = sum2 - sum1 ;
            diff += z2 ; // jitne z2 the unko 1 man liya hai 

            if(diff >= z1 && z1 != 0 )
                return sum1 + diff ;

            else if(diff < z1 && z2 != 0) 
                return sum1 + z1 ;

            return -1 ;
        }


    }
};