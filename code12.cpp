//12.Write a program which takes two string as input and check second string is suffix, prefix,substring and subsequence of first string or not.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool is_prefix(string s,string a) {
    ll i=0;
    for( i=0; i<a.length(); i++) {
        if(s[i] != a[i]) break;
    }
    if(i == a.length()) return true;
    return false;
}
bool is_suffix(string s, string a) {
    ll i,j;
    for(i=a.length()-1,j=s.length()-1; i>=0; i--,j--) {
        if(a[i] != s[j]) break;
    }
    if(i == -1) return true;
    return false;
}
bool is_substring(string s,string a) {
    bool ok =false;
    for(ll i=0; i<s.length()-a.length(); i++) {
        ll j;
        for(j=0; j<a.length(); j++) {
            if(s[i+j] != a[j]) break;
        }
        if(j == a.length()) {
            ok = true;
            break;
        }
    }
    return ok;
}
bool is_subsequence(string s, string a) {
        ll j=0;
        for(ll i=0;i<s.length();i++)
		{
            if(a[j]==s[i])j++;
        }
      return (j==a.length())?true : false;
    }

int main() {
    string s,a;
    cin>>s>>a;

    if(is_prefix(s,a)) cout<<"Yes,prefix found"<<endl;
    else cout<<"prefix not found"<<endl;

    if(is_suffix(s,a)) cout<<"Yes,suffix found"<<endl;
    else cout<<"suffix not found"<<endl;

    if(is_substring(s,a)) cout<<"Yes,substring found"<<endl;
    else cout<<"substring not found"<<endl;

    if(is_subsequence(s,a)) cout<<"Yes,subsequence found"<<endl;
    else cout<<"subsequence not found"<<endl;

    return 0;

}

