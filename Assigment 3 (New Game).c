#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    while (1) {   // restart loop(if user choose the option 1)

        srand(time(0));

        int x = 1;                       // player lane (0-2)
        int step = 0;                    // coin vertical position
        int coinPos = rand() % 3;        // which lane coin falls in
        int score = 0;
        int lives = 3;
        int speed = 120;

        // --- GAME LOOP ---
        while (1) {

            // ---- INPUT ----
            if (_kbhit()) {
                char ch = getch();

                if (ch == 75 && x > 0)    // left arrow
                    x--;

                if (ch == 77 && x < 2)    // right arrow
                    x++;
            }

            // ---- DRAW ----
            system("cls");
            printf(" SCORE: %d   LIVES: %d\n", score, lives);
            printf("|-----------|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {

                    if (coinPos == 0)
                        printf("| O        |\n");

                    else if (coinPos == 1)
                        printf("|     O    |\n");

                    else if (coinPos == 2)
                        printf("|        O |\n");

                } else {
                    printf("|           |\n");
                }
            }

            // ---- PLAYER ----
            if (x == 0)
                printf("| ^        |\n");
            else if (x == 1)
                printf("|     ^    |\n");
            else if (x == 2)
                printf("|        ^ |\n");

            // ---- CHECK CATCH / MISS ----
            if (step == 10) {

                if (x == coinPos) {
                    score++;               // caught
                } else {
                    lives--;               // missed
                }

                if (lives == 0) {
                    printf("\nGAME OVER! Final Score: %d\n\n", score);
                    break;
                }
            }

            Sleep(speed);

            // Move coin downward
            step++;

            // Reset coin when reaches bottom
            if (step > 10) {
                step = 0;
                coinPos = rand() % 3;

                // increase speed
                if (speed > 40)
                    speed -= 5;
            }
        }

        // ------------- GAME OVER MENU -------------
        int choice;
        printf("1. Restart\n");
        printf("2. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 2)
            break;
    }

    return 0;
}

