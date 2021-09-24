// 抽象出4个桶，对索引进行回溯

class Solution {
public:

    bool backtrack(vector<int>& matchsticks, int index, int sub, vector<int>& bucket){
        if(index < 0){
            if(bucket[0] == bucket[1]&&bucket[1] == bucket[2] &&bucket[2]== bucket[3]) 
                return true;
            return false;
        }

        for(int i = 0 ; i < bucket.size(); i++){
            //也可以只要前面的判断，因为后面的太难想了
            if (bucket[i] + matchsticks[index] > sub || (i > 0 && bucket[i] == bucket[i - 1]) || (index == matchsticks.size() - 1 && i != 0))
                continue;
            bucket[i] += matchsticks[index];
            if (backtrack(matchsticks, index - 1, sub, bucket))
                return true;
            bucket[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum =  accumulate(matchsticks.begin(), matchsticks.end(), 0) ;
        if(sum % 4 != 0 || matchsticks.size() < 4) return false;
        int sub = sum >> 2; // 每条边必须达到的长度
        // 先选大的，因为先选小的，递归太深
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());  
        if (matchsticks[0] >  sub ) return false;
        vector<int> bucket(4, 0);
        return backtrack(matchsticks, matchsticks.size()-1, sub, bucket);
    }
};