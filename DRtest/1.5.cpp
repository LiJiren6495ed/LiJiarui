#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

bool validInput(string str);
string removeSpaces(string str);
double calculate(string str);

int main()
{
    string inputstr;

    while (true)
    {
    cout << "请输入算术表达式：";
    getline(cin, inputstr);
    string str = removeSpaces(inputstr);
    try
    {
        double result = calculate(str);
        cout << "结果：" << result << endl;
    }
    catch (const exception& e)
    {
        cout << "错误：" << e.what() << endl;
        cout << "请重新输入！" << endl;
    }
    }
}

bool validInput(string str)
{
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)");
    
    return regex_match(str, pattern);
}

string removeSpaces(string str)
{
    string result = "";
    for (char c : str)
    {
        if (c != ' ') result += c;
    }
    return result;
}

double calculate(string str)
{
    string input;
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)");
    smatch match;
    if (!(validInput(str) && regex_search(str, match, pattern)))
    {
        throw invalid_argument("输入格式错误！");
    }
        
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