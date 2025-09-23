class Solution {
  public:
    bool check(vector<int> arr, int max_pages_per_student, int k){
        int tot=0;
        int cnt=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(tot+arr[i]>max_pages_per_student){
                tot=0;
                tot+=arr[i];
                cnt++;
            }
            else{
                tot+=arr[i];
            }
        }
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        int sum=0,maxi=INT_MIN,n=arr.size();
        if(n<k) return -1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        int i=maxi;
        int j=sum,mid;
        while(i<=j){
            mid=(i+j)/2;
            if(check(arr,mid, k)){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }

 
};