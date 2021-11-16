// 类似编译原理定义
/*
    表达式计算 f(x)%mod 
    Expression:   //处理+,- 
        Term2
        Expression + Term2
        Expression - Term2
	Term2:       //*或者同级运算 
        Term1
        Term2 * Term1
	Term1:      //处理^ 
        Primary
        Term1 ^ Primary
        - Term1
		+ Term1        
    Primary:    //处理整数、括号 
        Number
        ( Expression )
    Number:
        unsigned integer
*/
#include<iostream>
using namespace std;

typedef unsigned long long ll;
#define MAXCHARS 10240
#define number   1

//Token用于保存词法分析结果 
class Token {
public:
    char kind;        // token的类型，字符型的类型用字符本身表示，数字的类型为number（1）,行结束用0表示 
    ll value;        // kind=number时才有意义，value中保存整数值 
    Token(char ch)    // 解析到字符或者结束字符0 
        :kind(ch), value(0) { }
    Token(char ch, ll val)     // 解析到整数 
        :kind(ch), value(val) { }
};
//Token_stream用于扫描输入流 
class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    char getone();
	void putback();
   	void readline();
   	void clear(); 
    ll randint,mod;
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
    char line[MAXCHARS];
    int index;
}ts;

Token_stream::Token_stream()
:full(false), buffer(0)
{
}
void Token_stream::clear()//每次重新开始计算前清除 
{
	full=false;
	buffer=0;
	index=0;
}
void Token_stream::readline()//从标准输入读入一行，自动过滤回车、换行 
{
	index=0;
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch!='\n'&&ch!=EOF)
			line[index++]=ch;
		else
			break;
	}
	line[index]=0;
	index=0;
}
void Token_stream::putback()//解析过头了可以撤回，用于仅当读入下一个字符才知道当前单词是否结束的情况，比如读12345+ 
{
	index--;
}
char Token_stream::getone()//从缓冲区读入一个字符 
{
	return line[index++];
}
void Token_stream::putback(Token t)//用于token不在当前级别语法范围，退回 
{
    if (!full) 
    {
    	buffer = t;       
    	full = true;
	}
}
Token Token_stream::get() //词法分析 
{
    if (full) {         //先看看是否有退回的，如果有直接从退回的缓冲区去取 
        full=false;
        return buffer;
    }
    while(true){//读完一个token 
		char ch=getone();
	    switch (ch) {
		    case '(':
		    case ')':
		    case '+':
		    case '-':
		    case '*':
		    case '^':
		    case 0  ://行结束 
		        return Token(ch);
		    case 'x':
		    	return Token(number,randint);//把x赋值为randint 
			case '0': case '1': case '2': case '3': case '4':
		    case '5': case '6': case '7': case '8': case '9':
		    {
		        ll val=0;
				while(ch>='0' && ch<='9')
		        {
		        	val=val*10+ch-'0';
		        	ch=getone();
				}
				putback();   
		        return Token(number,val%mod);
		    } 	
		    default:	        
		    	return Token(ch);//此处也可以用于报错，例如出现空格或者其他字符时认为不合法 
	    }
	}//while
}
ll expression();//primary会递归调用 
ll primary()//处理非负整数和括号 
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // 括号 '(' expression ')'
        {
            ll d = expression();
            t = ts.get();//必须是')'
            return d;
        }
    case number:
        return t.value;    // 返回整数值 
    default:
        return 0;//亦可用于错误处理 
    }
}
ll term1()//处理^或者连续多个^，如果没有^,就直接返回表达式的值 
{
	//正、负号 
	Token t = ts.get();
	if(t.kind=='-')
		return (ts.mod-term1())%ts.mod;
	else if(t.kind=='+')
		return term1(); 
	ts.putback(t);
	
	ll left = primary();
    ll ans=left;
	t = ts.get(); //获取下一个单词 
    while(true) {
        switch (t.kind) {
        case '^':
        	{
        		ll d = primary();//假设d>0
        		left=ans;
            	for(int i=1;i<d;i++)
            		ans=(ans*left)%ts.mod;
            	t = ts.get();
            	break;
			}
        default://不是本级运算符则，退回 
            ts.putback(t);        // put t back into the token stream
            return ans;
        }
    }//while
}

//处理*, /, and%等同级运算，比^的级别低 
ll term2()
{
    ll left = term1();
    Token t = ts.get(); //获取运算符 

    while(true) {
        switch (t.kind) {
        case '*':
            left = (left*term1())%ts.mod;
            t = ts.get();
            break;
        default:
            ts.putback(t);        //不是本级运算符则退回 
            return left;
        }
    }
}
// 处理最低级运算符 + 、 -
ll expression()
{
    ll left = term2();      // 读左边值 
    Token t = ts.get();     // 获取运算符 
	ll d;
    while(true) {
        switch(t.kind) {
        case '+':
        	left = (left+term2())%ts.mod;//读右边值，并计算 
            t = ts.get();
            break;
        case '-':
            left = (ts.mod+left-term2())%ts.mod; 
            t = ts.get();
            break;
        case 0: //表达式扫描结束 
        	return left;
        default:
            ts.putback(t);   //可用于错误处理,此处碰到多余不合法项直接舍弃，例如1+xx会解析为1+x
            return left; 
        }
    }
}
//代入x值，和mod,计算表达式 
ll calc(ll randint,ll mod)
{
	ts.clear();
	ts.randint=randint;
	ts.mod=mod;
	return expression();
}

int main()
{
	ll ans1,ans2;
	int n;
	ll r1=298347523,m1=1498753483,r2=132270983,m2=2111234388;
	ts.readline();
	ans1=calc(r1,m1);
	ans2=calc(r2,m2);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		ts.readline();
		if(ans1==calc(r1,m1) && ans2==calc(r2,m2))
			printf("%d ",i);
	}
	
	return 0;
}