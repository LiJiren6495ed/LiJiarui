#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& arr, int left, int right);

int main()
{
    int n;
    cout << "输入数组长度: ";
    cin >> n;
    vector<int> nums;
    cout << "输入数组元素: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    QuickSort(nums, 0, n - 1);

    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

void QuickSort(vector<int>& arr, int left, int right)
{
    if (left >= right) return;
    int pivot = arr[(left + right) / 2]; // 设置基准值
    int i = left, j = right; // 建立指针

    // 指针如果不交叉，就一直移动检索
    while (i <= j)
    {
        // 左指针向右移动，直到遇到大于基准值的元素
        while (arr[i] < pivot) i++;
        // 右指针向左移动，直到遇到小于基准值的元素
        while (arr[j] > pivot) j--;
        // 如果左指针小于等于右指针，交换元素，指针向中间移动
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    // 递归左右子数组
    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}