#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int *heights, int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int maxArea = 0, top = -1;

    // Traverse all bars of the histogram
    for (int i = 0; i < n; i++)
    {
        // Process the stack when the current height is less than the height of the bar at the top of the stack
        while (top >= 0 && heights[stack[top]] > heights[i])
        {
            int h = heights[stack[top]];
            top--;
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = (maxArea > h * width) ? maxArea : h * width;
        }
        stack[++top] = i; // Push current bar to the stack
    }

    // Now pop the remaining bars from the stack and calculate area
    while (top >= 0)
    {
        int h = heights[stack[top]];
        top--;
        int width = (top == -1) ? n : n - stack[top] - 1;
        maxArea = (maxArea > h * width) ? maxArea : h * width;
    }

    free(stack);
    return maxArea;
}

int main()
{
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    printf("Largest rectangle area: %d\n", largestRectangleArea(heights, n));
    return 0;
}
