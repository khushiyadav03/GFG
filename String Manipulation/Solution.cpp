// User function Template for C++
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
        stack<string> s;
        for(int i = 0; i<arr.size(); i++){
            if(s.empty()){
                s.push(arr[i]);
            } else if (arr[i] == s.top()){
                s.pop();
            } else {
                s.push(arr[i]);
            }
        }
        
        return s.size();
    }
};