// Write a program which takes 0’s and 1’s as input string and accept that string which is divisible by 4 using the concept of DFA.


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  char A = '0';
  char B = '1';
  char C = '2';
  char D = '3';
  
  char current_state = A;
  char final_state = A;
  
  string s;
  cin>>s;
  
  for(ll i=0; i<s.length(); i++){
    if(current_state == A && s[i] == '0') current_state = A;
    else if(current_state == A && s[i] == '1') current_state = B;
    else if(current_state == B && s[i] == '0') current_state = C;
    else if(current_state == B && s[i] == '1') current_state = D;
    else if(current_state == C && s[i] == '0') current_state = A;
    else if(current_state == C && s[i] == '1') current_state = B;
    else if(current_state == D && s[i] == '0') current_state = C;
    else if(current_state == D && s[i] == '1') current_state = D;
    
  }
  if(final_state == current_state) cout<<s<<" is divisible by 4."<<endl;
  else cout<<s<<" is not divisible by 4."<<endl;
  return 0;
}

