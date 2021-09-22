// 1. BF算法，注意cost和temp的转换对k次的限定
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int> cost(n, INT_MAX);
       cost[src] = 0;
        //  BF算法
       for(int i = 0; i <= k; i++){
           vector<int> temp = cost;
           for(auto & flight : flights){
               int from = flight[0], to = flight[1], c = flight[2];
               if (cost[from] == INT_MAX) continue;
               temp[to] = min(temp[to], cost[from] + c);
           }
           cost = temp;
       }
       for(auto i : cost){
           cout<<i<<endl;
       }
       return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};

// dp 从dst反推到src dp[k][i]表示第i个点用k步到dst的最短路径
// 因为只有k与k-1的转换，所以可以用(i-1)&1 和 i&1来压缩
class Solution {
public:

    int NUM_MAX = 1000007;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<int>> dp(2, vector<int>(n, NUM_MAX));
       dp[0][dst] = 0;
       int res = NUM_MAX;
       for(int i = 1; i<=k+1; i++){
           vector<int> temp(n, NUM_MAX);
           dp[i&1] = temp;
           for(auto & flight : flights){
               dp[i&1][flight[0]] = min(dp[i&1][flight[0]], flight[2] + dp[(i-1)&1][flight[1]]);
           }
           res = min(res, dp[i&1][src]);
       }

       return res >= NUM_MAX ? -1 : res;
    }
};

// bfs 加剪枝
