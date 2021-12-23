//lets you place compiler instuctions in your source code
//lets you request special behavior from the compiler

#pragma GCC poison printf

int main(){
    printf("Hello");    //will produce an error since printf is poisoned
    return 0;
}