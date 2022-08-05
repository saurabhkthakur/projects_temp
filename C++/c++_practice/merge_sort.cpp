#include <iostream>
using namespace std;


void merge(int arr[], int l ,int m, int r){
    int i = l;
    int j = m+1;
    int k = l;
    int temp[6];

    while(i <= m && j <= r){

        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i <=m){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }

    
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
  }

  for(int f=0; f<6;f++){
        cout << arr[f] << "--- " << l << " ---" << r << " " << endl;
    }
  

}

void mergesort(int arr[], int l , int r){

  

    if(l < r){
        int mid = l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }


}

void display(int *arr){

    // cout << sizeof(arr) / sizeof(arr[0]);
    // cout << sizeof(arr) << " " << sizeof(arr[0]) << " " <<  sizeof(arr)/ sizeof(arr[0]);

}



int main(){
    int arr[6] = {5,6,4,3,8,1};
    // cout << sizeof(arr) << " " << sizeof(arr[0]) << " " <<  sizeof(arr)/ sizeof(arr[0]);
    // display(arr);
    mergesort(arr,0,5);
    for(int i=0; i<6;i++){
        cout << arr[i] << " ";
    }

}