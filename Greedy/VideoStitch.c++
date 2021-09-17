// 1024 程序员标号
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        //贪心
        int end = 0, pre = 0, res = 0;
        vector<int> vec(T);
        for(auto& it : clips){
            //找到最右边的端点
            if(it[0] < T){
                vec[it[0]] = max(vec[it[0]], it[1]);
            }
        }
        for(int i = 0; i < T;i++){
            end = max(end, vec[i]);
            if(i == end) return -1;
            if(i == pre){
                res++;
                pre = end;
            }
        }
        return res;
    }
};