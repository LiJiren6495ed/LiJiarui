#include <iostream>
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

bool validInput(const string& str);
string removeSpaces(const string& str);
double calculate(const string& str);

int main() {
    string inputstr;
    
    while (true) {
        cout << "请输入数学表达式 (输入 'quit' 退出): ";
        getline(cin, inputstr);
        
        if (inputstr == "quit") break;
        
        string str = removeSpaces(inputstr);
        
        try {
            if (validInput(str)) {
                double result = calculate(str);
                cout << "结果: " << result << endl;
            } else {
                cout << "输入格式错误！" << endl;
            }
        } catch (const exception& e) {
            cout << "发生错误: " << e.what() << endl;
            cout << "请重新输入" << endl;
        }
    }
    
    return 0;
}

bool validInput(const string& str) {
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*\/-])\s*([-+]?\d*\.?\d+)\s*$)");
    return regex_match(str, pattern);
}

string removeSpaces(const string& str) {
    string result;
    for (char c : str) {
        if (c != ' ') result += c;
    }
    return result;
}

double calculate(const string& str) {
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*\/-])\s*([-+]?\d*\.?\d+)\s*$)");
    smatch match;
    
    if (!regex_search(str, match, pattern) || match.size() < 4) {
        throw runtime_error("无法解析数学表达式");
    }
    
    try {
        double num1 = stod(match[1]);
        char op = match[2].str()[0];
        double num2 = stod(match[3]);
        double result = 0;
        
        cout << "计算: " << num1 << " " << op << " " << num2 << endl;
        
        switch (op) {
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
                if (num2 == 0) {
                    throw runtime_error("除数不能为零");
                }
                result = num1 / num2;
                break;
            default:
                throw runtime_error("未知运算符: " + string(1, op));
        }
        
        return result;
        
    } catch (const invalid_argument& e) {
        throw runtime_error("数字格式错误: " + string(e.what()));
    } catch (const out_of_range& e) {
        throw runtime_error("数字超出范围: " + string(e.what()));
    }
}