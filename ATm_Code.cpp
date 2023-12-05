#include<bits/stdc++.h>
using namespace std;
class amount
{
    int accno,balance,credit,withdraw;
    char name[100];
    public:
    void search(int);
    void input();
    void output();
};

int main()
{
    int i,accno,credit,withdraw,balance;
    amount x[2];
    for(i=0;i<2;i++)
    {
        x[i].input();
    }
    int r;
    cout<<"Enter your account no. to get your account details"<<endl;
    cin>>r;
    for(i=0;i<2;i++)
    {
        x[i].search(r);
    }
    return 0;
}

void amount::input()
{
    cout<<"Enter name"<<endl;
    cin>>name;
    cout<<"Enter account number"<<endl;
    cin>>accno;
    cout<<"Enter balance"<<endl;
    cin>>balance;
}

void amount::search(int r)
{
    if(accno==r)
    {
        int choice;
        cout<<"\n1.Credit\n2.Withdraw";
        cout<<"\n Enter the choice";
        cin>>choice;

    switch(choice)
    {
        case 1:
                cout<<"Amount to be credit"<<endl;
                cin>>credit;
                balance=balance+credit;                
                break;
        case 2:
                cout<<"Amount to be withdraw"<<endl;
                cin>>withdraw;
                balance=balance-withdraw;
                break;
        default:
                cout<<"Invalid input";

    }
    output();
    }
}

void amount::output()
{
    cout<<"\n"<<"Account holder: "<<name<<"\n"<<"Account number: "<<accno<<"\n"<<"Current Balance: "<<balance;
}
