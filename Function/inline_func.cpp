#include<iostream>
using namespace std;

inline int product(int a,int b)
{
    static int c=0;
    c=c+1;
    return a*b;
}

int main()
{
    int num1, num2;
    cout<<"Enter first number:"<<endl;
    cin>>num1;
    cout<<"Enter second number:"<<endl;
    cin>>num2;
    cout<<"Product is:"<<product(num1,num2);
    return 0;
}
