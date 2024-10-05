#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> arr;
    string str;
    int a;
    cin >> a;
    cin.ignore(10, '\n');
    while (a--) {
        cin >> str;
        arr[str]++;
        string temp;
        getline(cin, temp);
    }
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}