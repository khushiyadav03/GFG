class Solution {
public:
    string caseSort(string &s) {
        vector<char> lower, upper;
        
        // Separate lowercase and uppercase
        for (char c : s) {
            if (islower(c)) 
                lower.push_back(c);
            else 
                upper.push_back(c);
        }
        
        // Sort each group
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        
        // Reconstruct string
        int li = 0, ui = 0;
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) 
                res[i] = lower[li++];
            else 
                res[i] = upper[ui++];
        }
        
        return res;
    }
};
