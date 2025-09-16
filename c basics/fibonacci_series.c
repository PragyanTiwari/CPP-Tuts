// printing fibonacci series recursively

#include <stdio.h>

// defining recursive function
int fib(int x){
    if (x==0){
        return 0;
    }
    else if (x==1){
        return 1;
    }
    return fib(x-1) + fib(x-2);
}

int main() {
    
    int num, i=0;
    printf("enter the number : ");
    scanf("%d",&num);
    
    while (i<=num){
        printf("%d \n",fib(i));
        i++;
    }
    return 0;
}

/*

-------OUTPUT----------
enter the number : 9
0 
1 
1 
2 
3 
5 
8 
13 
21 
34 

*/
