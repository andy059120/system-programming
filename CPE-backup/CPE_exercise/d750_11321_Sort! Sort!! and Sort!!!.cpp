#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b) {
        cout << a << " " << b << endl;
        if (a == 0 && b == 0) {
            break;
        }
        int index = -10000;
        vector<int> vec, subVec;
        while (a--) {
            cin >> n;
            vec.push_back(n);
        }
        while (b != index) {
            for (auto& v : vec) {
                if (v % b == index) {
                    subVec.push_back(v);
                }
            }
            sort(subVec.begin(), subVec.end());
            for (auto iter = (subVec.end() - 1); iter != (subVec.begin() - 1); iter--) {
                if (*iter % 2) {
                    cout << *iter << endl;
                }
            }
            for (auto& v : subVec) {
                if (!(v % 2)) {
                    cout << v << endl;
                }
            }
            subVec.clear();
            index++;
        }
    }
    return 0;
}
//not accepted in codeforces