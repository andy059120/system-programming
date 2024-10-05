#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (cin >> str && str != "0")
    {
        // normal print
        for (int i = 0; i < str.length(); i++)
        {
            cout << str[i] << " ";
        }
        cout << endl;

        // print with iterator
        for (auto iter = str.begin(); iter != str.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;

        // print with memory address
        for (auto &s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}