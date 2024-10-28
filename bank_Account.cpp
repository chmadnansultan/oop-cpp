#include <iostream>
using namespace std;

class bank
{
private:
    double balance;
    double transactions;

public:
    bank(double);
    void setbalance(double);
    void setwithdraw(double);
    double getbalance();
    double gettransection();

    static int satVariable;
};

bank::bank(double value = 0)
{
    cout << "constuctor 1 is calling " << endl;
    cout << "Default Value set to balance" << endl;
    balance = value;
    transactions = value;
}
int bank::satVariable = 500;
void bank::setbalance(double makeDeposit)
{
    if (makeDeposit > 0)
    {
        balance = balance + makeDeposit;
        cout << "\nDeposit money successfully " << endl;
        transactions++;
    }
    else
    {
        cout << "negative value not allowed" << endl;
    }
}
void bank::setwithdraw(double withdraw)
{
    if (withdraw <= balance && balance > 0)
    {
        balance = balance - withdraw;
        cout << "\nWithdraw money successfully " << endl;
        transactions++;
    }
    else
    {
        cout << "withdraw money is greater than balance " << endl;
    }
}
double bank::getbalance()
{
    return balance;
}
double bank::gettransection()
{
    return transactions;
}
int main()
{
    bank obj1;
    // cout << obj1.balance2;
    cout << bank::satVariable;
    cout << "     ";
    double makeDeposit, withdraw;
    int choice;
    do
    {
        cout << "BANK ACCOUNT " << endl;
        cout << "1. Make Deposit " << endl;
        cout << "2. With Draw Money " << endl;
        cout << "3. Check Balance " << endl;
        cout << "4. Total Transections " << endl;
        cout << "5. EXIT " << endl;
        cout << "\n Enter Choice " << endl;
        cout << "-----------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter the value : ";
            cin >> makeDeposit;
            obj1.setbalance(makeDeposit);
        }
        break;
        case 2:
        {
            cout << "\nenter value to withdraw form account : ";
            cin >> withdraw;
            obj1.setwithdraw(withdraw);
        }
        break;
        case 3:
        {
            cout << "\nThe balance is : " << obj1.getbalance() << endl;
        }
        break;
        case 4:
        {
            cout << "your total Transections are : " << obj1.gettransection() << endl;
        }
        break;
        case 5:
        {
            cout << "Program END.." << endl;
            cout << "------------------------------" << endl;
        }
        break;
        default:
        {
            cout << "invalid choice " << endl;
        }
        break;
        }
    } while (choice != 5);

    return 0;
}