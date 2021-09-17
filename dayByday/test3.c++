#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求权值，即k到j这一段的极差
int weight(vector<int> ans, int k, int j){
    int res = *max_element(ans.begin()+k, ans.begin()+j+1) - *min_element(ans.begin()+k, ans.begin()+j+1);
    return res;
}



int main() {
    //输入数据个数和分组数
    int n, m;
    cin>>n>>m;
    vector<int> ans(n+1, 0);
    for(int i = 1; i<= n;i++){
        cin>>ans[i];
    }
    //建立二维dp数组
    //dp[i][j]表示前j个数据分为i组的最小权值和
    //则dp[i][j] = min(weight(k, j) + dp[i-1][k-1])
    //所以是需要i, j, k三层循环的，时间复杂度不包括weight函数为 O(n^2*m)，比较高，不知道会不会卡
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    //baseCase: 分为1组时则直接为该段的权值，由状态转移方程知对于每一个i，j只需遍历到n-(m-i)为止
    for(int i = 1;i <= n-(m-1);i++){
        dp[1][i] = weight(ans,1, i);
        cout<<"(1,"<<i<<"):"<<dp[1][i]<<"  ";
    }
    cout<<endl;

    for(int i = 2; i <= m; i++){
        for(int j = i;j <= n-(m-i); j++){
            int minW = 0x7ffffff;
            for(int k = i;k <=j; k++){
                int temp = weight(ans, k, j) + dp[i-1][k-1];
                minW = min(temp, minW);
            }
            dp[i][j] = minW;
            cout<<"("<<i<<","<<j<<"):"<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<dp[m][n];

}