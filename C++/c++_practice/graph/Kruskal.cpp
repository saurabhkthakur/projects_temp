#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Directed_graph{
    public:
        int source;
        int dest;
        int weight;


        // Directed_graph(int v1, int v2, int w){
        //     vertex1 = v1;
        //     vertex2 = v2;
        //     weight = w;
        // }

       

};

 bool compare(const Directed_graph class1, const Directed_graph class2){
            return class1.weight < class2.weight;
        }


int findparent(int v, int *parent_pos){
    if(parent_pos[v]==v){
        return v;
    }

    findparent(parent_pos[v], parent_pos);

}

void Krusikal(Directed_graph *input_edge, int v, int e){

    sort(input_edge, input_edge+e, compare);

    Directed_graph * output = new Directed_graph[v-1];

    int *parent_pos = new int[v];
    for(int i=0;i<v;i++){
        parent_pos[i] = i;
    }
    int count =0 ;
    int i =0;

    while(count != v-1){
        
       
        Directed_graph current_edeg = input_edge[i];

        int source_parent = findparent(current_edeg.source, parent_pos);
        int dest_parent = findparent(current_edeg.dest, parent_pos);

        if(source_parent != dest_parent){
            output[count] = current_edeg;
            count++;

            }
        i++;


    }

    for(int i =0; i< v-1;i++){
        if(output[i].source< output[i].dest){
            cout << "source :" << output[i].source << "dest :" << output[i].dest << "weight :" << output[i].weight << endl; 
        }
        else{
            cout << "dest :" << output[i].dest << "source :" << output[i].source << "weight :" << output[i].weight << endl;
        }
    }

    delete [] parent_pos;
}









int main(){

    int v,e;
    cin >> v >>e;
    
    
    vector<Directed_graph> output;


    Directed_graph *input_edge = new Directed_graph[e];




    for(int i=0; i<e;i++){
        int f,l,w;
        cin >> f >> l >> w;
        input_edge[i].source = f;
        input_edge[i].dest = l;
        input_edge[i].weight = w;

    }

    Krusikal(input_edge, v, e);

    

    
















}