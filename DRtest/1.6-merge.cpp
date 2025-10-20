#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>& nums);

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    mergeSort(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

void mergeSort(vector<int>& nums)
{
    if (nums.size() > 1)
    {
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        mergeSort(left);
        mergeSort(right);
        merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
    }
}