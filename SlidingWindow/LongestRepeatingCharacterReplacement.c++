// .424
// 最开始想的是dp，但是并没有相处很好的方法，如果仅是k=1还好
// 所以最好的是将题目换一种表述，即找到最长的区间，区间内不重复的字符不超过k
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26,0);
        int left = 0;
        int right = 0;
        int maxn = 0;
        while(right < s.length()){
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if(right - left + 1 - maxn > k){
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};