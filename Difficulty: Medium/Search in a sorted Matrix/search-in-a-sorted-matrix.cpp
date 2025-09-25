class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int x) {
        // code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = 0, c = cols - 1;
        
        while(r < rows && c > -1){
            int curr = matrix[r][c];
            
            if(curr == x){
                return true;
            }
            
            if(x > curr){
                r++;
            } else {
                c--;
            }
        }
        
        return false;
    }
};