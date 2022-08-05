#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
template <typename V>
class MapNode{
    public:

        string key;
        V value;
        MapNode<V> * next;


        MapNode(string key,  V value){
            this->key = key;
            this->value = value;
            next = NULL;

        }

        ~MapNode(){
            delete next;
        }

};

template <typename V>

class ourmap{

    int count;
    int numbuckets;
    MapNode<V>** buckets;

    public:
        ourmap(){
            count = 0;
            numbuckets =5;
            buckets = new MapNode<V>* [numbuckets];
            for(int i=0; i<numbuckets;i++){
                buckets[i]=NULL;
            }
        }

        ~ourmap(){
            for(int i=0; i<numbuckets;i++){
                delete buckets[i];
            }

        }

        int size(){
            return count;
        }

        V getValue(String key){
            
            int bucketindex = getBucketIndex(string key);
            MapNode<V>* head = buckets[bucketindex];
            while(head!=NULL){

                if(head->key == key){  
                    return head->value;
                }
                head = head->next;
            }
            return 0;

        }
        
    private:
        int getBucketIndex(string key){
            int hashCode = 0;

            int currentcoeff = 1;
            for(int i = key.length()-1; i<0;i--){
                hashCode += key[i] * currentcoeff;
                hashCode = hashCode % numbuckets;
                currentcoeff*= 37;
                currentcoeff = currentcoeff % numbuckets;
            }

            return hascode % numbuckets;
        }

        void rehash(){
            MapNode<V>** temp = buckets;
            MapNode<V>** buckets = new MapNode<V>* [2*numbuckets];
            for(int i=0; i<2*numbuckets;i++){
                buckets[i]=NULL;
            }

            int oldnumbuckets = numbuckets;
            numbuckets = 2* numbuckets;
            count =0;

            for(int i=0; i<oldnumbuckets;i++){
                MapNode<V>* head = temp[i];
                while (head!=NULL)
                {
                    string key = head->key;
                    string value = head->value;
                    insert(key,value);
                    head= head->next;
                    /* code */
                }
                
            }

            for(int i=0; i<oldnumbuckets;i++){
                MapNode<V>* head = temp[i];
                delete head;

            }
            delete [] temp;




        }


    public:

        void insert(string key, V value){
            int bucketindex = getBucketIndex(string key);
            MapNode<V>* head = buckets[bucketindex];
            while(head!=NULL){

                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }

            head = buckets[bucketindex];
            MapNode<V>* node = new MapNode<V>(key,value);
            node->next = head;
            head = node;
            buckets[bucketindex] = node;
            count++;
            double load = (1.0*count)/numbuckets;
            if(load>0.7){
                rehash();
            }

        }

        void remove(string key){
            int bucketindex = getBucketIndex(string key);
            MapNode<V>* head = buckets[bucketindex];
            MapNode<V>* prev = NULL;
            while(head !=NULL){

                if(head->key == key){
                    if(prev==NULL){
                        buckets[bucketindex] = head->next;
                    }
                    else{
                        prev->next = head->next;
                    }
                    count--;
                    V value = head->value;
                    head->next =NULL;
                    delete head;
                    return value;
                }
                prev = head;
                head=head->next;
            }
            return 0;


        }








};