//每日一题：649. Dota2 Senate
//关键：理清题意，抽象出逻辑关系
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radianSenaters, direSenaters;

        //初始化,保存索引
        for(int i = 0;i < senate.size(); i++){
            if(senate[i] == 'R') radianSenaters.push(i);
            else direSenaters.push(i);
        }

        while(!radianSenaters.empty() && !direSenaters.empty()){
            int rfront = radianSenaters.front();
            int dfront = direSenaters.front();
            radianSenaters.pop();
            direSenaters.pop();
            if(rfront < dfront){
                //先下手为强
                rfront += senate.size();//保留继续发言
                radianSenaters.push(rfront);
            }else{
                dfront += senate.size();
                direSenaters.push(dfront);
            }
        }
        return radianSenaters.empty() ? "Dire" : "Radiant";
    }
};