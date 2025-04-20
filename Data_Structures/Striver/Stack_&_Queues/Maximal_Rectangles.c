#include <stdio.h>
#include <stdlib.h>

int maximalRectangle(int **matrix, int rows, int cols)
{
    int *heights = (int *)calloc(cols, sizeof(int));
    int maxArea = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            heights[j] = (matrix[i][j] == 0) ? 0 : heights[j] + 1;
        }

        int *stack = (int *)malloc(cols * sizeof(int));
        int top = -1;

        for (int j = 0; j < cols; j++)
        {
            while (top >= 0 && heights[stack[top]] > heights[j])
            {
                int h = heights[stack[top]];
                top--;
                int width = (top == -1) ? j : j - stack[top] - 1;
                maxArea = (maxArea > h * width) ? maxArea : h * width;
            }
            stack[++top] = j;
        }

        while (top >= 0)
        {
            int h = heights[stack[top]];
            top--;
            int width = (top == -1) ? cols : cols - stack[top] - 1;
            maxArea = (maxArea > h * width) ? maxArea : h * width;
        }

        free(stack);
    }

    free(heights);
    return maxArea;
}

int main()
{
    int matrix[4][4] = {
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 0}};
    int rows = 4, cols = 4;
    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        mat[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }

    printf("Maximal rectangle area: %d\n", maximalRectangle(mat, rows, cols));

    for (int i = 0; i < rows; i++)
    {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
