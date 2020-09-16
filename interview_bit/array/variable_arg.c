
#include <stdio.h>
#include <stdarg.h> 

int sum(int arg_count, ...){
    va_list ap; 
    va_start(ap, arg_count); 
    int res = 0;
    for (int i = 1; i <= arg_count; i++) {
        int val = va_arg(ap, int);
        printf("%d ", val); 
        res += val;
    }
    printf("\n");
    va_end(ap); 
    return res;
}

int main(){
    printf("%d", sum(5, 1, 2, 3, 4, 5));
}