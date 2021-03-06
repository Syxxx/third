/*4-6个数字，5个运算符号,0-3个括号
  四个数字4+3=7位字符串 6+5=11位字符串*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void init();
void equation(int t);
void bracket(int m[],char n[],int t);
char nowsign,sign;
int s1[10];
char s2[10];
int k=0,count=0,lan;
void match( char nowsign );
double low();
double mid();
double high();
void check ();

int main(){
	srand((unsigned(time(NULL))));
	int n;
	cout<<"请选择语言(Please choose language)"<<endl;cout<<"1.中文 2.English ： ";
	cin>>lan;
	switch(lan)
	{
		case 1:cout<<"请输入题数：";cin>>n;break;
		case 2:cout<<"Please enter a number of questions：";cin>>n;break;
		defaul:cout<<"Error!";break; 
	}
	for (int j=0;j<n;j++)
	{
		  init();
		  cout<<endl;
	}
	switch(lan)
	{
		case 1:cout<<"正确题数："<<count<<" 错误题数："<<n-count;break;
		case 2:cout<<"Correct questions:"<<count<<" Wrong questions:"<<n-count;break; 
	}
    return 0;
}

void init(){
     int q;
     q=rand()%3+4;   //数字一共多少位
     equation(q);
}
 
void equation(int t) //产生算式 
{
     char a[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //算式字符串

     for(int i=0;i<t;i++)
     {
          e[i]=rand()%8+1;    // 数字
          q[i]=a[rand()%4]; //符号
     }
     q[t-1]='=';
     bracket(e,q,t-1);//注意这里传的是t-1，形参只有一个t 
}

void bracket(int m[],char n[],int t){   //添加括号
     int q=0;//rand()%2;    //有几个括号
     if(q==1)
     {
        int a=rand()%(t/2)+1;
        int b=a+rand()%(t/2)+2;//分别在第几个数加括号 
 //a+1是第一个括号的位置，b是第二个括号的位置
          for(int i=0;i<=t;i++) //测试算式
          {
          if(i==a) cout<<"(";
		  cout<<m[i];
		  if(i==b-1) cout<<")";
		  if (n[i]=='/')
			cout<<"÷";
		  else
		    cout<<n[i];
          }
     }
     if(q==0)
     {
     	for (int i=0;i<t+1;i++)
     	{
     		if (n[i]=='/')
     		cout<<m[i]<<"÷";
     		else
     		cout<<m[i]<<n[i];
		}
		for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //数字 
     		s2[i]=n[i];  //符号 
		}
		check();	
	 }
}

void check ()
{
	double result;
	sign = s1[0]; /*载入第一个符号*/
	result=low(); /*进行计算*/
	cout<<result;
}
 
void match( char nowsign ) //对当前的标志进行匹配
{
if( sign == nowsign ) //匹配成功，获取下一个标志
	{
		k++;
		if ((k%2) == 0) //下一位是数字 
		sign = s1[k/2];
		else    //下一位是符号 
		sign = s2[(k-1)/2];
	}
}

double low() //用于计算表达式中级别最低的运算
{
	double result1 = mid(); //计算比加减运算优先级别高的部分
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //进行加法运算
		result1 += mid();
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //进行减法运算
		result1 -= mid(); 
		break;
	}
	return result1;
}

double mid() //用于计算表达式中级别较高的运算
{
	double result2 = high();
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //进行乘法运算
		result2 *= high();
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //进行除法运算
		result2 /= high(); 
		break;
	}
	return result2;
}


double high() //用于计算表达式中级别最高的运算，即带（）的运算
{
	double result3; 
	if( sign == '(' ) //带有括号的运算
	{
		match( '(' );
		result3 = low(); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign<= 9) //实际的数字
	{
		result3=sign;
		k++;
		if ((k%2) == 0)
		sign = s1[k/2];//下一位是数字 
		else
		sign = s2[(k-1)/2];//下一位是符号 
	}
	return result3;
}
