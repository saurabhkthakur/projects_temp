#include <bits/stdc++.h>

using namespace std;

// # include vector
# define ll long long
# define pb push_back

// whenever we have const datatype we have to create intiliazation list such that we can 
// store value at memory creation time in const data member

// Initialization list rollNumber(rollno), age(age), x(this -> age)

class Student {
    public:
    int age;
    const int  rollNumber;
    int &x; //age reference variable

    Student(int age, int rollno) : rollNumber(rollno), age(age), x(this -> age){

    }

    void display(){
        cout << this ->age << " " << this ->rollNumber << " " << this -> x;

    }
};

int main(){

    Student s1(20,30);

    cout <<  s1.age << " " <<  s1.rollNumber << " " <<  s1.x;

    s1.display();



    return 0;
}




