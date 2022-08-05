#include <iostream>
using namespace std;

// int binary_search(int arr[],int start,int end,int target){
//     if(end>=start){
            
//         int mid = start+(end-start)/2;
//     // cout << arr[mid] << " " << target << endl;
//         if(arr[mid]== target){

//             return mid;
//         }
//         else if(target< arr[mid]){
//             return binary_search(arr, start, mid-1,target);
//         } 
//         else
//             return binary_search(arr,mid+1,end,target);

//     }

//     return -1;


// }

// bool check_ab(string s){

//     if(s.length()<=1){
//        if(s[0] =='a')
//             return true;
//         if(s.length()==0){
//             return true;}
//         else
//             return false;
        
//     }
//     cout << " dddd" << s[0] << endl;
//     if(s[0]=='a'){
//         string d = s.substr(1,1);
//         bool f = d =="a";
//         string e = s.substr(1,2);
//         bool g = e=="bb";
//         cout << d << " " << f << " " << e <<endl;
//         if(f){
//             cout << s.substr(2) << endl;
//             return check_ab(s.substr(2));
//         }
//         else if(g){
//             return check_ab(s.substr(3));
//         }
        
//     }
    
//     return false;
    
// }

bool check_abb(char input[], int startIndex){
    if(input[startIndex]=='\0')
        return true;
    if(input[startIndex]!= 'a')
        return false;
    if(input[startIndex+1] != '\0' && input[startIndex+2]!= '\0'){
        if(input[startIndex+1]=='b' && input[startIndex +2]=='b'){
            return check_abb(input,startIndex+3);
        }
    }
    return check_abb(input, startIndex +1);
}



#include <string>
 
void printPermutationsHelper(string input, string output){ 
    if(input.length() == 0){
        cout << output << endl; 
        return;
    }
    for(int i = 0; i<= output.length(); i++){
        printPermutationsHelper(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));
    }
}
void printPermutations(string input){ 
    printPermutationsHelper(input, "");
    return;
}


int main(){


    // char s[100];
    // cin >> s;
    // string d = s.substr(2);
    // bool f = d =="bb" ;
    string s;
    cin >> s;
    
    printPermutations(s);

    // int n;
    // cin >> n;
    // int arr[5]= {3,4,5,6,7};
    // int target = 7;
    // int start = 0;
    // int end = 5;

    // cout << binary_search(arr,start,end,target);

}