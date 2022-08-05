#include <bits/stdc++.h>

using namespace std;

// # include vector
# define ll long long
# define pb push_back


class Student{


    private:
    static int total_student;

    public:
     int age;
     int rollno;


     

     Student(){
         total_student++;
     }

     static int get_totalstudent(){
         return total_student;
     }

};

    int Student :: total_student = 0; //initiliaze static members


int main(){
    Student s1;

    cout << s1.age << " " << s1.rollno << endl;
    cout << Student :: get_totalstudent() << endl;


    return 0;

}


