#include<stdio.h>

typedef long long ll;

ll board[30][30] = {0};

int main() {
    int n, m, m1, m2;
    scanf("%d%d%d%d",&n,&m,&m1,&m2);
    // 初始化棋盘
    board[m1][m2] = board[m1+1][m2+2] = board[m1+2][m2+1] = 1;
    if(m1-1>=0){
        board[m1-1][m2+2] = 1;
        if(m2-2>=0) board[m1-1][m2-2] = 1;
        if(m1-2>=0){
            board[m1-2][m2+1] = 1;
            if(m2-1>=0) board[m1-2][m2-1] = 1;
        } 
    }

    if(m2-1>=0) board[m1+2][m2-1] = 1;
    if(m2-2>=0) board[m1+1][m2-2] = 1;


    // 奇怪输入
    if(board[0][0] == 1 || (board[n-1][m] == 1 && board[n][m-1] == 1) || (board[0][1] == 1 && board[1][0] == 1)){   
        printf("0\n");
        return 0;
    }

    ll dp[30][30] = {0};
    dp[1][1] = 1;
    for(int i = 1;i<=n+1;i++){
        for(int j = 1;j<=m+1;j++){
            if(board[i-1][j-1]!=1&& dp[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    

    printf("%d\n", dp[n+1][m+1]);
    return 0;
}