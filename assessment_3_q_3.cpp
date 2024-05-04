#include <iostream>

using namespace std;

double calculateElectricityBill(double units)
{
    double bill = 0.0;
    auto cmp = units <=> 50;
    if (cmp <= 0)
    {
        bill = units * 0.50;
    }
    else
    {
        cmp = units <=> 150;
        if (cmp <= 0)
        {
            bill = 50 * 0.50 + (units - 50) * 0.75;
        }
        else
        {
            cmp = units <=> 250;
            if (cmp <= 0)
            {
                bill = 50 * 0.50 + 100 * 0.75 + (units - 150) * 1.20;
            }
            else
            {
                bill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
            }
        }
    }

    bill *= 1.20;

    return bill;
}

int main()
{
    double units;
    cout << "Enter the number of units consumed: ";
    cin >> units;

    double totalBill = calculateElectricityBill(units);

    cout << "Total electricity bill: Rs. " << totalBill << endl;

    return 0;
}
