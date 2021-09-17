//.738 middle
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int flag = str.size();
        for(int i = str.size() - 1; i > 0 ; i--){
            if(str[i-1] > str[i]){
                flag = i;
                str[i-1]--;
            }
        } 
        for(int i = flag; i< str.size();i++){
            str[i] = '9';
        }
        return stoi(str);
    }
};