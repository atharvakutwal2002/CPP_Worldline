#include <iostream>

using namespace std;

namespace Calculator
{
    enum Operation
    {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION
    };

    double performOperation(double num1, double num2, Operation op)
    {
        switch (op)
        {
        case ADDITION:
            return num1 + num2;
        case SUBTRACTION:
            return num1 - num2;
        case MULTIPLICATION:
            return num1 * num2;
        case DIVISION:
            if (num2 != 0)
            {
                return num1 / num2;
            }
            else
            {
                cerr << "Error: Division by zero!" << endl;
                return 0.0;
            }
        }
    }
}

    int
    main()
{
    int userCh = 1;
    while (userCh == 1)
    {
        cout << "Enter 1 for calculation and 0 to exit " << endl;
        cin >> userCh;
        if (userCh != 1)
            break;
        double num1, num2;
        char opSymbol;
        Calculator::Operation op;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose operation (+, -, *, /): ";
        cin >> opSymbol;

        switch (opSymbol)
        {
        case '+':
            op = Calculator::ADDITION;
            break;
        case '-':
            op = Calculator::SUBTRACTION;
            break;
        case '*':
            op = Calculator::MULTIPLICATION;
            break;
        case '/':
            op = Calculator::DIVISION;
            break;
        default:
            cerr << "Invalid operation!" << endl;
            return 1;
        }

        cout << "Result: " << Calculator::performOperation(num1, num2, op) << endl;
        cout << "==================================================================" << endl;
    }

    return 0;
}
