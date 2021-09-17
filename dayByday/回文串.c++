class Solution {
public:
//中心扩散法
    int countSubstrings(string s) {
        cnt=0;
        int len=s.size();
        for(int i=0;i<len;++i)
        {
            centre_extend(s,i,i);
            centre_extend(s,i,i+1);
        }
        return cnt;
    }
    void centre_extend(string &s,int left,int right)
    {
        while(left>=0&&right<s.size()&&s[left]==s[right])
        {
            cnt++;
            left--,right++;
        }
    }
    int cnt;
};