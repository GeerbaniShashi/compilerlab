//Q 11 .  remove extra space
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    string s, temp;
    cout<<"Input : "; getline(cin>>ws,s);
    bool space = false;
    for(int i=0 ; i<s.size() ; i++)
    {
        if(s[i]!=' ')
        {
            temp+=s[i];
            space = false;
        }
        else if(space==false)
        {
            temp+=' ';
            space = true;
        }
    }

    cout<<"Before removing space : "<<s<<endl;
    cout<<" After removing space : "<<temp<<endl;

    return 0;

}
Write to ত্রিবেণী তিথি
