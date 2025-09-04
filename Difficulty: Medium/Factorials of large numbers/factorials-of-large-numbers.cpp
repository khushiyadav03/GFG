// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        string fact = "1";

    for(int i = 2; i <= n; i++){
        int carry = 0;
        string temp = "";

        for(int j = fact.size()-1; j >= 0; j--){
            int prod = (fact[j]-'0') * i + carry;
            temp = char(prod % 10 + '0') + temp;
            carry = prod / 10;
        }
        while(carry){
            temp = char(carry % 10 + '0') + temp;
            carry /= 10;
        }
        fact = temp;
    }

    vector<int> res;
    for(char c : fact) res.push_back(c - '0');
    return res;
    }
};