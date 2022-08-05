#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
 
{
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    
    dp[0]=0;
    for(int i=1;i<10;i++) dp[i]=1;
    
    
    for(int i=10;i<n+1;i++){
        for (char c : to_string(i)){
            if(c=='0') continue;
            dp[i] = min(dp[i], 1+dp[i-(c-'0') ]);
        
        }
    
    }
    

    cout << dp[n] << endl;
    
 
}






















//memoization
// int f(int n, vector<int> &dp){

    
//     if(n==0) return 0;
    
//     if(n < 10 && n>0) return 1;
    
    
//     if(dp[n]!=-1) return dp[n];
//     int mini=1e8;
     
//     for (char c : to_string(n)){
//         if(c=='0') continue;
//         mini = min(mini, 1+f(n-(c-'0'), dp ));
        
//     }
    
    
    
//     return dp[n]=mini;
// }

// int main()

// {
//     int n;
//     cin >> n;
//     // for (char c : to_string(i)) {
//     //     cout << i-(c-'0') <<typeid(i-c-'0').name() << endl;
//     // }
//     vector<int> dp(n+1,-1) ;
    
    
//     cout << f(n,dp) << endl;
    

//     return 0;
// }