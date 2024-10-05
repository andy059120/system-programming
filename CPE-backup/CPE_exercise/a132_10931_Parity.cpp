#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, parity;
    while (cin >> n && n != 0)
    {
        int temp = n;
        string binary = "";
        parity = 0;
        while (temp != 0)
        {
            if (temp % 2 == 1)
            {
                parity++;
                binary += "1";
            }
            else
            {
                binary += "0";
            }
            temp /= 2;
        }
        reverse(binary.begin(), binary.end());
        cout << "The parity of " << binary << " is " << parity << " (mod 2).\n";
    }
    return 0;
}
