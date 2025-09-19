class Solution {
  public:
    int cubeRoot(int x) {
        // code here
        int low = 1, high = x, ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long  sq = mid * mid * mid;

            if(sq == x){
                return mid;
            } else if (sq < x){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 

        return ans;
    }
};