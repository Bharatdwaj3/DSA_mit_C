
/*#include<stdio.h>

int main(){

    int i,n;

    printf("Enter a number : ");
    scanf("%d",&n);

    printf("The Number list : ");
    for(i=0;i<n+1 ;i++){
        printf("%d ",i);
    }
}*/

/*#include<stdio.h>

void num(int n){
    
    

    printf("The Number list : ");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", i);
    }
}

int main(){

    int n;
    
    printf("Enter the number: ");
    scanf("%d", &n);
    
    num(n);

    return 0;
}*/


#include<stdio.h>

void num(int n){
    if(n<0)
        return ;
    num(n-1);
        printf("%d ",n);
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    printf("The Number list: ");
    num(n);
}


