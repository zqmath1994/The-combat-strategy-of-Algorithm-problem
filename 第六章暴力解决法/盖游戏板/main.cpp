#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2]={
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}},
}

bool set(vector<vector<int>>& board,int y,int x,int type,int delta)
{
    bool ok = true;
    for(int i =0; i < 3; ++i)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny < 0 || ny >= board.size() || nx < 0 || nx >=board[0].size())
        {
            ok = false;
        }
        else if((board[ny][nx] += delta) > 1)
        {
            ok = false;
        }
    }
     return ok;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
