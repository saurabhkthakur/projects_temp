#include <iostream>
using namespace std;


void consecutive(char s[]){

    if(s[0] == '\0')
        return;

    if(s[0]==s[1]){
        int j = 1;
        for(; s[j]!='\0';j++){
            s[j-1]=s[j];
        }
        s[j-1]=s[j];
        consecutive(s);

    }
    else
    {
        consecutive(s+1);
    }
}

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

        s[i-1]=s[i];
        removex(s);
    }

}

int length(char s[]){

    if(s[0] =='\0')
        return 0;
    
    int ans = length(s+1);
    
    return ans+1;
}


int main(){
    char str[100];
    cin >> str;

    int l = length(str);
    // cout << l << endl;
    // removex(str);aa
    // l = length(str);
    // cout << l << endl;
    consecutive(str);
    l = length(str);
    cout << l <<" " << str << endl;

}