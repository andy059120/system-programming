#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        string str = "", ans;
        int num;
        cin >> num;
        if( num == 1 ) {
            cout << "1" << endl;
            continue;
        }
        for(int i = 9; i > 0; i--){
            if(!(num%9)) {
                str += "9";
                num /= 9;
            }
            if(!(num%8)) {
                str += "8";
                num /= 8;
            }
            if(!(num%7)) {
                str += "7";
                num /= 7;
            }
            if(!(num%6)) {
                str += "6";
                num /= 6;
            }
            if(!(num%5)) {
                str += "5";
                num /= 5;
            }
            if(!(num%4)) {
                str += "4";
                num /= 4;
            }
            if(!(num%3)) {
                str += "3";
                num /= 3;
            }
            if(!(num%2)) {
                str += "2";
                num /= 2;
            }
        }
        if(num > 1) {
            cout << "-1" << endl;
        } else {
            for(int i = (str.length() - 1); i >= 0; i--) {
                ans += str[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
