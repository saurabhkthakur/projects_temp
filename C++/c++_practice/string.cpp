#include <iostream>
#include <math.h>
using namespace std;

int subseq(string str, string output[]){
    if(str.empty()){
        output[0] = ' ';
        return 1;
    }
    string small_str = str.substr(1);
    int subseqstrsize = subseq(small_str, output);
    cout << subseqstrsize << endl;

    for(int i=0; i<subseqstrsize;i++){
        output[i+subseqstrsize]= str[0]+output[i];
    }

    return 2*subseqstrsize;



}



int main(){
string str;
cin >> str;
// getline(str, cin);
int size = pow(2,str.size());
string output[size];

int count = subseq(str,output);
// cout << count;
// for(int i=0; i<count;i++){
//     cout << output[i] << endl;
// }


}