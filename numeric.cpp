
#include<iostream>
#include<math.h>
using namespace std;



int main()
{
    float X[20],Y[20] ,a,b,sumx=0,sumy=0,sumxx=0,sumxy=0;
    int n,i;

    cout<<"number of data point:"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
      cout<<"input x :  ";
      cin>>X[i];
      cout<<"and y value: ";
      cin>>Y[i];

     sumx=sumx+X[i];
     sumy=sumy+Y[i];
     sumxx=sumxx+(X[i]*X[i]);
     sumxy=sumxy+(X[i]*Y[i]);

    }
  cout<<"summation of x value:"<<sumx<<endl;
  cout<<"summation of y value:"<<sumy<<endl;
  cout<<"summation of xx value:"<<sumxx<<endl;
  cout<<"summation of xy value:"<<sumxy<<endl;

 b=((n*sumxy-sumx*sumy)/(n*sumxx-(sumx*sumx)));

 a=((sumy/n)-(b*(sumx/n)));
 cout<<"value of b is:"<<b<<endl;
 cout<<"value of a is:"<<a<<endl;
 cout<<"straight line:  f(x)="<<b<<"x+"<<a;

    return 0;
}

