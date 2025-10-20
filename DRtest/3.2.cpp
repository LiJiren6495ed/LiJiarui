#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

// 模板函数，两个参数分别代表获取的输出和输入类型
template<typename T1, typename T2>
void computeOperation(T1& result, const string& formula)
{
    // 解析逻辑
    regex pattern(R"(([-+]?\d*\.?\d+)\s*([+*/-])\s*([-+]?\d*\.?\d+)\s*$)"); // 正则表达式
    smatch match;
    
    if(regex_search(formula, match, pattern))
    {
        T2 a = stod(match[1]);
        char op = match[2].str()[0];
        T2 b = stod(match[3]);
        
        // 运算逻辑
        switch(op)
        {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: throw invalid_argument("无效的运算");
        }
        
        cout << a << " " << op << " " << b << " = " << result << endl;
    }
}

int main()
{
    string formula;
    double result;
    cout << "请输入公式：";
    getline(cin, formula);

    // 调用模板函数
    cout << "计算结果：";
    computeOperation<double, double>(result, formula);
    return 0;
}


