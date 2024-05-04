#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    BankAccount(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->balance = 0;
    }

    void getAccountDetails()
    {
        cout << "============================================================" << endl;
        cout << "Your account details are:\n";
        cout << " Name --> " << this->name << "\n";
        cout << " Age --> " << this->age << "\n";
        cout << " Account balance --> " << this->balance << endl;
        cout << "============================================================" << endl;
    }

    void getBalance()
    {
        cout << "============================================================" << endl;
        cout << "Your account balance is " << balance << endl;
        cout << "============================================================" << endl;
    }

    void depositAmount(int amt)
    {
        if (amt < 0)
        {
            cout << "============================================================" << endl;
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
            cout << "============================================================" << endl;
            return;
        }

        this->balance += amt;
        cout << "============================================================" << endl;
        cout << "Account balance after depositing amount is " << this->balance << endl;
        cout << "============================================================" << endl;
    }

    void withdrawAmount(int amt)
    {
        if (balance < amt)
        {
            cout << "============================================================" << endl;
            cout << "Insufficient balance for withdrawal." << endl;
            cout << "============================================================" << endl;
            return;
        }

        this->balance -= amt;
        cout << "============================================================" << endl;
        cout << "Account balance after withdrawal is " << this->balance << endl;
        cout << "============================================================" << endl;
    }

private:
    int balance;
    string name;
    int age;
};

int main()
{
    BankAccount *b1;

    while (true)
    {
        int ch;
        cout << "============================================================" << endl;
        cout << "Enter your choice:\n";
        cout << " 1. Create account\n";
        cout << " 2. Get account details\n";
        cout << " 3. Deposit amount\n";
        cout << " 4. Get balance\n";
        cout << " 5. Withdraw amount\n";
        cout << " 6. Exit\n";
        cout << "============================================================" << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            string name;
            int age;
            cout << "Enter account holder's name: ";
            cin >> name;
            cout << "Enter account holder's age: ";
            cin >> age;
            b1 = new BankAccount(name, age);
            break;
        }
        case 2:
            if (b1 != nullptr)
            {
                b1->getAccountDetails();
            }
            else
            {
                cout << "No account created yet.\n";
            }
            break;
        case 3:
            if (b1 != nullptr)
            {
                int amt;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                b1->depositAmount(amt);
            }
            else
            {
                cout << "No account created yet.\n";
            }
            break;
        case 4:
            if (b1 != nullptr)
            {
                b1->getBalance();
            }
            else
            {
                cout << "No account created yet.\n";
            }
            break;
        case 5:
            if (b1 != nullptr)
            {
                int amt;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                b1->withdrawAmount(amt);
            }
            else
            {
                cout << "No account created yet.\n";
            }
            break;
        case 6:
            delete b1;
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
