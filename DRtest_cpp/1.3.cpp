#include <iostream>
#include <string>
#include <vector>
using namespace std;

//画了个苦力怕的脸。

vector<int> line1 = {1, 1, 1, 1, 1, 1, 1, 1};
vector<int> line2 = {1, 1, 1, 1, 1, 1, 1, 1};
vector<int> line3 = {1, 0, 0, 1, 1, 0, 0, 1};
vector<int> line4 = {1, 0, 0, 1, 1, 0, 0, 1};
vector<int> line5 = {1, 1, 1, 0, 0, 1, 1, 1};
vector<int> line6 = {1, 1, 0, 0, 0, 0, 1, 1};
vector<int> line7 = {1, 1, 0, 0, 0, 0, 1, 1};
vector<int> line8 = {1, 1, 0, 1, 1, 0, 1, 1};
vector<vector<int>> board = {line1, line2, line3, line4, line5, line6, line7, line8};

int main()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (auto c : board[i])
        {
            if (c == 0) cout << " ";
            else if (c == 1) cout << "\u2588";
        }
        cout << endl;
    }
}