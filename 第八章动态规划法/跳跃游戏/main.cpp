#include <iostream>

using namespace std;

int n,board[100][100];
//�ݹ鷽��
bool jump(int y,int x)
{
    if(y>=n||x>=n)
    {
        return false;
    }
    if(y == n-1 && x == n-1)
    {
        return true;
    }
    int jumpSize = board[y][x];
    return jump(y+jumpSize,x)||jump(y,x+jumpSize);
}

//�Ʊ���
int cache[100][100];
int jump2(int y ,int x)
{
    if(y>=n||x>=n)
    {
        return 0;
    }
    if(y == n-1 || x == n-1)
    {
        return 1;
    }
    //�Ʊ�
    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }
    int jumpSize = board[y][x];
    return ret = (jump2( y + jumpSize,x)||jump2(y,x+jumpSize));
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
