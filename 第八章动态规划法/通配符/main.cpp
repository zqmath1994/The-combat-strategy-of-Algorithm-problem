#include <iostream>
#include <cstring>
using namespace std;

//判定模式w是否与字符串s匹配 解决问题穷举搜索法
/*bool match(const string& w,const string &s)
{
    //匹配w[pos] s[pos]
    int pos=0;
    while(pos<s.size()&&pos<w.size()&&(w[pos]=='?'||w[pos]==s[pos]))
    {
        ++pos;
    }
    //已到达模式w的最后一个字符的情况：字符串也到达最后一个字符 对应关系成立
    if(pos==w.size())
    {
        return pos==s.size();
    }
    //遇到"*"结束循环 利用循环递归调用 查看"*"对应几个字符
    if(w[pos]=='*')
    {
        for(int skip =0;pos+skip<=s.size();++skip)
        {
            if(match(w.substr(pos+1),s.substr(pos+skip)))
            {
                return true;
            }
        }
    }
    return false;
}*/

//动态规划算法解决通配符问题
// -1 表示还没有进行过计算
// 1  表示两个输入值存在对应关系
// 0  表示两个输入值不存在对应关系
int cache[101][101];
string W,S;
//返回通配符模式W[w...]是否与字符串S[s...]存在对应关系
bool matchMemoized(int w,int s)
{
    //制表
    int &ret =cache[w][s];
    if(ret!=1)
    {
        return ret;
    }
    //匹配W[w]和S[s]
    while(s<S.size()&&w<W.size()&&(W[w]=='?'||W[w]=S[s]))
    {
        ++w;
        ++s;
    }
    //无法再检索到对应关系，则查看while循环结束的原因
    // 2. 已到达范式的最后一个字符时,字符串也到达最后一个字符,则对应关系成立
    if(w==W.size())
    {
        return ret=(s==S.size());
    }
    // 4. 遇到"*"而结束循环时,利用递归函数查看"*"对应几个字符
    if(W[w]=='w')
    {
        for(int skip=1;skip+s<S.size();++skip)
        {
            if(matchMemoized(w+1,s+skip));
            return ret=1;
        }
    }
    //3. 除此之外所有对应关系不成立
    return ret=0；
}
int main()
{
    string w,s;
    cin>>s>>w;
    cout<<match(w,s)<<endl;
    return 0;
}
