// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int low = 0, high = arr.size() - 1;
        int count = -1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == 0){
                count = mid;
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        
        if(count == -1) return 0;
        
        return arr.size() - count;
    }
};