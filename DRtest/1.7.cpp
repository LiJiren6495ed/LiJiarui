#include <iostream>
#include <stdexcept>
using namespace std;

void Fibolacci(unsigned int k);

int main(void)
{
    unsigned int k;
    cout << "你需要数列的前几项？" << endl;
    cin >> k;

    if (k > 40) throw invalid_argument("输入的数太大！");
    if (k < 1) throw invalid_argument("输入的数太小！");

    Fibolacci(k);
    return 0;
}

void Fibolacci(unsigned int k)
{
    int a = 1 , b = 1;
    // 处理特殊情况
    if (k == 1)
    {
        cout << "1" << endl;
    }
    else if (k == 2)
    {
        cout << "1" << endl << "1" << endl;
    }
    // 正常情况
    else
    {
        cout << "1" << endl << "1" << endl;
        for (int i = 3; i <= k; i++)
        {
            int next = a + b;
            a = b;
            b = next;
            cout << b << endl;
        }
    }
    // 稍微有些硬编码，但是我也没有想到很好的解决方法
}