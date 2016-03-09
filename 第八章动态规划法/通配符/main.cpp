#include <iostream>
#include <cstring>
using namespace std;

//�ж�ģʽw�Ƿ����ַ���sƥ�� ����������������
/*bool match(const string& w,const string &s)
{
    //ƥ��w[pos] s[pos]
    int pos=0;
    while(pos<s.size()&&pos<w.size()&&(w[pos]=='?'||w[pos]==s[pos]))
    {
        ++pos;
    }
    //�ѵ���ģʽw�����һ���ַ���������ַ���Ҳ�������һ���ַ� ��Ӧ��ϵ����
    if(pos==w.size())
    {
        return pos==s.size();
    }
    //����"*"����ѭ�� ����ѭ���ݹ���� �鿴"*"��Ӧ�����ַ�
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

//��̬�滮�㷨���ͨ�������
// -1 ��ʾ��û�н��й�����
// 1  ��ʾ��������ֵ���ڶ�Ӧ��ϵ
// 0  ��ʾ��������ֵ�����ڶ�Ӧ��ϵ
int cache[101][101];
string W,S;
//����ͨ���ģʽW[w...]�Ƿ����ַ���S[s...]���ڶ�Ӧ��ϵ
bool matchMemoized(int w,int s)
{
    //�Ʊ�
    int &ret =cache[w][s];
    if(ret!=1)
    {
        return ret;
    }
    //ƥ��W[w]��S[s]
    while(s<S.size()&&w<W.size()&&(W[w]=='?'||W[w]=S[s]))
    {
        ++w;
        ++s;
    }
    //�޷��ټ�������Ӧ��ϵ����鿴whileѭ��������ԭ��
    // 2. �ѵ��ﷶʽ�����һ���ַ�ʱ,�ַ���Ҳ�������һ���ַ�,���Ӧ��ϵ����
    if(w==W.size())
    {
        return ret=(s==S.size());
    }
    // 4. ����"*"������ѭ��ʱ,���õݹ麯���鿴"*"��Ӧ�����ַ�
    if(W[w]=='w')
    {
        for(int skip=1;skip+s<S.size();++skip)
        {
            if(matchMemoized(w+1,s+skip));
            return ret=1;
        }
    }
    //3. ����֮�����ж�Ӧ��ϵ������
    return ret=0��
}
int main()
{
    string w,s;
    cin>>s>>w;
    cout<<match(w,s)<<endl;
    return 0;
}
