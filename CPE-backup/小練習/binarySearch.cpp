#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size() - 1;
	while (low <= high) {
		int mid = int((low + high) / 2);
		if (target == nums[mid])
			return mid;
		else if (target > nums[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

int main()
{
	vector<int> vec = { 1, 3, 5 ,6 };
	int key = 7;

	for (auto& i : vec) {
		cout << i << " ";
	}
	cout << "\n" << searchInsert(vec, key);
	return 0;
}
