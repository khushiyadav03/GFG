#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> ans(n);
        stack<int> st; // stores indices

        for(int i = 0; i < n; i++) {
            while(!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = i + 1;  // all previous days are smaller or equal
            } else {
                ans[i] = i - st.top();  // distance to previous greater element
            }

            st.push(i);
        }
        return ans;
    }
};
