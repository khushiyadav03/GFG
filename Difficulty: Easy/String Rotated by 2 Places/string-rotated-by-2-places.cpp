class Solution {
public:
    bool isRotated(string s1, string s2) {
        // Check if lengths match
        if (s1.size() != s2.size()) return false;
        if (s1.size() < 2) return s1 == s2; // edge case

        // Left rotation by 2: move first 2 chars to the end
        string left = s1.substr(2) + s1.substr(0, 2);

        // Right rotation by 2: move last 2 chars to the start
        string right = s1.substr(s1.size() - 2) + s1.substr(0, s1.size() - 2);

        // Check if s2 matches either rotation
        return (s2 == left || s2 == right);
    }
};
