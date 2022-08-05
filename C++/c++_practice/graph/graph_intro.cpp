#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(int **edges, int n, int sv, bool *visited){

    cout << sv << endl;
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(i==sv)
            continue;

        
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }

            print(edges, n, i, visited);

        }
        
    }

}

void printBFS(int **edges, int n,int sv, bool * visited){

    queue<int> pending_vertices;
    // bool * visited = new bool[n];

    // for(int i=0;i<n;i++){
    //     visited[i] = false;
    // }

    pending_vertices.push(sv);
    visited[sv]=true;

    while(!pending_vertices.empty()){
        int current_vertices = pending_vertices.front();
        pending_vertices.pop();
        cout << current_vertices << endl;

        for(int i =0;i<n;i++){
            if(i==current_vertices){
                continue;
            }
            if(edges[current_vertices][i]==1 && !visited[i]){
                pending_vertices.push(i);
                visited[i] = true;
            }
        }
    }
        

}

void DFS(int ** edges, int n){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i])
            print(edges, n, i, visited); 
    }
    delete [] visited;

}


void BFS(int ** edges, int n){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i])
            printBFS(edges, n, i, visited); 
    }
    delete [] visited;

}

  





int main(){

    int n, e;
    cin >> n;
    cin >> e;

    int** edges = new int*[n];

    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0; j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    //DFS
    cout << "DFS" << endl;
    print(edges, n, 0, visited);


    //BFS
    cout << "BFS" << endl;
    printbfs(edges, n, 0);

    for(int i = 0;i<n;i++){
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
 













}
