#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a << " " << b << " ";
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int maxCount = 0;
        for (int i = b; i <= a; i++)
        {
            int num = i, count = 1;
            while (true)
            {
                if (num == 1)
                {
                    break;
                }
                if (num % 2 == 0)
                {
                    num /= 2;
                }
                else
                {
                    num *= 3;
                    num++;
                }
                count++;
            }
            maxCount = max(maxCount, count);
        }
        cout << maxCount << endl;
    }
    return 0;
}

/*
1
2 1
3 10 5 16 8 4 2 1
4 2 1
5 16 8 4 2 1
6 3 10 5 16 8 4 2 1
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
8 4 2 1
9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
10 5 16 8 4 2 1
*/