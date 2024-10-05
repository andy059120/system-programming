#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr[50];
    cin>>n;
    while(n--){
        int a, ans = 0;
        cin>>a;
        for(int i = 0; i < a; i++){
            int num;
            cin>>num;
            arr[i] = num;
        }
        for(int i = 0; i < a-1; i++){
            for(int j = (i + 1); j < a; j++){
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    ans++;
                }
            }
        }
        cout << "Optimal train swapping takes " << ans << " swaps." << endl;
    }
    return 0;
}
