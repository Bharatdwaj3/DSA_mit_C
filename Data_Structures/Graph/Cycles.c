#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int rep = 0;

    // Check each element for uniqueness
    for (int i = 0; i < n; i++) {
        int isUnique = 1;

        // Check if arr[i] is repeated
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = 0; // Found a duplicate
                break;
            }
        }

        if (isUnique) {
            rep++;
            if (rep == 4) {
                printf("The 4th non-repeating element is: %d\n", arr[i]);
                return 0;
            }
        }
    }

    printf("There are less than 4 non-repeating elements in the array.\n");
    return 0;
}
