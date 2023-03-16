#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    int n = get_size();
    print_grid(n);
}

// Get size of grid
int get_size(void)
{
    int n;
    do {
        n = get_int("Size: ");
    } while(n < 1);
    return n;
}

// Print grid of bricks
void print_grid(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
}