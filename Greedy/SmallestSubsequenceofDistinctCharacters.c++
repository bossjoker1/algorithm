// .1081 middle
class Solution {
public:
    string smallestSubsequence(string text) {
       int n=text.size();
       vector<char> temp;
       string res="";
       for(int i=0;i<n;i++){
           char c=text[i];
           if(find(temp.begin(),temp.end(),c)!=temp.end()) continue;
           while(!temp.empty()&&c<temp.back()&&text.find(temp.back(),i)!=-1){
               temp.pop_back();
           }
           temp.push_back(c);
       }
       for(auto ss:temp)
           res+=ss;
       return res;
    }

};
