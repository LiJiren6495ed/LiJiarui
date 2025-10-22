#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

bool validInput(string str);
string removeSpaces(string str);
double calculate(string str);

int main()
{
    string inputstr;
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)");
    smatch match;
    vector<string> tokens;

    while (true)
    {
    cout << "请输入算术表达式：";
    getline(cin, inputstr);
    string str = removeSpaces(inputstr);
    // 进行匹配，匹配后将字符出啊各部分保存在向量里方便调用
    if (regex_search(str, match, pattern))
    {
        string num1 = match[1];
        string op = match[2];
        string num2 = match[3];
        tokens.push_back(num1);
        tokens.push_back(op);
        tokens.push_back(num2);
    }
    try
    {
        double result = calculate(str);
        cout << "结果：" << tokens[0] << " " << tokens[1] << " " << tokens[2] << " = " << result << endl;
    }
    catch (const exception& e)
    {
        cout << "错误：" << e.what() << endl; // 返回错误信息
        cout << "请重新输入！" << endl;
    }
    }
}

// 检测输入是否有效
bool validInput(string str)
{
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)");
    
    return regex_match(str, pattern);
}

// 移除空格统一字符串格式
string removeSpaces(string str)
{
    string result = "";
    for (char c : str)
    {
        if (c != ' ') result += c;
    }
    return result;
}

// 计算函数
double calculate(string str)
{
    string input;
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)");
    smatch match;
    if (!(validInput(str) && regex_search(str, match, pattern)))
    {
        throw invalid_argument("输入格式错误！");
    }
        
    // 计算同时进行异常处理
    try
    {
    double num1 = stod(match[1]);
    char op = match[2].str()[0];
    double num2 = stod(match[3]);
    double result = 0;
    switch (op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                throw invalid_argument("除数不能为零！");
            }
            result = num1 / num2;
            break;
        default:
            throw invalid_argument("错误：未知运算符!");
    }
    return result;
    }
    catch (const exception& e)
    {
        throw;
    }
}