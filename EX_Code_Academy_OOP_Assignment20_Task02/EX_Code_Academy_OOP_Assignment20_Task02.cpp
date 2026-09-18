#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SecureBankAccount
{
private: //protect data
    string owner_name; //data
    long long balance = 0; //data
    std::vector<long long> transactionHistory; // to save transaction history
public:
    void setName(string owner) // safe name setter 
    {
        owner_name = owner;
    };
    void getName() // safe name getter
    {
        cout << owner_name << endl;
    };
    // Balance Guard
    void setBalance(long long Bal) //safe Balance setter
    {
        if (Bal < 0)
            //rejection if balance to be set is negative
        {
            cout << "You must input Balance Amount that is ";
            cout << "greater than 0" << endl;
            cout << "Exiting ... " << endl;
            return;
        }
        else if (balance != 0) 
            //rejection if there is an amount in the account already
        {
            cout << "Balance cannot be reset if there is an amount in it." << endl;
            cout << "Exiting ..." << endl;
            return;
        }
        else
        {
            balance = Bal;
            transactionHistory.push_back(balance); //to be added to transaction history
        }
    };

    void getBalance() // safe balance getter
    {
        cout << "Your Balance is $" <<  balance << " ." << endl;
    };

    //Deposits
    void depositInAccount(long long deposit)
    {
        if (deposit <= 0)
            //rejection if amount deposited is less than or equal to zero
        {
            cout << "Please try again and ";
            cout << "deposit an amount greater than zero" << endl;
            return;
        }
        else
        {
            balance += deposit;
            transactionHistory.push_back(deposit * +1); //to be added to transaction history
        }
    };
    //withdrawals
    void withdrawfromAccount(long long withdraw)
    {
        if (balance < withdraw) 
        //blocking if withdraw greater than the balance available in account
        //i.e. not enough money in the account.
        {
            cout << "The Balance available is lower than ";
            cout << "the amount you wish to withdraw." << endl;
            cout << "Please try again later." << endl;
            return;
        }
        else if (withdraw < 0) //blocking if withdraw amount is negative
        {
            cout << "You cannot withdraw a negative amount." << endl;
            cout << "Please try again with a positive amount." << endl;
            return;
        }
        else
        {
            balance -= withdraw;
            transactionHistory.push_back(withdraw * -1);
        }
    };
    
    void printTransactionHistory()
        //printing the transaction history vector
    {
        cout << "The Transction History is as follows:" << endl;
        for (auto it = transactionHistory.begin(); it != transactionHistory.end();
            it++)
        {
            cout << *it <<"$" << endl;
        }
    };
};

int main()
{
    SecureBankAccount Figma;
    Figma.setName("Amr Shaaban");
    // system test
    Figma.setBalance(500);
    Figma.depositInAccount(-100);
    Figma.withdrawfromAccount(600);
    Figma.withdrawfromAccount(200);
    cout << endl;
    Figma.getBalance();
    cout << endl;

    // even more system tests
    Figma.depositInAccount(600);
    Figma.withdrawfromAccount(500);
    Figma.depositInAccount(300);
    Figma.withdrawfromAccount(1000);
    Figma.withdrawfromAccount(-100);
    Figma.setBalance(600);
    Figma.depositInAccount(0);
    
    cout << endl;
    cout << endl;

    Figma.getName();
    Figma.getBalance();

    //printing the transaction history list
    Figma.printTransactionHistory();
    
}