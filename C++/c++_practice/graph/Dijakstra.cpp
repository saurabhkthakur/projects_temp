#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int findminvertex(int *distance, bool *visited, int v){
    int minvertex = -1;

    for(int i=0;i<v;i++){
        if(!visited[i] && (minvertex==-1 || distance[i] < distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

void Dijkstra(int **edges, int v){
    bool *visited = new bool[v];
    int *distance = new int[v];

    for(int i=0;i<v;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0]=0;
    
    for(int i=0; i<v;i++){
        int minvertex = findminvertex(distance, visited, v);
        visited[minvertex]=true;
        for(int j=0;j<v;j++){

            if(edges[minvertex][j]!=0 && !visited[j]){

                int dist = edges[minvertex][j] + distance[minvertex];
                if(dist < distance[j]){
                    distance[j] = dist;

                }

            }
              
                    
        }
    }
    cout << endl;
    for(int i = 0; i<v; i++){
    
        cout << i << " " << distance[i] << endl;
    }

    delete [] distance;
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

    Dijkstra(edges, v);

    for(int i=0; i<v;i++){
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
