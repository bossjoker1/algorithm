//1760 看到最大值最小化或者最小值最大化就想到用二分法
//这题将分开装的次数作为target很明显，注意是否可以整除要分开讨论
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        while(l < r){
            int mid = (l + r) >> 1;
            int cnt =0;
            for(auto ans: nums){
                if(ans % mid == 0) cnt += ans/mid - 1;
                else cnt += ans/mid;
            }
            if(cnt > maxOperations)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};