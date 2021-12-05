#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
const int N = 5e6+10;
typedef long long ll;
//LDd目录配额，LRd后代配额,LD现有目录额，LR现有后代额
struct node
{
    map<string,int> branch;   //每个目录节点的孩子节点(包括目录节点和普通文件)
    int isleaf;     //是否是普通文件
    ll LDd,LRd;     //目录配额，后代配额
    ll LD,LR;       //现有目录，后代
    ll val;         //普通文件的大小
    int fa;         //父节点编号
}tr[N];
int vex;   //有效文件名所属编号
string getindex(string &s,int &num)   //截取一个合法文件名
{
    string res="";
    int i;
    for(i=num;s[i]!='/'&&i<s.size();i++)
        res+=s[i];
    num=i+1;
    return res;
}
vector<pair<int,string> > v;   
void del()   //若插入失败，对本次前面所有插入操作进行撤销
{

    for(int i=0;i<v.size();i++)
    {

        int a=v[i].first;
        string b=v[i].second;
        tr[a].branch.erase(tr[a].branch.find(b));
    }
}
bool insert(string s,ll size)  //文件插入
{
    v.clear();
    int num=1,fa=0,init=vex,len=s.size();
    while(num<len)     //直至截取最后一个文件名
    {
        string ss=getindex(s,num);
        //如果要创建的目录文件与已有的同一双亲目录下的孩子文件中的普通文件名称重复，则该指令不能执行成功
        if(tr[fa].branch[ss] && tr[tr[fa].branch[ss]].isleaf && num<len)  
        {
            vex=init;del();
            return false;
        }
        int id,flag=0;
        if(tr[fa].branch[ss])  
            id=tr[fa].branch[ss],flag=1;
        else  //若不存在该目录/普通文件，进行创建
            id=++vex,tr[vex].isleaf=0,tr[vex].fa=fa,tr[vex].LDd=0,tr[vex].LRd=0,tr[fa].branch[ss]=vex,v.push_back(make_pair(fa,ss));
        if(num<len)
            fa=id;
        if(num>=len)   //遍历至叶子文件时
        {
            ll extra;  //需要更新的文件值
            if(flag)   //叶子文件如果已存在
            {
                if(!tr[id].isleaf)   //如果是个目录文件，插入失败
                {
                    vex=init;del();
                    return false;
                }
                extra=size-tr[id].val;
            }
            else
                extra=size;
            if(tr[fa].LD+extra>tr[fa].LDd&&tr[fa].LDd)   //如果双亲目录的目录配额存在且因为插入该文件超额，插入失败
            {
                vex=init;del();
                return false;
            }
            tr[id].val=size;
            tr[id].LR=size;
            tr[id].isleaf=1;
            for(int r=fa;r!=-1;r=tr[r].fa)
                if(tr[r].LR+extra>tr[r].LRd&&tr[r].LRd)  //如果后代配额存在且会因为插入此文件超额，插入失败
                {
                    vex=init;del();
                    return false;
                }
            for(int r=fa;r!=-1;r=tr[r].fa)  //插入成功，更新整条路径
                tr[r].LR+=extra;
            tr[fa].LD+=extra;
        }

    }
    return true;
}
void remove(string s)   //移除文件
{
    int num=1,fa=0,len=s.size();
    while(num<len)
    {
        string ss=getindex(s,num);
        if(!tr[fa].branch[ss]) return;   //若路径不存在，直接返回
        int id=tr[fa].branch[ss];
        if(num<len)
            fa=id;
        if(num<len&&tr[id].isleaf)  //如果路径不合法，返回
            return;
        if(num>=len)
        {
            tr[fa].branch.erase(tr[fa].branch.find(ss));  //删除与双亲节点之间的路径
            for(int r=fa;r!=-1;r=tr[r].fa)   //更新前面祖宗节点的后代配额
                tr[r].LR-=tr[id].LR;
            if(tr[id].isleaf)     //若删除节点为叶子节点，更新双亲节点的目录配额
                tr[fa].LD-=tr[id].LR;
        }
    }
}
bool set(string s,ll ld,ll lr)   //设置配置额
{
    if(s.size()==1)  //配置根目录
    {
        int id=0;
        if((ld<tr[id].LD && ld) || (lr<tr[id].LR && lr))  //如果配置额小于当前已存在的文件大小，配置失败
            return false;
        tr[id].LRd=lr;tr[id].LDd=ld;
        return true;
    }
    int num=1,fa=0,len=s.size();
    while(num<len)
    {
        string ss=getindex(s,num);
        if(!tr[fa].branch[ss]) return false;  //如果路径不存在，配置失败
        int id=tr[fa].branch[ss];
        fa=id;
        if(tr[id].isleaf) return false;   //如果配置的不是目录文件，配置失败
        if(num>=len)
        {
            if((ld<tr[id].LD && ld) || (lr<tr[id].LR && lr))  //如果配置额小于当前已存在的文件大小，配置失败
                return false;
            tr[id].LRd=lr;tr[id].LDd=ld;  //修改额度，配置成功
            return true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s;
	int n;
	cin>>n;
	tr[0].fa=-1;
	tr[0].isleaf=0;
	tr[0].LDd=0;
	tr[0].LRd=0;
	while(n--)
    {
        bool flag=true;
        char order;
        cin>>order;
        ll ld,lr,size;
        switch(order)
        {
            case 'C':cin>>s>>size;flag=insert(s,size);break;
            case 'R':cin>>s;remove(s);break;
            case 'Q':cin>>s>>ld>>lr;flag=set(s,ld,lr);break;
        }
        if(flag)
            cout<<"Y"<<'\n';
        else
            cout<<"N"<<'\n';
    }
    return 0;
}


