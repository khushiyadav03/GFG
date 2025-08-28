#include <numeric>

class Solution {
public:
    int missingNum(vector<int>& arr) {
        long long n = (long long)arr.size() + 1;           // 1..n
        long long total = n * (n + 1) / 2;                  // 64-bit
        long long sum = std::accumulate(arr.begin(), arr.end(), 0LL);
        return (int)(total - sum);
    }
};
