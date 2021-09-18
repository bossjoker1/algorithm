// 应该是经典题目了，挑战一下
// 还有一个复杂度为 O(n)的 Manacher 算法 插个眼 以后再看看

// 动态规划试一下 状态 dp[i][j]表示[i, j]是不是回文串
// 得到转移方程
// dp[i][j] = dp[i+1][j-1] & (s[i]==s[j])
// 边界条件
// dp[i][i] = true
// dp[i][i+1] = (s[i]==s[i+1])

// 然后需要枚举串长度和左边界 即O(n^2)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};



// 评论区的最牛逼解法 直接收藏
// 思路是将回文串中间的字符认作是相同的
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0){
            return "";
        }

        pair<int, int> index;

        for(int i =0; i< n;i++){
            // 赋值i能继续加速
            i = findlongest(s, i, index);
        }
        return s.substr(index.first, index.second-index.first+1);
    }

    int findlongest(string s, int low, pair<int, int> & index){
        int high = low;
        while(high < s.size()-1 && s[high+1] == s[low]) high++;

        // 定位该回文串中间右位置，供下一次查询使用
        int ans = high;

        while(low > 0 && high < s.size()-1 &&s[low-1]==s[high+1]) {low--, high++;}

        // 记录此次找到的最大长度
        if(high - low > index.second - index.first){
            index.first = low;
            index.second = high;
        }
        return ans;
    }

};