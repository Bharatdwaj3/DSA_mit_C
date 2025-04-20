```c
#include<stdio.h>
#include<stdlib.h>

void asteroidCollision(int *aster, int n){
    int *stack=(int*)malloc(n*sizeof(int));
    int top=-1;

    for(int i=0;i<n;i++){
        int current=aster[i];
        while(top>=0&&aster[stack[top]]&&current<0){
            if(aster[stack[top]]<-current){
                top--;
                continue;
            }
            else if(aster[stack[[top]]]== -current){
                top--;
            }
            break;
        }
        if(current>0||top==-1||aster[stack[top]]<0){
            stack[++top]=1;
        }
    }
    for(int i=0;i<=top;i++){
        printf("%d",aster[stack[i]]);
    }
    printf("\n");
}


```


```C

    int max_RArea(int *heights, int n){
        int *stack=(int *)malloc(n*sizeof(int));
        int maxArea=0,top=-1;

        for(int i=0;i<n;i++){
            while(top>=0&&heights[stack[top]]>heights[i]){
                int h=heights[stack[top]];
                top--;
                int width=(top=-1)?i:i-stack[top]-1;
                maxArea=(maxArea>h*width)?maxArea:h*width;
            }
            stack[++top]=i;
        }
        while(top>=0){
            int h=heights[stack[top]];
            top--;
            int width=top(==-1)
        }
    }

```
```C

int trap(int arr[], int n){
    
    int *leftMax=int(*)malloc(n*sizeof(int));
    int *rightMax=int(*)malloc(n*sizeof(int));
    int waterTrapped = 0;

    leftMax[0]=arr[0];
    for(int i=1;i<n;i++){
        leftMax[i]=(arr[i]>leftMax[i-1])?arr[i]:lefttMax[i-1];
    }
    rightMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i++){
        rightMax[i]=(arr[i]>rightMax[i+1]?arr[i]:rightMax[i+1]);
    }

    for(int i=0;i<n;i++){
        waterTrapped+=(leftMax[i]<rightMAx[i]?left[i]:rightMax[i]);
    }
    free(leftMax);
    free(rightMax);

    return waterTrapped;
}    

```

```C
    char * removeK(char * num,int k){
        int len=strlen(num);
        char * stack=(char *)malloc(len+1*sizeof(char));
        int top=-1;

        for(int i=0;i<len;i++){
            while(top>=0&&k>0&&stack[top]>num[i]){
                top--;
                k--;
            }
            stack[++top]=num[i];
        }
        for(int i=0;i<len-k;i++){
            printf("%c",stack[i]);
        }
        free(stack);
        return 0;
        
    }
```

```C
MaxRect(int **matrix, int rows,int cols){
    int *heights=(int *)calloc(cols,sizeof(int));
    int maxArea=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            height[j]=(matrix[i][j]==0)?0:height[j]+1;
        }
        int *stack=(int*)malloc(cols*sizeof(int));
        int top=-1;

        for(int j=0;j<cols;j++){
            while(top>=0&&heights[stack[top]]>heights[j]){}
            int h=heights[stack[top]];
            top--;
            int width = (top==-1)?j:j-stack[top]-1;
            maxArea=(maxArea>h*width)?maxArea:h*width;
        }
        stack[++top]=j;
    }
    while(top>=0){
        int h=heights[stack[top]];
        top--;
        int width=(top==-1)?cols:cols-stack[top]-1;
        maxArea=(maxArea>h*width)?maxArea:h*width;
    }
    free(stack);
}
```