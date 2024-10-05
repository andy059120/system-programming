#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    while (cin >> num && num != "0")
    {
        string num1 = "";
        string num2 = "";
        int num1Value = 0;
        int num2Value = 0;
        for (int i = 0; i < num.length(); i++)
        {
            if (!(i % 2))
            {
                num1 += num[i];
            }
            else
            {
                num2 += num[i];
            }
        }
        for (int i = 0; i < num1.length(); i++)
        {
            num1Value += (num1[i] - 48);
        }
        for (int i = 0; i < num2.length(); i++)
        {
            num2Value += (num2[i] - 48);
        }
        if (!(num1Value - num2Value) || !((abs(num1Value - num2Value)) % 11))
        {
            cout << num << " is a multiple of 11." << endl;
        }
        else
        {
            cout << num << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}