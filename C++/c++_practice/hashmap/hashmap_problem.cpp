#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

// void removeduplicates(char *s){
//     unordered_map<char, int> exists;
//     int index = 0;
//     for(int i=0; s[i]!='\0';i++){
        
//         if(exists[s[i]]==0){
//             s[index++] = s[i];
//             exists[s[i]]++;
//         }
        
//     }
//     s[index] = '\0';
//     // return s;
// }
char* removeduplicates(char *s){
    unordered_map<char, int> exists;
    int index = 0;
    for(int i=0; s[i]!='\0';i++){
        
        if(exists[s[i]]==0){
            s[index++] = s[i];
            exists[s[i]]++;
        }
        
    }
    s[index] = '\0';
    return s;
}

//longestconsequative sequence

vector<int> longestconsequativesequence(int *arr, int n){
    unordered_map<int,int> a;
    vector<int> ans;

    for(int i=0;i<n;i++){
        a[arr[i]] =1;
    }

    int max =0;
    int k =0;

    for(int i = 0; i<n;i++){
        int x = arr[i];
        int j = 0;
        if(a.count(x-1)>0){
            continue;
        }
        while(a.count(x)>0){
            x++;
            j++;
        }

        if(j>max){
            max = j;
            k = arr[i];
        }

    }

    for(int i=0; i<max;i++){
        ans.push_back(k);
        k++;
    }
    return ans;
}
int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
  // Write your code here
 
    unordered_map<int,int> m;

    
    int length=0;
    int sum=0;
    
     for(int i=0 ;i<n;i++)
    {
        sum+=arr[i];
        
        if(arr[i]==0 && length ==0)
            length =1;
        
        if(sum==0)
            length= i;
        
		if(m.count(sum)>0)
        {
            length=max(length,i-m[sum]);
        }
        else
        {
            m[sum]=i;
        }
    }
    
    return length;
}
int main(){

    // char s[] = "abbc";
    // char *g = removeduplicates(s);
    // for(int i=0; g[i]!='\0';i++){

    //     cout << g[i] ;
    // }
    int arr[] = {2,3,-3,-4,2,5,-4};
    cout << lengthOfLongestSubsetWithZeroSum(arr, 7) << endl;


}