// 贪心难想
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int s = accumulate(machines.begin(), machines.end(), 0), n = machines.size() ;
        if(s%n!= 0) return -1;
        int avg = s / n;
        int ans = 0, sum = 0;
        for(auto & num : machines){
            num -= avg;
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }
        return ans;
    }
};