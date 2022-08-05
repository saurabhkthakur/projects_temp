#include <iostream>
#include <string>
using namespace std;



class Student{
    public:
        int rollnumber;
    
    private:
        int age;

    public:
        //Deconstructor
        ~Student(){
            cout << "deconstructor called" << endl;
        }


        // Default constructor 
        // for one object constructor is called once, constructor is used to initialize object
        Student() {
            cout << "Default Constructor Called -->" << endl;
        }

        Student(int r){
            cout << "1st parameterized Constructor Called -->" << endl;
            rollnumber = r;
        }

        Student(int r, int a){
            cout << "1st parameterized 2 Constructor Called -->" << endl;
            rollnumber = r;
            age = a;

        }

    
        void display(){
            cout << rollnumber << " " << age << endl;
        }

        void setage(int a){
            // if inplace of a we have a variable name as age we have to use this variable to refer class variable
            this -> age = a;
        }

        int getage(){
            return age;
        }


};

int main(){

    Student s1;
    Student s2(10);
    Student s3(11,21);

    Student s4(s3);  //copy constructor
    s4.display();

    s1 = s2 ; // = assignment 
    s1.display();
    Student *s5 = new Student;
    *s5 = s2;
    s5->display();

    



}