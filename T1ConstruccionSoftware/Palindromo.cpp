#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv){

    char palindrome[20];
    cin >> palindrome;
    int length = strlen(palindrome);
    int res;
    
    for(int i = 0; i<length; i++){
        if(palindrome[i] == palindrome[length-i-1]){
            res=1;
        }
        else{
            res=0;
            break;
        }
    }

    cout<<res;

    return 0;
}