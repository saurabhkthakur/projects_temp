#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Teacher
{

public:
    string name;
    int age;

    void print()
    {
        cout << "teacher" << endl;
    }
};

class Student
{
public:
    void print()
    {
        cout << "Student" << endl;
    }
};

class TA : public Teacher, public Student
{

public:
    // void print()
    // {

    //     cout << "TA --" << endl;
    // }
};

int main()
{

    TA c1;
    c1.Student :: print();

    return 0;
}