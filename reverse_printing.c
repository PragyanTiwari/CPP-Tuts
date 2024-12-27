// printing integer in reverse order using recursion

#include <stdio.h>

// defining recursive function
int print_num(int x){
    if (x>0){
        printf("%d \n",x);
        return get_reverse_num(x-1);
    }
    return 0;
}


int main(){
    int num;
    printf("enter the number : ");
    scanf("%d", &num);
    return print_num(num);
}

/*

-------OUTPUT----------
enter the number : 5
5 
4 
3 
2 
1 


=== Code Execution Successful ===

*/
