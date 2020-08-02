int sumardosint(int x,int j){
    
    int suma;
    suma = x + j;

    return suma;
}
int fibonnaci(int nfibonacci){
    int ifibonacci,jfibonacci,tfibonacci,kfibonacci;
    ifibonacci = 0;
    jfibonacci = 1;
    for(kfibonacci = 1; kfibonacci < nfibonacci; kfibonacci = kfibonacci + 1){
        tfibonacci = ifibonacci + jfibonacci;
        ifibonacci = jfibonacci;
        jfibonacci = tfibonacci;    
    }
    return jfibonacci;
}
int main(){
    int n,answer,i;
    n=10;
    answer = fibonnaci(n);
    print(answer);
}chao