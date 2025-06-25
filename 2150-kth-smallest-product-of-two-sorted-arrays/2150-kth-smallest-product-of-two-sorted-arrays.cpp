#define ll long long 

class Solution {
public:
    ll findCountSmallest(vector<int>& nums1, vector<int>& nums2, ll midProduct) {

        //  yha pe midProduct ki position find kr rhe hai 
        // ya phir usse chote elements , ek hi baat hai 
        ll productsCount = 0;

        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            //nums1[i]

            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; //invalid index on left hand side
                // m -> kitne prod isse chote ya equal hai (index in nums2)

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    ll product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }

                productsCount += (m+1); //covered by nums1[i]
            } else {
                //product will be negative and right hand side will contain smaller products and left hand side larger
                // right to left , product is increasing 
                int l = 0;
                int r = n-1;
                int m = n; //invalid index on the right hand side

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    ll product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                                                    
                productsCount += (n - m);
            }
        }
        
        return productsCount;
    }

    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        
        //  B.S on answer (product value)

        ll ans = 0;

        ll l = -1e10; //min product possible
        ll r = 1e10; //max product possible

        while(l <= r) {

            ll midProduct = l + (r-l)/2;

            //check if this is kth smallest or not

            ll countSmallest = findCountSmallest(nums1, nums2, midProduct);

            if(countSmallest >= k) {
                ans = midProduct;
                r = midProduct-1;
            } 
            
            else l = midProduct+1;
        }

        return ans;
    }
};




