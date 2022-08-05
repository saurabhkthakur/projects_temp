#include <bits/stdc++.h>

using namespace std;

# define ll long long
# define pb push_back

int n,m;
string gr[1005];
bool vis[1005][1005];

void dfs(int x, int y){
    if(x<0 || y<0 || x==n || y==m || vis[x][y] || gr[x][y]=='#')
    return;

    vis[x][y]=true;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);


}


int main(){

    cin >> n>> m;
    for(int i=0;i<n;i++)
    cin>>gr[i];

    memset(vis,false,sizeof(vis));

    int res=0;
    for(int i=0; i<n;i++){

        for(int j=0;j<m;j++){
            if(gr[i][j]=='.' && !vis[i][j]){
                dfs(i,j);
                res++;
            }
        }
    }




    cout << res;

    return 0;
}


