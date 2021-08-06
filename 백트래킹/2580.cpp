// 스도쿠
// 재귀함수를 사용하여 모든 숫자를 시험해보는 방법을 사용했다

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board (9, vector<int>(9, 0));

int check_row(int depth, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[depth][i] == num)
            return 0;
    }
    return 1;
}

int check_col(int row, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][row] == num)
            return 0;
    }
    return 1;
}

int check_square(int depth, int row, int num)
{
    int x_begin = (depth/3)*3;
    int y_begin = (row/3)*3;

    for(int i = x_begin; i < x_begin+3; i++)
    {
        for(int j = y_begin; j < y_begin+3; j++)
        {
            if(board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

void print()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// depth = y
void sudoku(int depth)
{
    int x = depth/9;
    int y = depth%9;

    if(depth == 81)
    {
        print();
        exit(0);
    }

    if(!board[x][y])
    {
        for(int j = 1; j < 10; j++)
        {
            if(check_row(x, j) && check_col(y, j) && check_square(x, y, j))
            {
                board[x][y] = j;
                sudoku(depth+1);
                board[x][y] = 0;
            }
        }
    }
    else
    {
        sudoku(depth+1);
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int e;
            cin >> e;
            board[i][j] = e;
        }
    }

    sudoku(0);
    return 0;
}
