

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// You are given with an integer k and an array of integers that contain numbers in random order.
//   Write a program to find k largest numbers from given array. You need to save them in an array and return it.
// Time complexity should be O(nlogk) and space complexity should be not more than O(k).

vector<int> Klargestelement(int k, vector<int> arr){
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i< arr.size();i++){
        pq.push(arr[i]);
    }

    for(int i=0; i< pq.size();i++){
        int element = pq.top();
        pq.pop();
        ans.push_back(element);
    }

    return ans;

}


vector<int> sortKarray(vector<vector<int>*> arr){
    vector<int> ans;

    priority_queue<int> pq; //greater

    for(int i=0; i< arr.size(); i++){

        for(int j = 0; j< arr[i]->size(); j++){

            pq.push(arr[i]->at(j));
        }

    }

 

    for(int i=0; i< pq.size();i++){
        int element = pq.top();
        pq.pop();
        ans.push_back(element);
    }

    return ans;

}
// You want to buy a ticket for a well-known concert which is happening in your city. 
// But the number of tickets available is limited. Hence the sponsors of the concert decided to
// sell tickets to customers based on some priority.
// A queue is maintained for buying the tickets and every person has attached with a priority
// (an integer, 1 being the lowest priority). The tickets are sold in the following manner -
// 1. The first person (pi) in the queue asked to comes out.
// 2. If there is another person present in the queue who has higher priority than pi,
//    then ask pi to move at end of the queue without giving him the ticket.
// 3. Otherwise, give him the ticket (and don't make him stand in queue again).
// Giving a ticket to a person takes exactly 1 minutes and it takes no time for removing and adding a person to the queue.
// And you can assume that no new person joins the queue.
// Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0).
// Find and return the time it will take until you get the ticket.

// Input Format :
// Line 1 : Integer N (Total number of people standing in queue)
// Line 2 : Priorities of every person (n space separated integers)
// Line 3 : Integer k (index of your priority)
// Output Format :
// Time required
// Sample Input 1 :
// 3
// 3 9 4
// 2
// Sample Output 1 :
// 2
// Sample Output 1 Explanation :
// Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status : {9, 4, 3}. Time : 0 secs.
// Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status : {4, 3}. Time : 1 secs.
// Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
// Sample Input 2 :
// 5
// 2 3 2 2 4
// 3
// Sample Output 2 :
// 4


int main(){

    // vector <int> arr = {2,46,32,534,65,121,12,32,1};

    // vector<int> out = Klargestelement(5, arr);

    // vector <int> arr1 = {2,46,32,534,65,121,12,32,1};
    // vector <int> arr2 = {2,16,42,5334,15,11,52,82,1211};

    // vector<vector<int>*> arr ;
    // arr.push_back(&arr1);
    // arr.push_back(&arr2);

    // vector<int> out = sortKarray(arr);

    // for(int i=0;i< out.size();i++){
    //     cout << out[i] << endl;
    // }


    int N;
    
    cin >> N ;
    // vector<int> priority;
    queue<int> priority;
    priority_queue<int> pq;
    vector<int> arr;
    for(int i=0;i< N;i++){
        int data;
        cin >> data;
        priority.push(i);
        arr.push_back(data);
        pq.push(data);
    }

    int pos;
    cin >> pos;

    
    int time =0;
    while(priority.front()!= pos || pq.top()!=arr[priority.front()] ){
        

        int element = arr[priority.front()];
        cout <<"ss" << element << endl;

     

     

        if(element < pq.top()){
            priority.push(element);
            priority.pop();
        }

        else if(element == pq.top()){
            pq.pop();
            priority.pop();
            time++;
        }


    }

    cout << time;








    return 0;
}