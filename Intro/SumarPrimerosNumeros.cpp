#include <iostream>
using namespace std;

int main(int argc, char** argv){

    int num;
    cin >> num;
    int sum = 0;
    
    for(int i = 1; i<num+1; i++){
        sum = sum + i;
    }

    cout << sum;
    return 0;
}

