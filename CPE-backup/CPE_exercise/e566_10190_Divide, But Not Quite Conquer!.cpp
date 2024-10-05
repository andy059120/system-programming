#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a < 2 || b < 2)
        {
            cout << "Boring!" << endl;
            continue;
        }
        int num = a;
        while (!(num % b) && num > 1)
        {
            num /= b;
        }
        if (num != 1)
        {
            cout << "Boring!" << endl;
        }
        else
        {
            while (a != 1)
            {
                cout << a << " ";
                a /= b;
            }
            cout << 1 << endl;
        }
    }
    return 0;
}
//not accepted in codeforces