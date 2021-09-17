//435 贪心思想：跟书上区间调度问题类似，也是使结尾的位置尽可能小，也保证后面有更充足的空间

class Solution {
public:
    // 按照区间右边界排序
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1; // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};


//类似问题： 最少箭数射完气球
//只是改为要求覆盖最多的
//而且刚好与上面相反，即求不交叉的，上面是求交叉的需要移除
//同时注意题意
class Solution {
public:

    // 按照区间右边界排序
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int count = 1; // 记录非交叉区间的个数
        int end = points[0][1]; // 记录区间分割点
        for (int i = 1; i < points.size(); i++) {
            //箭挨着也行，所以不要等号
            if (end < points[i][0]) {
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};