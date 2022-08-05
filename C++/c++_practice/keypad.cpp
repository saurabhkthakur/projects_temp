#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
using namespace std;

string dial(int key){
    unordered_map<int,string>m;
    m[0]="";
    m[1]="";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}

int keypad(int num, string output[]){
    if(num ==0){
        return 1;
    }
    int smallnum = num/10;
    int n=num%10;

    int count= keypad(num,output);

    for(int i=0;i<3*cout;i++){
        output[i]=
    }

}




int main(){
    int num;
    cin >> num;
    string output[100];

    int count = keypad(num, output);
}