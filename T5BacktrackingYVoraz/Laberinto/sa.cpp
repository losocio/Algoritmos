
int main(){
    // array enumerado 1-10
    int *sa=new int[10];
    for(int i=0;i<10;i++){
        sa[i]=i;
    }
    // matriz
    int **sa2=new int*[10];
    for(int i=0;i<10;i++){
        sa2[i]=new int[10];
        for(int j=0;j<10;j++){
            //enumerar 1-10 todas la columnas
            sa2[i][j]=j;
        }
    }
}