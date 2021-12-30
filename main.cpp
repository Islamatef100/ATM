#include <iostream>
#include"history.h"
using namespace std;
int main( )
{
    user_accounts islam;
   // islam.view_history_of_account();
    while(1)
    {
        int choose;
        cout<<"1-creat account\n"
        <<"2-inquiry account\n"
        <<"3-withdraw\n"
        <<"4-deposit\n"
        <<"5-exist or not\n"
        <<"6-viw history of account:\n"
        <<"7-exit\n";
        cin>>choose;
        if(choose==1)
            islam.creat_account();
        else if(choose==2)
            islam.inquiry_about_account();
        else if(choose==3)
            islam.withdraw();
        else if(choose==4)
            islam.deposit();
        else if(choose==5)
            cout<<islam.exist()<<endl;
        else if(choose==6)
            islam.view_history_of_account();
        else if(choose==7)
            return 0;
            
    }
   
}













































