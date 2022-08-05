#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = 0;
  int s = 1;
  for(int i=1;i<s.length();i++){

    if(s[i-1] == s[i]){
      n++;

    }
      
    else{
      s = max(s,n);
      n=1   
    }

  }
}
