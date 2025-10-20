#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;

    // 获取需要排序的数字
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 1; i < a.size(); i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        // 插入temp到正确位置
        a[j + 1] = temp;
    }

    // 输出排序后的结果
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}