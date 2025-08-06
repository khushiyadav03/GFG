#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &nums) {
        // code here
        int n = nums.size();
        vector<int> res(n, -1); // Initially sab -1
        stack<int> st; // Stack for storing indices

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!st.empty() && nums[idx] > nums[st.top()]) {
                res[st.top()] = nums[idx];
                st.pop();
            }

            if (i < n) st.push(idx); // Sirf first pass mein hi push
        }

        return res;
    }
};