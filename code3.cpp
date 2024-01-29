// Write a program to implementation of operator precedence parser(Operator should be (+,-,/,*) and operand should be in single digit number).

#include<bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()

void solve1(string s) {
   vector<int>v;
   int i;
   for(i=0;i<s.size();i++) {
        if(s[i]=='-')   {
            v.push_back(-10);
        }
        else if(s[i]=='+')  {
            v.push_back(-20);
        }
        else if(s[i]=='*') {
            v.push_back(-30);
        }
        else if(s[i]=='/')  {
            v.push_back(-40);
        }
        else {
            v.push_back(s[i]-48);
        }
    }
    int value=0;
    while( find(all(v), -40) != v.end() )
    {
        auto it=find(all(v), -40);
        auto p=it; --p;
        auto n=it; ++n;
        value=((*p)/(*n));
        *it=value;
        v.erase(n);
        v.erase(p);
    }
    while(find(all(v), -30) != v.end())  {
        auto it=find(all(v), -30);
        auto p=it; --p;
        auto n=it; ++n;
        value=((*p)*(*n));
        *it=value;
        v.erase(n);
        v.erase(p);
    }

    while(find(all(v), -20) != v.end()) {
        auto it=find(all(v), -20);
        auto p=it; --p;
        auto n=it; ++n;
        value=((*p)+(*n));
        *it=value;
        v.erase(n);
        v.erase(p);
    }
    while( find(all(v), -10) != v.end()) {
        auto it=find(all(v), -10);
        auto p=it; --p;
        auto n=it; ++n;
        value=((*p)-(*n));
        *it=value;
        v.erase(n);
        v.erase(p);
    }
    cout<<v[0];
}
string solve2(string ss) {
    for(int i=1;i<ss.size()-1;i++)  {
        if(ss[i]=='<' && ss[i+2]=='>') {
            ss[i]='.';
            ss[i+1]='.';
            ss[i+2]='.';
        }
    }
    string s="";
    for(int i=0;i<ss.size();i++) {
        if(ss[i]!='.' && ss[i]!='<' && ss[i]!='>') {
            s+=ss[i];
        }
    }
    ss=s;
    return ss;
}
int main() {
    cout<<"Enter the arithmetic expression : ";
    string s;
    cin>>s;
    string ss="$";
    for(auto i:s) {
        if(i>='0' && i<='9')
        {
            ss+="<";
            ss+=i;
            ss+=">";
        }
        else
        {
            ss+=i;
        }
    }
    ss+="$";
    map<char, int>mp;
    mp['/']=50 , mp['*']=40 , mp['+']=30 , mp['-']=20 , mp['$']=10;
    cout<<ss<<endl;
    while(ss.size()>2) {
        string s=solve2(ss);
        if(s.size()==2) {
            break;
        }
        ss="";
        for(int i=0;i<s.size()-1;i++) {
            ss+=s[i];
            if(mp[s[i]]<mp[s[i+1]]) {
                ss+="<";
            }
            else
            {
                ss+=">";
            }
        }
        ss+="$";
        cout<<ss<<endl;
    }
    cout<<"Value is : ";
    solve1(s);
    return 0;
}
