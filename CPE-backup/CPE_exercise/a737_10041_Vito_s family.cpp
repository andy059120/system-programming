#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    int a, x, y;
    cin >> a;
    while (a--)
    {
        cin >> x;
        int ans = 0;
        vec.clear();
        for (int i = 0; i < x; i++)
        {
            cin >> y;
            vec.push_back(y);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < x; i++)
        {
            ans += abs(vec.at(i) - vec.at(vec.size() / 2));
        }
        cout << ans << endl;
    }
    return 0;
}