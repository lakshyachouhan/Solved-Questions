class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        // ACCEPTED O(N^2)
        // int n = boxes.size();
        // vector<int> ans(n) ;

        // for(int i=0; i<n; i++){

        //     int curr = 0 ;
        //     for(int j=0; j<n; j++){

        //         if(boxes[j] == '1')
        //             curr += abs(j-i) ;
        //     }

        //     ans[i] = curr ;
        // }

        // return ans ;

 // ----------------------------------------------------------------

        int n = boxes.size();
        vector<int> left(n) , right(n);
        // left se balls ko move krne mein kitne ops +
        // right se move krne mein 

        int balls = boxes[0] == '1' ? 1 : 0 ;
        left[0] = 0 ;

        for(int i=1; i<n; i++){

            left[i] += left[i-1] + balls ;
            // hr ball ko move mein ek step toh jitne balls utni steps
            if(boxes[i] == '1')
                balls++;
        }

        balls = boxes[n-1] == '1' ? 1 : 0 ;
        right[n-1] = 0 ;

        for(int i=n-2; i>=0; i--){

            right[i] += right[i+1] + balls ;
            if(boxes[i] == '1')
                balls++;
        }

        for(int i=0; i<n; i++)
            left[i] += right[i] ;

        return left ;
    }
};