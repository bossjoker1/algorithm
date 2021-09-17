//.42
//从整体抽象出对局部的思考
//1：双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if( n == 0) return 0;
        int left = 0, right = n - 1;
        int res = 0;

        int l_m = height[left], r_m = height[right];

        while(left <= right){
            l_m = max(l_m, height[left]);
            r_m = max(r_m, height[right]);
            if(l_m < r_m){
                res += l_m - height[left];
                left ++;
            }else{
                res += r_m - height[right];
                right --;
            }
        }
        return res; 
    }
};


//2.单调栈，来自网络 作者：ikaruga
int trap(vector<int>& height)
{
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int l = st.top();
            int r = i;
            int h = min(height[r], height[l]) - height[cur];
            ans += (r - l - 1) * h;
        }
        st.push(i);
    }
    return ans;
}

