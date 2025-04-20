#include <stdio.h>
#include <stdlib.h>



unsigned long long fact(int num){
    if(num==0)
        return 1;
    else
        return num*fact(num-1);
}

int main()
{
    int num;
    long factorial;

    printf("%d Enter any Number: ");
    scanf("%d", &num);

    factorial = fact(num);

    printf("Factorial % is %llu", num, factorial);

    return 0;
}