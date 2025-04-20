#include<stdio.h>

int reverse(int num, int rev){
    if(num==0)
     return rev;
    return reverse(num/10,rev*10+num%10);
}

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int reversedNumber = reverse(n, 0); // Get the reversed number

    printf("Reversed Number: %d\n", reversedNumber);
}