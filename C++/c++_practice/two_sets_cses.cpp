#include <bits/stdc++.h>
 
using namespace std;
// # define int long long
# define long long ll

ll mod=1e9+7;

// Fermate little therorm

int add(int a, int b,int mod) {
    a%=mod;
    b%=mod;
	a += b;
	if (a >= mod) a -= mod;
	if(a<0)
    {
        a += mod;
        a %= mod;
    }
	return a;
}
 
int mul(ll a, int b,int mod) {
    a%=mod;
    b%=mod;
	a *= b;
	a += mod;
	return a % mod;
}
int po(int a,int b,int mod)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return po(mul(a,a,mod),b/2,mod);
    return mul(a,po(mul(a,a,mod),(b-1)/2,mod),mod);
}


// To compute x^y under modulo m
// int power(int x, unsigned int y, unsigned int m)
// {
//     if (y == 0)
//         return 1;
//     int p = power(x, y / 2, m) % m;
//     p = (p * p) % m;
 
//     return (y % 2 == 0) ? p : (x * p) % m;
// }
 
int f(int n,int sum,vector<vector<int>> &dp){
    if(sum <0) return 0;
    if(sum==0) return 1;
    
    if(n==0) return 0;
    if(dp[n][sum]!=-1) return dp[n][sum];
    int nottake = f(n-1,sum,dp);
    int take = 0 ;
       
    take=f(n-1,sum-n,dp);
   
  return dp[n][sum]=((take%mod)+(nottake%mod))%mod;
}
 
 
 
 
signed main()
{
    int n;
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++) sum+=i; 
    // cout << sum << " " << sum/2 << endl;
    if(sum%2!=0) cout << 0 << endl;
 
    else{
    
    vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
    

    cout << (po(2, mod-2,mod) *f(n,sum/2,dp))%mod;
    }
    
  
    
}   
   