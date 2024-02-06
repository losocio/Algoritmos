#include <iostream>
using namespace std;

int main(int argc, char** argv){

    int num;
    cin >> num;
    int sum = 0;

    //6 -> 2 + 4 + 6 = 12
    for(int i=0; i<num+1; i++){
        //Impar
        if(num%2){
            sum += i+1;
        }
        //Par
        else{
            sum += i;
        }
        i++;
    }

    cout << sum;

    return 0;
}