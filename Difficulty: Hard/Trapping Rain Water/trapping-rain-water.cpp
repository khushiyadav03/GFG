class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int n = height.size();
        stack<int> st;
        int water = 0;

        for(int i = 0; i<n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;

                int wid = i - st.top() - 1;
                int heig = min(height[i], height[st.top()]) - height[top];
                water += wid * heig;
            }
            st.push(i);
        }
        return water;
    }
};