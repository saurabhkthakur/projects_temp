#include <iostream>
using namespace std;


int partition(int arr[], int l, int r){



    int x = arr[l];
    int small_count=0;
    for(int i=l;i<=r;i++){
        if(arr[i]<x)
            small_count++;
    }
    cout << l << " ss" << r << endl;
    cout << x << " " << small_count << endl;

    arr[l]=arr[l+small_count];
    arr[l+small_count]=x; 

    int i=l;
    int j =r;
    int temp=0;
    while(i<l+small_count && j > l+small_count){

        if(arr[i] < x && arr[j] > x){
            i++;
            j--;
        }
        else if(arr[i]<x && arr[j] < x){
            i++;
        }
        else if(arr[i]>= x && arr[j] <= x){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j]=temp;
            i++;
            j--;

        }
        else{
            j--;
        }
    }
    
     for(int f=0;f<5;f++){
        cout << arr[f] << " ";
    }
    cout << endl;

   
    return l+small_count;

}


void quicksort(int arr[], int l, int r){

    if(l<r){

        int m = partition(arr,l,r);
        quicksort(arr, l, m-1);
        quicksort(arr, m+1,r);

    }
}

int main(){

    int arr[5]= {5,5,5,9,1};
    
    

    quicksort(arr,0,4);
    cout <<"ss"<< endl;
    for(int i=0;i<5;i++){
        cout << arr[i] << endl;

    }
    
}