class Solution {
public:
    vector<int> maxOfMins(vector<int> &arr) {
        int n = arr.size();  // 👈 define n here
        vector<int> left(n), right(n);
        stack<int> s;

        // Step 1: Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Step 2: Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        // Step 3: Fill answers for each window length
        vector<int> res(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Step 4: Propagate maximums backwards
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        // Step 5: Final result (ignore res[0])
        vector<int> ans(res.begin() + 1, res.end());
        return ans;
    }
};
