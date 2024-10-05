#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int up = 1, down = 6, east = 3, south = 2, west = 4, north = 5;
        while (n--) {
            string str;
            cin >> str;
            switch (str[0]) {
                case 'e': {
                    int temp = up;
                    up = east;
                    east = down;
                    down = west;
                    west = temp;
                    break;
                }
                case 's': {
                    int temp = up;
                    up = south;
                    south = down;
                    down = north;
                    north = temp;
                    break;
                }
                case 'w': {
                    int temp = up;
                    up = west;
                    west = down;
                    down = east;
                    east = temp;
                    break;
                }
                case 'n': {
                    int temp = up;
                    up = north;
                    north = down;
                    down = south;
                    south = temp;
                    break;
                }
            }
        }
        cout << up << endl;
    }
    return 0;
}

--------------------------------------------------------
FALSE code:

#include <iostream>
#include <string>
using namespace std;

struct dice {
    int value;
    dice* east;
    dice* south;
    dice* west;
    dice* north;
};

int main() {
    dice* one = new dice;
    dice* two = new dice;
    dice* three = new dice;
    dice* four = new dice;
    dice* five = new dice;
    dice* six = new dice;
    one->value = 1;
    two->value = 2;
    three->value = 3;
    four->value = 4;
    five->value = 5;
    six->value = 6;
    one->east = three;
    one->south = two;
    one->west = four;
    one->north = five;
    two->east = three;
    two->south = six;
    two->west = four;
    two->north = one;
    three->east = four;
    three->south = one;
    three->west = two;
    three->north = one;
    four->east = two;
    four->south = six;
    four->west = three;
    four->north = one;
    five->east = three;
    five->south = one;
    five->west = four;
    five->north = six;
    six->east = three;
    six->south = five;
    six->west = four;
    six->north = two;

    int n;
    while (cin >> n && n) {
        dice* ans = new dice;
        ans = one;
        while (n--) {
            string str;
            cin >> str;
            switch (str[0]) {
                case 'e': {
                    ans = ans->east;
                    break;
                }
                case 's': {
                    ans = ans->south;
                    break;
                }
                case 'w': {
                    ans = ans->west;
                    break;
                }
                case 'n': {
                    ans = ans->north;
                    break;
                }
            }
        }
        cout << ans->value << endl;
    }
    return 0;
}