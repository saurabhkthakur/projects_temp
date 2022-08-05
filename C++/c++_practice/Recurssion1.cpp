/* e will use recrusion jab kis bade cheeze ka 
solution chote pe depend karta h */

#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n){
    int smallout = factorial(n-1);
    return n * smallout;
}

int first_index(int arr[], int size,int x ){
    
    /* first index of array using recurssion */
    if(arr[0] == x)
        return 0 ;
    
    if(size < 1){
        return -1;
    }

    int ans = first_index(arr+1, size-1,x);
    if(ans<0)
        return ans;
    else
        return ans+1;
}

int last_index(int arr[], int size, int x){
    /* recursion using last index of array */
    if(size < 1)
        return -1;
    
    int ans = last_index(arr+1, size-1, x);
    // cout << ans << " " << size << " " << ans <<  endl;
    if (ans < 0 )
    {
        if(arr[0]==x)
            return ans+1;
        else
            return -1;
    }
    else
        return ans+1;
    
}

int all_indices(int arr[], int size, int x,int output[],int i){
    
    if(size < 1)
        return -1;

    if(arr[0]==x)
        return 0;


    int ans = all_indices(arr+1, size-1,x,output,i);

    if(ans < 0){
        if(arr[0]==x)
            return ans+1;
        else
            return -1;

    }
        


     
}




int main(){
    
    int arr[7] = {3,4,3,6,5,7,5};
    int size =7;
    int target = 5;
    int output = last_index(arr, size, target);
    cout << output << endl;


}