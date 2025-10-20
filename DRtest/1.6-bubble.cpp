#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "输入数组长度: ";
    cin >> n;
    vector<int> a;

    // 获取需要排序的数字
    cout << "输入数组元素: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    //冒泡排序
    for (int i = 0; i < a.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < a.size() - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    // 输出排序后的结果
    cout << "排序后的数组: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}