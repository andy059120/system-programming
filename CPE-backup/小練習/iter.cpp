#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mostFrequentEven(vector<int>& nums) {
	sort(nums.rbegin(), nums.rend());
	int count = 0, maxCount = 0;
	int last = -1, ans = -1;
	nums.push_back(1);
	for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		if (count >= maxCount && ~last % 2) {
			maxCount = count;
			ans = last;
		}
		if (last != *iter) {
			count = 0;
		}
		if (~*iter % 2) {
			count++;
		}
		last = *iter;
	}
	return ans;
}

int main()
{
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	for (auto& i : vec) {
		cout << i << " ";
	}
	cout << "\n\n" << mostFrequentEven(vec);
	return 0;
}
