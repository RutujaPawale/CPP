#include<iostream>
using namespace std;

int main()
{
    int marks[4]={23,45,78,94};
    cout<<marks[0]<<endl;
    int mathmarks[4]={53,68,24,48};
    mathmarks[1]=99;
    cout<<mathmarks[1]<<endl;

    int* p=marks;
    cout<<"Marks:"<<*p<<endl;
    cout<<"Marks:"<<*(p+1)<<endl;
    cout<<"Marks:"<<*(p+2)<<endl;
    cout<<"Marks:"<<*(p+3)<<endl;
}
