class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int mid = 0 ;
        int left = 0 ;
        int right = arr.size()-1 ;

        while(mid <= right){

            if(arr[mid] == 1)
                mid++;

            else if(arr[mid] == 0){
                swap(arr[left],arr[mid]);
                left++;
                mid++;
            }

            else{
                swap(arr[right],arr[mid]);
                right--;
            }
        }
    }
};