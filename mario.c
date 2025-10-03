#include <stdio.h>

int main() {
    int height;

    // Get valid height from user
    do {
        printf("Height: ");
        if (scanf("%d", &height) != 1) { 
            while (getchar() != '\n'); // Clear invalid input
            height = -1; 
        }
    } while (height < 1 || height > 8);

    // Print the pyramids
    for (int i = 1; i <= height; i++) {
        // Print spaces for left pyramid
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        // Print left pyramid hashes
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        // Print gap of two hashes 
        printf("  ");
        // Print right pyramid hashes
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
