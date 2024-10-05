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
        getline(cin, str);
        if (str[0] == 's') {
            arr[str]++;
        } else {
            arr[str] += 7;
        }
    }
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << "iter.first: " << iter->first << "    iter.second: " << iter->second << endl;
    }
    cout << endl;
    for (auto& n : arr) {
        cout << "n.first: " << n.first << "    n.second: " << n.second << endl;
    }
    return 0;
}