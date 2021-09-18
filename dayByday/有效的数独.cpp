// 就挨个搜呗
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<char> v1, v2, v3;
            for(int j = 0;j < 9;j++){
                if(board[i][j]!='.'){
                    if(!count(v1.begin(), v1.end(), board[i][j])){
                        v1.push_back(board[i][j]);
                    }else{
                        return false;
                    }
                }
                if(board[j][i]!='.'){
                    if(!count(v2.begin(), v2.end(), board[j][i])){
                        v2.push_back(board[j][i]);
                    }else{
                        return false;
                    }
                }
                if(board[i/3*3+j/3][i%3*3+j%3]!='.'){
                    if(!count(v3.begin(), v3.end(), board[i/3*3+j/3][i%3*3+j%3])){
                        v3.push_back(board[i/3*3+j/3][i%3*3+j%3]);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};