#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int findMinVertex(int *weight, bool *visited, int v){
    int minvertex = -1;

    for(int i=0; i<v;i++){
        if(!visited[i] && (minvertex==-1 || weight[i]<weight[minvertex])){
            minvertex = i;
        }
    }
    return minvertex;    
}

void Prims(int **edges, int v){
    bool *visited = new bool[v];
    int *parent = new int[v];
    int *weight = new int[v];

    for(int i=0; i<v;i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;

    for(int i=0;i<v;i++){
        //find min vertex
        int minvertex = findMinVertex(weight, visited, v);
        visited[minvertex] =true;
        //Explore neighbours
        for(int j=0; j<v;j++){
            if(edges[minvertex][j] !=0 && !visited[j]){
                if(edges[minvertex][j] < weight[j]){
                    weight[j] = edges[minvertex][j];
                    parent[j] = minvertex;
                }

            }

        }
    }

    for(int i = 1; i<v; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
             cout << i << " " << parent[i] << " " << weight[i] << endl;
    }



    delete [] weight;
    delete [] parent;
    delete [] visited;
}
 
int main(){

    int v,e;

    cin >> v;
    cin >> e;

    int** edges = new int*[v];
    int* weights = new int[v];

    for(int i=0; i<v ; i++){

        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j]=0;

        }
    }

    for(int i=0; i<e ; i++){
    
        int source, dest, weight;
        cin >> source >> dest >> weight;
        edges[source][dest] = weight;
        
    }

    Prims(edges, v);

    for(int i=0; i<v;i++){
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}

// 5 7
// 0 1 4
// 0 2 8
// 1 3 6
// 1 2 2
// 2 3 3
// 2 4 9
// 3 4 5