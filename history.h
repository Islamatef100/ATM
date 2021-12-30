//-------------ATM--------------
#include <iostream>
//#include<history.h>
#include <ctime>
using namespace std;
struct node
{
    string type_of_operation;
    double money;
    string day;
    float time;
    node*next;
    int atm_number;
};
class account_operation
{
private:
    node*head;
    node*temp;
public:
    account_operation()
    {
        head=nullptr;
    }
    void add(double mony,int atmnumber,string day,int time,string type)
    {
        node*newnode=new node;
        newnode->money=mony;
        newnode->day=day;
        newnode->time=time;
        newnode->atm_number=atmnumber;
        newnode->type_of_operation=type;
        if (head==nullptr)
            head=newnode;
        else
            temp->next=newnode;
        temp=newnode;
      
    }
    void print()
    {
        //this method by while
        node*temp=head;
        while(temp!=nullptr)
        {
            cout<<"---------------------------------------------------------------------\n";
            cout<<"day:"<<temp->day<<endl;
            cout<<"time"<<temp->time<<endl;
            cout<<"ATM Number:"<<temp->atm_number<<endl;
            cout<<"type of operation:"<<temp->type_of_operation<<endl;
            cout<<"the money:"<<temp->money<<endl;
            cout<<"---------------------------------------------------------------------\n";
            temp=temp->next;
        }
    }
};

class user_accounts:public account_operation
{
private:
    bool client;
    double user_ID;
    string user_name;
    double number_cridit_card;
    double user_money;
    char password[4];
public:
    user_accounts()
    {
        user_ID=0;
        user_name="";
        user_money=0;
        client=false;
        number_cridit_card=0;
    }
    bool exist()
    {
        if(client==false)
            return false;
        else
            return true;
    }
    void creat_account()
    {
        client=true;
        user_money=0;
        cout<<"entre yoyr name:";
        cin>>user_name;
        cout<<"enter your password:";
        cin>>password[0]>>password[1]>>password[2]>>password[3];
        cout<<"enter your ID:";
        cin>>user_ID;
        cout<<"enter number of cridit card:";
        cin>>number_cridit_card;
    }
   void deposit()
    {
        if(exist())
        {
            int money;
            cout<<"How much mony:";
            cin>>money;
            user_money+=money;
            cout<<"operation completed successfully\n";
            add(money, 123, "tusday", 12, "deposit");//123 is any number i write it for atm number.
        }
          else
          {
              int choose;
              cout<<"You have not account create account and try again:\n";
              cout<<"1-creat account\n"
                  <<"2-exist\n";
              cin>>choose;
              if(choose==1)
              {
                  creat_account();
                   deposit();
                  
              }
              else
                  return;
          }
    }
   void withdraw()
    {
        if(exist())
        {
                int money;
                cout<<"How Much Money?:";
                cin>>money;
                if(money<=user_money)
                {
                    user_money-=money;
                    cout<<"operation completed successfully\n";
                    add(money, 123, "tusday", 12, "withdaw");//123 is any number i write it for atm number.
                }
                else
                {
                    int choose;
                    cout<<"yoy have not this money you have only "<<user_money<<endl;
                    cout<<"1-Do you want do that again? 2-or not:";
                    cin>>choose;
                    if(choose==1)
                        withdraw();
                }
        }
        else
            {
                    int choose;
                    cout<<"You have not account create account and try again:\n";
                    cout<<"1-creat account\n"
                        <<"2-exist\n";
                    cin>>choose;
                    if(choose==1)
                    {
                        creat_account();
                        withdraw();
                    }
            }
        }
    void inquiry_about_account()
    {
        if(exist())
        {
            cout<<"your money is:"<<user_money<<endl;
        }
        else
        {
            cout<<"you have not any account:";
        }
    }
    void view_history_of_account()
    {
        print();
    }
};
