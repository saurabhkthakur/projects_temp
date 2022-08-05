#include <iostream>
#include <string>
using namespace std;



class Student {
    public:
     int rollno;
     int age;

};

class Student1 {
    public:
        int rollno;

    private:
        int age;

    public:

        void display(){
            cout << rollno << " " << age << endl;
        }

        void setage(int a){
            age = a;
        }

        int getage(){
            return age;
        }

};

int main(){
    // statically
    Student s1;

    // dynimcally
    Student *s2 = new Student;

    s1.age = 23;
    s1.rollno = 2;
    cout << s1.age << " " <<s1.rollno << endl;

    (*s2).age =21;
    (*s2).rollno = 3;
    // s2->age =21; //Exact same line like above 
    // // s2->rollno=1;

    cout << s2->age << " " << s2->rollno << endl; 
    cout << (*s2).age << " " << s2->rollno << endl;



    // getter and setter

    Student1 s3;
    Student1 *s4 = new Student1; 

    s3.display();
    s3.setage(24);
    s3.rollno=4;
    s3.display();

    
    




}