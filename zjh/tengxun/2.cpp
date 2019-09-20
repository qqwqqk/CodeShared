#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
    int y,m,d;
    cin>>y>>m>>d;

    bool isRunY=false;

    if(y%100==0){//世纪年
        if(y%400==0){
            isRunY=true;
        }
    }
    if(y%4==0&&y%100!=0){
        isRunY=true;
    }

    cout<<y<<"-";
    if(m==1||m==3||m==5||m==7||m==8||m==12){//31
        cout<<m<<"-"<<d<<endl;cout<<"1"<<endl;
    }else if(m==4||m==6||m==9||m==10||m==11){
        if(d==31){
            d=1;
            cout<<m+1<<"-"<<d<<endl;
        }else{
            cout<<m<<"-"<<d<<endl;
        }
    }else{
        if(isRunY==true){
            if(d>29){
                cout<<m+1<<"-"<<d-29<<endl;
            }else{
                cout<<m<<"-"<<d<<endl;
            }
        }else{
            if(d>28){
                cout<<m+1<<"-"<<28-d<<endl;
            }else{
                cout<<m<<"-"<<d<<endl;
            }
        }
    }

    return 0;
}