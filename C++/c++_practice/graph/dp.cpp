
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int fibonacci_dp(int n){
    
    int * ans = new int[n+1];
    ans[0] =0;
    ans[1] = 1;

    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1]+ans[i-2];
    }

    return ans[n];


}

int fibonacci(int n){
    if(n<=1){
        return n;
    }

    return fibonacci(n-1) +fibonacci(n-2);
}

// 0,1,1,2,3,5

int fibonacci_better(int n, int *ans){
    if(n<=1){
        ans[n]=n;
        return n;
    }

    if(ans[n-1] ==0){
        ans[n-1]= fibonacci_better(n-1, ans);

    }    
    if(ans[n-2] ==0){
        ans[n-2]= fibonacci_better(n-2,ans);

    }
    ans[n] = ans[n-1]+ans[n-2];

    return ans[n];

}

int fibonacci_better(int n){
    int * ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=0;
    }
    return fibonacci_better(n, ans);
    }


int min_steps_dp(int n){
    int * ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    ans[0] =0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;

    for(int i=4;i<=n;i++){

        if(i%2==0){
            ans[i] = ans[i/2]+1;
        }
        else if(i%3==0){
            ans[i] = ans[i/3]+1;
        }
        else{
            ans[i]=ans[i-1]+1;
        }
        
    }

    return ans[n];

}

int min_steps(int n, int *ans){
    if(n==1){
        return 0;
    }

    int y= INT_MAX;
    int z = INT_MAX;

    if(ans[n-1]==-1){
        int a = min_steps(n-1, ans)+1;
    }
    if(n%2==0){
        if(ans[n/2]==-1){
            ans[n/2] = min_steps(n/2, ans);
        }
        y= ans[n/2];
    }

    if(n%3==0){
        if(ans[n/3]==-1){
            ans[n/3] = min_steps(n/3, ans);
        }
        z = ans[n/3];
    }

    ans[n] = min(ans[n-1], min(z,y))+1;

    return ans[n];
}

int min_steps(int n){
    if(n==1){
        return 0;
    }
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(n%3==0){
        ans1 = min_steps(n/3);
    }
    if(n%2==0){
        ans2 = min_steps(n/2);
    }
    int ans3 = min_steps(n-1);

    

    return min(ans1,min(ans2,ans3))+1;
    
}


int main(){

    // cout << fibonacci(6) << endl;
    // cout << fibonacci_better(6) << endl;
    // cout << fibonacci_dp(6) << endl;

    cout << min_steps(5) << endl;
    cout << min_steps_dp(5) << endl;



}