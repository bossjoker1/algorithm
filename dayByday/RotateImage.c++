// .48 
// 演绎推理，找关系
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //时间复杂度 ： O(n*logn)
        int n = matrix.size(), flag;
        if(n == 1 || n == 0) return; 
        flag = n % 2 == 0 ? n - 2 : n - 3;
        for(int i = 0; i <=  flag; i++ ){
            for(int j = 0; j < n - 2*i - 1; j++){
                int tmp = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-1-i-j][i];
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = tmp;
            }
        }
    }
};