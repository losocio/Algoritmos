#include<iostream>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

void ordenarInsercion(int x[], int len){
	int temp;
    //Itero todo el array
	
    for(int i=1;i<len;i++){
        //Si es mas pequeño que el anterior, se hace el desplazamiento y finalmente la insercion
        
		int j=i-1;
		while(x[i]<x[j]){

			j--;
		}
		if(x[i-1]>x[i]){
        
        }
		
		for(int k=0;k<len;k++) cout<<x[k]<<" ";
		cout<<endl;
    }
}


int main(){
	int n;
	cin>>n;
	int *x=new int[n];

	for(int i=0;i<n;i++) cin>>x[i];

	ordenarInsercion(x,n);
}


