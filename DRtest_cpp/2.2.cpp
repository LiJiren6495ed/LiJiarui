#include <algorithm>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

class Complex
{
    private:
        double real, imag;
    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {} // 构造函数
        Complex(const Complex& other) : real(other.real), imag(other.imag) {} // 拷贝构造函数
        double getReal() const { return real; } // 获取实部
        double getImag() const { return imag; } // 获取虚部
        friend ostream& operator<<(ostream& os, const Complex& c) // 输出流运算符重载
        {
            os << c.real << (c.imag >= 0? "+" : "") << c.imag << "i";
            return os;
        }
        // 两次获取输入都使用了getline，所以没有再进行输入流运算符重载
        // 重载加法运算符
        Complex operator+(const Complex& other) const
        {
            return Complex(real + other.real, imag + other.imag);
        }
        // 重载减法运算符
        Complex operator-(const Complex& other) const
        {
            return Complex(real - other.real, imag - other.imag);
        }
        // 重载乘法运算符
        Complex operator*(const Complex& other) const
        {
            return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }
        // 重载除法运算符
        Complex operator/(const Complex& other) const
        {
            double denominator = other.real * other.real + other.imag * other.imag;
            if (denominator == 0) throw invalid_argument("除数为0了！");
            return Complex((real * other.real + imag * other.imag) / denominator,
                           (imag * other.real - real * other.imag) / denominator);
        }
};

Complex getComplex(string formula);

int main()
{
    string oFormula1;
    cout << "请输入第一个复数：" << endl;
    getline(cin, oFormula1);
    oFormula1.erase(remove(oFormula1.begin(), oFormula1.end(), ' '), oFormula1.end()); // 去除空格
    Complex c1 = getComplex(oFormula1);
    
    string oFormula2;
    cout << "请输入第二个复数：" << endl;
    getline(cin, oFormula2);
    oFormula2.erase(remove(oFormula2.begin(), oFormula2.end(), ' '), oFormula2.end()); // 去除空格
    Complex c2 = getComplex(oFormula2);

    cout << "相加：" << c1 + c2 << endl;
    cout << "相减：" << c1 - c2 << endl;
    cout << "相乘：" << c1 * c2 << endl;
    cout << "相除：" << c1 / c2 << endl;

    return 0;
}

Complex getComplex(string formula)
{
    regex pattern(R"(([+-]?\d*\.?\d*)i
                    |([+-]?\d*\.?\d*)
                    |([+-]?\d*\.?\d*)([+-](?:\d*\.?\d*)?)i)"); // 正则表达式
    smatch result;

    if (regex_match(formula, result, pattern))
    {
        if (result[1].matched) // 处理纯虚数
        {
            string str = formula;
            if (str == "i") return Complex(0, 1);
            else if (str == "-i") return Complex(0, -1);
            else return Complex(0, stod(str));
        }
        else if (result[2].matched)
            return Complex(stod(result[2].str()), 0); // 处理实数
        else if (result[3].matched && result[4].matched)
        {
            if (result[4].str() == "+") return Complex(stod(result[3].str()), 1);
            else if (result[4].str() == "-") return Complex(stod(result[3].str()), -1);
            else return Complex(stod(result[3].str()), stod(result[4].str())); // 处理复数
        }
    }
    else throw invalid_argument("无效的输入！"); // 若表达式不符合正则表达式，抛出异常
    return Complex(); // 若表达式不符合任何情况，返回空复数
}