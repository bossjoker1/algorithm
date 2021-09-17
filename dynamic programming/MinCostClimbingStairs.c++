// ./746 eaxy
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int pre = 0, post = 0;
        for(int i = 2; i <= n; i++){
            int next = min(pre + cost[i-2], post + cost[i-1]);
            pre = post;
            post = next;
        }
        return post;
    }
};