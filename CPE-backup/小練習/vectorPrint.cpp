#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vec;
    string str;
    while (cin >> str && str != "0")
    {
        //這邊只塞入一個str
        vec.push_back(str);

        // normal print
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec.at(i) << " ";
        }
        cout << endl;

        // print with iterator
        for (auto iter = vec.begin(); iter != vec.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;

        // print with memory address
        for (auto &v : vec)
        {
            cout << v << " ";
        }
        cout << endl;

        vec.clear();
    }
    return 0;
}