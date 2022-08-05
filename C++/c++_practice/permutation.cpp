#include <iostream>
#include <string>
using namespace std;

// Print Permutations - String
// Given a string, find and print all the possible permutations of the input string.
// Note : The order of permutations are not important. Just print them in different lines.
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba

void permutation_string(string input, string output){
    if(input.length() == 0 ){
        cout << output << endl;
        return;
    }

    for(int i=0; i<=output.length(); i++){
        cout << i << " " << input.substr(1)<< " xxx " << output.substr(0,i) << "yyy "<< input[0] << " zzz "<<output.substr(i) << endl ;
        permutation_string(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));
    }
}

void subset_arr(int arr[],int size, int output[]){
    if(size==0){

        return;
    }

    subset_arr(arr+1,size-1,output);
    for(int i=0;i<size;i++){
        output[i+size] =output[i] + arr[i];
        
    }
}


int main(){
    // string s;
    // cin >> s;
    // permutation_string(s,"");
    // cout << s.substr(0,2) << " " << s.substr(0) << endl;
    int arr[3] = {2,3,4};
    int output[8];
    subset_arr(arr ,3, output);
    for(int i=0;i<8;i++){
        cout << output[i] << endl;

    }
    
}