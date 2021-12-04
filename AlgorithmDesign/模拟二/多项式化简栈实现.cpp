#include<bits/stdc++.h>
using namespace std;
const long long mod=100000007;
//模幂运算 
long long Pow(long long a,long long b)
{
    if(a==0)return 0;
    long long s=1;
    long long t=a;
    while(b>0)
    {
        if(b%2==1)
           s=(s*t)%mod;
        t=(t*t)%mod;
        b/=2;
    }
    return s;
}
unsigned int lev[256];//运算符优先级 
stack<long long>num;//数字栈 
stack<char>op;//运算符栈 
void calc()//从栈顶拿出两个元素，计算结果，然后再压入栈中 
{
	char ts=op.top();
    op.pop();
    long long t1=num.top();
    num.pop();
    long long t2=num.top();
    num.pop();
    long long ans=0;
    if(ts=='+')ans=(t1+t2)%mod;
    if(ts=='-')ans=(t2-t1+mod)%mod;
    if(ts=='*')ans=(t1*t2)%mod;
    if(ts=='^')ans=Pow(t2,t1);
    num.push(ans);
}
long long solve(char s[],long long xx)//计算一个表达式的值，假设变量取值为xx 
{
	int k=0;//保存(的个数 
    op.push('#');//运算终止符 
    long long temp=0;
    for(unsigned int i=0;s[i]!=0;i++)
    {//一次处理一个字符
        if(s[i]=='x')num.push(xx);
        else if(s[i]<='9'&&s[i]>='0') {
                temp=(temp*10+s[i]-'0')%mod;
                if(s[i+1]<'0'||s[i+1]>'9') {
                    num.push(temp%mod);
                    temp=0;
                }
         }
   		else if(s[i]=='('){
		   op.push('(');k++;
		   if(s[i+1]=='-' || s[i+1]=='+')//处理单目+，-运算 
		   		num.push(0);
		   } 
		else if(s[i]==')') {
        	if(k<=0)return -1;//error!
            while(op.top()!='(')calc();
            op.pop();
            k--;
        } else {//运算符+-*^ 
            char tp=op.top();
            while(lev[(unsigned int)s[i]]<= lev[tp])
            {//栈顶优先级高，就先算栈顶 
                calc();
                tp=op.top();
            }
            //如果s[i]的级别更高了，那么就压栈，等到下一次运算符来了再比较，看看先算谁 
            op.push(s[i]);          
        }
    }
    while(op.top()!='#')calc();//同一级别了，全部顺序算完 
    return num.top();
}
char line[1024];
void getline()
{
	int index=0;
	char ch;
	line[index++]='('; 
	while(1)
	{
		ch=getchar();
		if(ch!='\n'&&ch!=EOF)
			line[index++]=ch;
		else
			break;
	}
	line[index++]=')';
	line[index]=0;
}      
int main(){
    lev[int('#')]=0;//定义优先级，终止符保证继续输入
    lev[int('+')]=1;
    lev[int('-')]=1;
    lev[int('*')]=2;
    lev[int('^')]=3;
    long long a=137;
	getline();
    long long ans=solve(line,a);
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++) {
        getline();
        if(solve(line,a)==ans)
            printf("%d ",i);
    }
    return 0;
}