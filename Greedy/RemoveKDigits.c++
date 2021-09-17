class Solution {
public:
    string removeKdigits(string num, int k) {
       if(num.length()==k)return "0";
       for(int i=0;i<k;i++)
       {
           //贪心策略：删除第一个比后面的数大的数字，如果没有说明单调增，则只需删除最后一个数及可
           int idx=0;
           for(int j=1;j<num.length()&&num[j]>=num[j-1];j++) idx=j;
             num.erase(num.begin()+idx);
           while(num.length()>1&&num[0]=='0')num.erase(num.begin());
       }
       return num;
    }
};