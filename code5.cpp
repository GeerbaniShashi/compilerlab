/*5. Write a program which takes 0’s and 1’s as input string and accept that string which have 
odd number of 0’s and odd number of 1’s using the concept of DFA.
*/
//Solution in cpp:
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  char EO = 'A';
  char OE  = 'B';
  char OO = 'C';
  char EE = 'D';
  
  char current_state = EE;
  char final_state = OO;
  
  string s;
  cin>>s;
  
  for(ll i=0; i<s.length(); i++){
    if(current_state == EE && s[i] == '0') current_state = OE;
    else if(current_state == EE && s[i] == '1') current_state = EO;
    else if(current_state == OE && s[i] == '0') current_state = EE;
    else if(current_state == OE && s[i] == '1') current_state = OO;
    else if(current_state == EO && s[i] == '0') current_state = OO;
    else if(current_state == EO && s[i] == '1') current_state = EE;
    else if(current_state == OO && s[i] == '0') current_state = EO;
    else if(current_state == OO && s[i] == '1') current_state = OE;
    
  }
  if(final_state == current_state) cout<<s<<" is accepted."<<endl;
  else cout<<s<<" is not accepted."<<endl;
  return 0;
}
