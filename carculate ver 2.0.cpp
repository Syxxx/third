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
int low();
int mid();
int high();
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
     int q=rand()%2;    //�м�������
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
	int result=0,answer;
	sign = s1[0]; /*�����һ������*/
	result=low(); /*���м���*/
	//printf("%d",result);
	cin>>answer;
	if (answer == result)
	{
		switch (lan)
		{
			case 1:cout<<"�ش���ȷ��";break;
			case 2:cout<<"Right!"; break;
		}
		count++;
	}
	else
	{
		switch (lan)
		{
			case 1:cout<<"�ش����";break;
			case 2:cout<<"Wrong!";break;
		}
	 } 	
}

void match( char nowsign ) //�Ե�ǰ�ı�־����ƥ��
{
if( sign == nowsign ) 
	{
		k++;
		if ((k%2) == 0)
		sign = s1[k/2];
		else
		sign = s2[(k-1)/2];//ƥ��ɹ�����ȡ��һ����־
	}

}

int low()//���ڼ�����ʽ�м�����͵�����
{
	int result = mid(); //����ȼӼ��������ȼ���ߵĲ���
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //���мӷ�����
		result += mid();
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //���м�������
		result -= mid(); 
		break;
	}
	return result;
}

int mid()//���ڼ�����ʽ�м���ϸߵ�����
{
	int div; //����ȼӼ��������ȼ���ߵĲ���
	int result = high();
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //���г˷�����
		result *= high();
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //���г�������
		result /= div; 
		break;
	}
	return result;
}


int high()//���ڼ�����ʽ�м�����ߵ����㣬��������������
{
	int result; 
	if( sign == '(' ) //�������ŵ�����
	{
		match( '(' );
		result = low();//�ݹ������ʽ
		match(')');
	}
	else if ( sign>= '0'&&sign<='9' ) //ʵ�ʵ�����
	{
		result=sign;
		k++;
		if ((k%2) == 0)
		sign = s1[k/2];
		else
		sign = s2[(k-1)/2];
	}
	return result;
}
