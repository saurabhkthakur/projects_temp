#include <iostream>
using namespace std;


// Geometric Sum
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// using recursion. Return the answer.
// Sample Input :
// 3
// Sample Output :
// 1.875

double gp(int input){
    if(input == 0)
        return 1;

    return 1+0.5*gp(input-1);
    
}

// Multiplication (Recursive)
// Given two integers m & n, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
// Input format : m and n (in different lines)

// Sample Input :
// 3 
// 5
// Sample Output -
// 15

int multi(int m, int n){
    if(n==1){
        return m;
    }
    if(n<0){
        return -multi(m,-n);
    }
    else
        return m+multi(m,n-1);

    
}

// Number of Digits
// Given the code to find out and return the number of digits present 
// in a number recursively. But it contains few bugs, 
// that you need to rectify such that all the test cases should pass.
// Input Format :
// Integer n
// Output Format :
// Count of digits
// Constraints :
// 1 <= n <= 10^6
// Sample Input :
//  156
// Sample Output :
// 3

int count_digit(int n){
    if(n==0)
        return 0;

    return 1+count_digit(n/10);
}

// Sum of digits (recursive)
// Write a recursive function that returns the sum of the digits of a given integer.
// Sample Input :
// 12345
// Sample Output :
// 15
int sum_digit(int n){
    if(n==0)
        return 0;
    
    return n%10+sum_digit(n/10);
    
}


// Check Number
// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.
// Input Format :
// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x
// Output Format :
// true or false
// Constraints :
// 1 <= N <= 10^3
// Sample Input :
// 3
// 9 8 10
// 8
// Sample Output :
// true

bool check_x(int arr[],int size,int x){

    if(size == 0){
        return false ;
    }

    if(arr[0]==x){
        return true;
    }
    return check_x(arr+1, size-1, x);

}

// Check Palindrome (recursive)
// Check if a given String S is palindrome or not (using recursion). Return true or false.
// Input Format :
// String S
// Output Format :
// true or false
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

bool check_palindrome(string s,int i,int size){

    if(size%2 ==0){
        if(s.length()<=size/2){
            return true;
        }
    }
    else{
        if(s.length()<=size/2){
            return true;
        }
    }
    
    cout << size << " " << s.length()<<endl;
    cout<< s << " "  << s[0] <<" "<<s[s.length()-(1+i)] << i<< endl;
    if(s[0]==s[s.length()-(1+i)]){
        return check_palindrome(s.substr(1),++i,size);
    }
    
    return false;
}

// Power
// Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
// Do this recursively.
// Input format :
// Two integers x and n (separated by space)
// Output Format :
// x^n (i.e. x raise to the power n)
// Constraints :
// 1 <= x <= 30
// 0 <= n <= 30
// Sample Input 1 :
//  3 4
// Sample Output 1 :
// 81
// Sample Input 2 :
//  2 5
// Sample

int check_power(int num, int x){
    if(x == 0){
        return 1;
    }
    return num*check_power(num,x-1);

}

// Sum of Array
// Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.
// Input Format :
// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Output Format :
// Sum
// Constraints :
// 1 <= N <= 10^3
// Sample Input :
// 3
// 9 8 9
// Sample Output :
// 26

int sum_arr(int arr[],int size){
    if(size == 0){
        return 0 ;
    }

    return arr[0]+sum_arr(arr+1,size-1);
}


// Pair star
// Given a string, compute recursively a new string where identical 
// chars that are adjacent in the original string are separated from 
// each other by a "*".
// Sample Input 1 :
// hello
// Sample Output 1:
// hel*lo
// Sample Input 2 :
// xxyy
// Sample Output 2:
// x*xy*y
// Sample Input 3 :
// aaaa
// Sample Output 3:
// a*a*a*a

string pair_star(string s,string output){
    if(s.length()==1){
        output = output + s;
        return output;
    }
    // cout << s[0] << " " << s[1]<< endl;
    if(s[0]==s[1]){
        output = output+s[0]+'*';
    }
    else{
        output =output+s[0];}
    return pair_star(s.substr(1),output);

    
}

// Remove X
// Given a string, compute recursively a new string where all 'x' chars have been removed.
// Sample Input 1 :
// xaxb
// Sample Output 1:
// ab
// Sample Input 2 :
// abc
// Sample Output 2:
// abc
// Sample Input 3 :
// xx
void removex(char s[]){

    if(s[0] == '\0')
        return;
    
    if(s[0]!= 'x'){
        removex(s+1);
    }
    else{
        int i=1;
        for( ; s[i]!='\0'; i++){
            s[i-1]=s[i];
        }
        // add null char at the end
        cout << i << endl;
        s[i-1]=s[i];
        removex(s);
    }
}
void remove_x(string s, char x){
    if(s.empty()){
        return;
    }

    if(s[0]==x){
        int i=1;
        for(int i =1;i<s.length();i++){
            s[i-1]=s[i];
        }
        cout << i << endl;
        s[i-1]='\0';
        cout << s;
        remove_x(s,x);
    }
    remove_x(s.substr(1),x);
}

// Replace pi (recursive)
// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p
// void replacepi(char s[]){
//     if(s[0]=='\0'){
//         return;
//     }

//     if(s[0]+s[1]=='pi'){
//         s.replace()
//     }
// }



int stringToNumber(char input[]) {
    	int  intValue;
     	intValue=atoi(input);
	
    
    	return intValue;
}


// Tower of Hanoi
// Tower of Hanoi is a mathematical puzzle where we have three rods and n
//  disks. The objective of the puzzle is to move all disks from source rod 
//  to destination rod using third rod (say auxiliary). The rules are :
// 1) Only one disk can be moved at a time.
// 2) A disk can be moved only if it is on the top of a rod.
// 3) No disk can be placed on the top of a smaller disk.
// Print the steps required to move n disks from source rod to destination rod.
// Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
// Input Format :
// Integer n
// Output Format :
// Steps in different lines (in one line print source and destination rod name separated by space)
// Sample Input :
// 2
// Sample Output :
// a b
// a c
// b c

int main(){
    // int n,x;
    string s;
    // char str[100];
    // cin >> str;
    cin >> s ;
    // string output  = "";
    // cin >> n;
    // int arr[n] ;

    // for(int i=0;i<n;i++){
    //     int a ;
    //     cin >> a;
    //     arr[i]=a;
    // }
    
    // removex(str);
    // remove_x(s,'v');
    // cout << stringToNumber(str);
    // cout << s.find('pi');
    cout <<s.find('p');


    




}