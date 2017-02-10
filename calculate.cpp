#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;


void init();
void equation(int t);

int main(){
    init();
}

void init(){
     int q;
     srand((unsigned(time(NULL))));
     q=(rand()%3+3)*2+1;//一共多少位
     cout<<q<<endl;
     equation(q);

}

void equation(int t)
{
     char sign[4]={'+','-','*','/'};
     int a[(t+1)/2],num;
     char b[(t+1)/2],c;        //算式字符串
     //char *s=e;
     srand((unsigned(time(NULL))));
     for(int i=0;i<=(t+1)/2-1;i++)
     {
     	  num=rand()%11;
          a[i]=num;   // 数字
          c=sign[rand()%4];
          b[i]=c;//符号
     }
     b[(t+1)/2-1]='=';
     for (int i=0;i<=(t+1)/2-1;i++)
     {
     	printf("%d%c",a[i],b[i]);
	 }
}

