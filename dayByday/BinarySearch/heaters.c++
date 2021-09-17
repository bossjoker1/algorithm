//c++
//这个二分的思想是找的每一个房子离前一个或者后一个加热器最近的距离
//我一开始想的是对可能的距离进行二分，由于加热器位置的特殊性，比较难考虑清楚
//所以还是不要局限于一种二分思想
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //找到每个房屋位置所需要的最小半径的最大值
        int res = 0;
        int n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (auto house : houses)
        {
            //二分法找不小于house的第一个值
            int left = 0, right = n;
            while (left < right)
            {
                int mid = left + (right - left)/2;
                if (house > heaters[mid]) left = mid + 1;
                else right = mid;
            }
            if(right==0) res = max(res, abs(house - heaters[right]));
            else if(right==n) res = max(res,abs(house - heaters[right-1]));
            else res = max(res, min(abs(house - heaters[right]), abs(house -heaters[right-1])));
        }
        return res;
    }
};