#include <iostream>
#include <string>
#include <vector>
using namespace std;

//画了个苦力怕的脸。

vector<string> line1 = {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588"};
vector<string> line2 = {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588"};
vector<string> line3 = {"\u2588", " ", " ", "\u2588", "\u2588", " ", " ", "\u2588"};
vector<string> line4 = {"\u2588", " ", " ", "\u2588", "\u2588", " ", " ", "\u2588"};
vector<string> line5 = {"\u2588", "\u2588", "\u2588", " ", " ", "\u2588", "\u2588", "\u2588"};
vector<string> line6 = {"\u2588", "\u2588", " ", " ", " ", " ", "\u2588", "\u2588"};
vector<string> line7 = {"\u2588", "\u2588", " ", " ", " ", " ", "\u2588", "\u2588"};
vector<string> line8 = {"\u2588", "\u2588", " ", "\u2588", "\u2588", " ", "\u2588", "\u2588"};
vector<vector<string>> board = {line1, line2, line3, line4, line5, line6, line7, line8};

int main()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (auto c : board[i])
        {
            cout << c;
        }
        cout << endl;
    }
}