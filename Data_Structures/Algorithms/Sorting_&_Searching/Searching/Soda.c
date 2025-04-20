void insertion_sort(int arr[], int n){
    int i,j,key;   
    for(i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }    
        arr[j+1]=key;
    }
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for(i=0;i<n;i++){
        for (j = 0; j < n - i - 1; i++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selection_sort(int arr[], int n)
{
    int i, j, min_index,temp;
    for (i = 0; i < n; i++)
    {
        min_index=i;
        for (j = i+1; j < n - 1; i++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index=j;
            }
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}