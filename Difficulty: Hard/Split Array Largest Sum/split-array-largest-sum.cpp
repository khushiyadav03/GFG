class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int time = 0, count = 1;
            for(int i = 0; i<n; i++){
                if(time + arr[i] > mid){
                    count++;
                    time = arr[i];
                } else {
                    time += arr[i];
                }
            }

            if(count <= k){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};