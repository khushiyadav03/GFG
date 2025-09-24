class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // more students than books

        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = end;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            int page = 0, count = 1; // students count
            
            for(int i = 0; i < n; i++){
                if(page + arr[i] > mid){
                    count++;
                    page = arr[i];
                } else {
                    page += arr[i];
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
