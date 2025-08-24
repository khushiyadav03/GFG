class Solution {
public:
    int calculate(string s) {
        stack<int> st;     // stack to store numbers (positive or negative)
        long num = 0;      // current number being formed (can be multi-digit)
        char sign = '+';   // last seen operator, assume '+' at the start

        // Traverse the entire string
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            //If digit → build the number (handle multi-digit numbers)
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            //If operator OR end of string reached → process the previous number
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                // Depending on the last operator (sign), handle the current num
                if (sign == '+') {
                    st.push(num);         // just push the number
                } else if (sign == '-') {
                    st.push(-num);        // push the negative number
                } else if (sign == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);   // multiply with top of stack
                } else if (sign == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);   // integer division with truncation
                }

                // Update sign to the current operator
                sign = c;
                // Reset num for the next number
                num = 0;
            }
        }

        //Now add everything in stack (handles + and -)
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
