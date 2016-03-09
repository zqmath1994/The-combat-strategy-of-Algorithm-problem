#include <iostream>
#include <cstring>
using namespace std;

/*�ݹ鷽���������ʽϵ��
int bino(int n,int r)
{
    if(r==0||r==n)
    {
        return 1;
    }
    return bino(n-1,r-1)+bino(n-1,r);
}*/

//���仯���� �Ʊ�
int cache[30][30];
int bino(int n,int r)
{
    if(r==0||r==n)
    {
        return 1;
    }
    if(cache[n][r]!=-1)
    {
        return cache[n][r];
    }
    return cache[n][r]=bino(n-1,r-1)+bino(n-1,r);
}
int main()
{
    int n,r;
    memset(cache,-1,sizeof(cache));
    cin>>n>>r;
    cout<<bino(n,r)<<endl;
    return 0;
}
