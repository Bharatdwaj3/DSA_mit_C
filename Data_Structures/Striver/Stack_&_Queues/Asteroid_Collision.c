#include <stdio.h>
#include <stdlib.h>

void asteroidCollision(int *asteroids, int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        int current = asteroids[i];

        // Handle asteroid collisions
        while (top >= 0 && asteroids[stack[top]] > 0 && current < 0)
        {
            if (asteroids[stack[top]] < -current)
            {
                top--; // Pop the asteroid from the stack
                continue;
            }
            else if (asteroids[stack[top]] == -current)
            {
                top--; // Both asteroids destroy each other
            }
            break;
        }

        // If no collision or the asteroid survived, push it to the stack
        if (current > 0 || top == -1 || asteroids[stack[top]] < 0)
        {
            stack[++top] = i;
        }
    }

    // Print the remaining asteroids in the stack
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", asteroids[stack[i]]);
    }
    printf("\n");

    free(stack);
}

int main()
{
    int asteroids[] = {5, 10, -5};
    int n = sizeof(asteroids) / sizeof(asteroids[0]);
    asteroidCollision(asteroids, n);
    return 0;
}
