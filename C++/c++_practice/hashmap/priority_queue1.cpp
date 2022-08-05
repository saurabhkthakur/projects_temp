#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Student{
    public:
        int age;
        string name;

        Student(int age, string name){
            this->age = age;
            this->name = name;
        }

        bool operator< ( const Student otherstudent) const{
            return age < otherstudent.age;
        }

        
};

// struct compare{
//     bool operator()(Student a, Student b){
//         return a.age > b.age;
//     }
// };



int main(){

    priority_queue<Student> pq;
    // priority_queue<Student, vector<Student>, compare> pq;



    cout << pq.empty() << endl;
    // pq.push(60);
    // pq.push(20);
    // pq.push(30);
    pq.push(Student(90,"saurabh"));
    pq.push(Student(20,"abc"));
    pq.push(Student(100,"def"));
    pq.push(Student(10,"as"));
    cout << pq.empty() << endl;
    cout << pq.size() << endl;
    cout << pq.top().name << endl;
    pq.pop();
    cout << pq.size() << endl;

    return 0;
}