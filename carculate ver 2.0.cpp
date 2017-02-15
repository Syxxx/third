/*4-6�����֣�5���������,0-3������
  �ĸ�����4+3=7λ�ַ��� 6+5=11λ�ַ���*/
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
	cout<<"��ѡ������(Please choose language)"<<endl;cout<<"1.���� 2.English �� ";
	cin>>lan;
	switch(lan)
	{
		case 1:cout<<"������������";cin>>n;break;
		case 2:cout<<"Please enter a number of questions��";cin>>n;break;
		defaul:cout<<"Error!";break; 
	}
	for (int j=0;j<n;j++)
	{
		  init();
		  cout<<endl;
	}
	switch(lan)
	{
		case 1:cout<<"��ȷ������"<<count<<" ����������"<<n-count;break;
		case 2:cout<<"Correct questions:"<<count<<" Wrong questions:"<<n-count;break; 
	}
    return 0;
}

void init(){
     int q;
     q=rand()%3+4;   //����һ������λ
     equation(q);
}
 
void equation(int t) //������ʽ 
{
     char a[]="+-*/";//{'+','*','-','/'};
     int e[20];
	 char q[20];       //��ʽ�ַ���

     for(int i=0;i<t;i++)
     {
          e[i]=rand()%8+1;    // ����
          q[i]=a[rand()%4]; //����
     }
     q[t-1]='=';
     bracket(e,q,t-1);//ע�����ﴫ����t-1���β�ֻ��һ��t 
}

void bracket(int m[],char n[],int t){   //�������
     int q=0;//rand()%2;    //�м�������
     if(q==1)
     {
        int a=rand()%(t/2)+1;
        int b=a+rand()%(t/2)+2;//�ֱ��ڵڼ����������� 
 //a+1�ǵ�һ�����ŵ�λ�ã�b�ǵڶ������ŵ�λ��
          for(int i=0;i<=t;i++) //������ʽ
          {
          if(i==a) cout<<"(";
		  cout<<m[i];
		  if(i==b-1) cout<<")";
		  if (n[i]=='/')
			cout<<"��";
		  else
		    cout<<n[i];
          }
     }
     if(q==0)
     {
     	for (int i=0;i<t+1;i++)
     	{
     		if (n[i]=='/')
     		cout<<m[i]<<"��";
     		else
     		cout<<m[i]<<n[i];
		}
		for (int i=0;i<t+1;i++)
     	{
     		s1[i]=m[i];  //���� 
     		s2[i]=n[i];  //���� 
		}
		check();	
	 }
}

void check ()
{
	double result;
	sign = s1[0]; /*�����һ������*/
	result=low(); /*���м���*/
	cout<<result;
}
 
void match( char nowsign ) //�Ե�ǰ�ı�־����ƥ��
{
if( sign == nowsign ) //ƥ��ɹ�����ȡ��һ����־
	{
		k++;
		if ((k%2) == 0) //��һλ������ 
		sign = s1[k/2];
		else    //��һλ�Ƿ��� 
		sign = s2[(k-1)/2];
	}
}

double low() //���ڼ�����ʽ�м�����͵�����
{
	double result1 = mid(); //����ȼӼ��������ȼ���ߵĲ���
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //���мӷ�����
		result1 += mid();
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //���м�������
		result1 -= mid(); 
		break;
	}
	return result1;
}

double mid() //���ڼ�����ʽ�м���ϸߵ�����
{
	double result2 = high();
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //���г˷�����
		result2 *= high();
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //���г�������
		result2 /= high(); 
		break;
	}
	return result2;
}


double high() //���ڼ�����ʽ�м�����ߵ����㣬��������������
{
	double result3; 
	if( sign == '(' ) //�������ŵ�����
	{
		match( '(' );
		result3 = low(); //�ݹ������ʽ
		match(')');
	}
	else if (sign >= 0 && sign<= 9) //ʵ�ʵ�����
	{
		result3=sign;
		k++;
		if ((k%2) == 0)
		sign = s1[k/2];//��һλ������ 
		else
		sign = s2[(k-1)/2];//��һλ�Ƿ��� 
	}
	return result3;
}
