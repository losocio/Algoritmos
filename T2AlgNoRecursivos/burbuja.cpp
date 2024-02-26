#include <iostream>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

int printArray(int array[], int len){
    
    for(int i=0;i<len;i++){
        cout<<array[i];
    }
    cout<<endl;
    return 0;
}

void ordenarBurbuja(int x[], int len){
	int temp;
    int done=1;

/*
    while(done){
        //done=0;
        for(int i=0;i<len;i++){
            if(x[i]>x[i+1]){
               temp = x[i];
               x[i] = x[i+1];
               x[i+1] = temp;
               //done=1;
            }
            
        }
        for(int k=0;k<len;k++) cout<<x[k]<<" ";
      	cout<<endl;
    }*/

	
	//Itero por todo el array empezando por el segundo elemento
	for(int i=0;i<len;i++){
		for(int j=i;j<len-1;j++){
			//Si el elemento es anterior es mayor lo cambio
			if(x[j]>x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
			
			for(int k=0;k<len;k++) cout<<x[k]<<" ";
			cout<<endl;
		}
	}
}


int main(){
 	int n;
 	cin>>n;
 	int *x=new int[n];
 	for(int i=0;i<n;i++) cin>>x[i];

	int size = sizeof(x)/sizeof(int);
	//cout<<"len "<<size<<endl;
	//printArray(x, size);
 	ordenarBurbuja(x,n);

	return 0;
}
