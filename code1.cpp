//Write a program which can identify correct identifier, keyword and comment.

#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
  string keyword[32]={
      "auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"
   } ;
   cout<<"Select any option: 1: To check Identifier"<<endl;
   cout<<"                   2: To check Keyword"<<endl;
   cout<<"                   3: To check comment"<<endl;
   
   ll option;
   cout<<"Choose your option: ";
   cin>>option;
   
   cout<<"Please enter any String: ";
   string s;
   cin>>s;
   
  if(option == 1) {
    bool ok = true;
    if (!((s[0] >= 'a' && s[0] <= 'z')
          || (s[0] >= 'A' && s[0] <= 'Z')
          || s[0] == '_')) {
            ok = false;
          }
        
 
    for (ll i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z')|| (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            ok = false;
            break;
    }
 
    if(ok) cout<<"This is valid identifier."<<endl;
    else cout<<"This is not valid identifier."<<endl;
  }
  
  else if(option == 2) {
   ll flag=0;
   for(ll i = 0; i < 32; i++) {
      if(s == keyword[i]) {
         flag=1;
         break;
      }
   }
   if(flag == 1) cout<<"This is valid keyword."<<endl;
   else cout<<"This is not valid keyword."<<endl;
  }
  
  else if(option == 3) {
   if (s[0] == '/' && s[1] == '/' && s[2] != '/') {
        cout << "It is a single-line comment."<<endl;
    }
   else if (s[s.length() - 2] == '*' && s[s.length() - 1] == '/' && s[0] == '/' && s[1] == '*') {
        cout << "It is a multi-line comment."<<endl;
    }
   else cout << "It is not a comment."<<endl;
  }
  return 0;
}
