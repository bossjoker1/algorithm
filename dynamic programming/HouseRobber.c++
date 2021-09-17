//HouseRobber I
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int pre = 0, post = 0, mid = 0;
        for(int i = n-1;i>=0;i--){
            pre = max(mid, nums[i] + post);
            post = mid;
            mid  = pre;
        }
        return pre;
    }
};

//HouseRobber II
//新增限制条件为房子围成一个圈
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        //要么只抢第一家或者最后一家即分成1 -- n-1或 0--n-2
        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
    int robRange(vector<int> nums, int end, int start){
        int pre = 0,mid = 0,post = 0;
        for(int i = start;i>=end;i--){
            pre = max(mid, nums[i] + post);
            post = mid;
            mid = pre;
        }
        return pre;
    }
};