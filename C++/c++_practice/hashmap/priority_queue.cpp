#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue{
    vector<int> pq;


    public:
        PriorityQueue(){

        }


        bool isEmpty(){
            return pq.size() ==0;
        }

        int getSize(){
            return pq.size();
        }

        int getMin(){
            if (pq.size()==0){
                return 0;
            }

            return pq[0];
        }


        void Insert(int data){

            
            pq.push_back(data);

            int childindex = pq.size()-1;

            while(childindex >0){
                int parentindex = (childindex -1)/2;

                if(pq[childindex] < pq[parentindex]){
                    int temp = pq[childindex];
                    pq[childindex] = pq[parentindex];
                    pq[parentindex] = temp;
                }
                else{
                    break;
                }
                childindex = parentindex;
            }

        }

        void removeelement(){
            int last_index = pq.size()-1;
            int temp = pq[0];
            pq[0] = pq[last_index];
            pq[last_index] = pq[0];

            pq.pop_back();

            int parent_index = 0;
            int child_index_1 = 2*parent_index+1;
            int child_index_2 = 2*parent_index+2;

            while(child_index_1 <= last_index  || child_index_2 <= last_index) {

                int child_index_1 = 2*parent_index+1;
                int child_index_2 = 2*parent_index+2;

               if(pq[parent_index] > pq[child_index_1]){
                    int temp = pq[child_index_1];
                    pq[child_index_1] = pq[parent_index];
                    pq[parent_index] = temp;
                    
                }

                  if(pq[parent_index] > pq[child_index_2]){
                    int temp = pq[child_index_2];
                    pq[child_index_2] = pq[parent_index];
                    pq[parent_index] = temp;
                    parent_index = child_index_2;
                }
                else{
                    parent_index = child_index_1;
                }

                child_index_1 = 2*parent_index+1;
                child_index_2 = 2*parent_index+2;
            }
            


        }

};