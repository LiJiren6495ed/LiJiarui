#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//猜数字
int main()
{
    srand(time(0)); //设置随机种子

    int num = rand() % 100 + 1; //生成1到100之间的随机数
    int guess;
    int n = 1; //初始次数

    //第一次猜测
    cout << "===欢迎来到猜字游戏！===" << endl;
    cout << "请输入你的猜测：";
    cin >> guess;
    cout << endl;

    //二次及更多次猜测
    while (guess!= num) //直到猜对为止
    {
        if (guess > num) cout << "太大了！" << endl;
        if (guess < num) cout << "太小了！" << endl;
        cout << "请输入你的猜测：";
        cin >> guess;
        cout << endl;
        n++;
    }
    cout << "猜对了！" << endl;

    //胜利结算
    if (n == 1) cout << "一遍过，太帅了！" << endl;
    if (n < 7 && n > 1) cout << "你猜了" << n << "次，厉害了！" << endl;
    if (n >= 7) cout << "你猜了" << n << "次，通过！" << endl;
}