#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    const double PLAN_A_COST = 39.99;
    const double PLAN_B_COST = 59.99;
    const double PLAN_C_COST = 79.99;
    const double EXTRA_GB_COST = 8.00;

    const int PLAN_A_DATA = 2;
    const int PLAN_B_DATA = 8;

    string name;
    char plan;
    double gigabytes;
    double total = 0.0;

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter plan purchased (A, B, or C): ";
    cin >> plan;

    cout << "Enter gigabytes used: ";
    cin >> gigabytes;

    switch (plan)
    {
    case 'A':
    case 'a':
        total = PLAN_A_COST;

        if (gigabytes > PLAN_A_DATA)
        {
            total += (gigabytes - PLAN_A_DATA) * EXTRA_GB_COST;
        }
        break;

    case 'B':
    case 'b':
        total = PLAN_B_COST;

        if (gigabytes > PLAN_B_DATA)
        {
            total += (gigabytes - PLAN_B_DATA) * EXTRA_GB_COST;
        }
        break;

    case 'C':
    case 'c':
        total = PLAN_C_COST;
        break;

    default:
        cout << "Invalid plan selected." << endl;
        return 0;
    }


    cout << fixed << setprecision(2);
    cout << "\n----- Monthly Bill -----" << endl;
    cout << "Customer: " << name << endl;
    cout << "Plan: " << static_cast<char>(toupper(plan)) << endl;
    cout << "Gigabytes used: " << gigabytes << endl;
    cout << "Total due: $" << total << endl;


    if (plan == 'A' || plan == 'a')
    {
        double planBSavings = total - PLAN_B_COST;
        double planCSavings = total - PLAN_C_COST;

        if (planBSavings > 0)
        {
            cout << "You could save $" << planBSavings
                << " per month by switching to Plan B." << endl;
        }

        if (planCSavings > 0)
        {
            cout << "You could save $" << planCSavings
                << " per month by switching to Plan C." << endl;
        }
    }
    else if (plan == 'B' || plan == 'b')
    {
        double planCSavings = total - PLAN_C_COST;

        if (planCSavings > 0)
        {
            cout << "You could save $" << planCSavings
                << " per month by switching to Plan C." << endl;
        }
    }

    return 0;
}
