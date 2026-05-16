#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CHARS 36

char std_alphabet[TOTAL_CHARS] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q',
    'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

char* morse_alphabet[TOTAL_CHARS] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--","--..",
    ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----"
};

char morse_to_std(char* morse)
{
    for (int i = 0; i < TOTAL_CHARS; i++)
    {
        if (strcmp(morse, morse_alphabet[i]) == 0)
        {
            return std_alphabet[i];
        }
    }

    return ' ';
}

void practice_loop()
{
    printf("Welcome to morse code practice\n");
    printf("Type 'quit' to exit.\n\n");

    char user_guess[16];
    char letter;

    while (1)
    {
        int random_num = rand() % TOTAL_CHARS;
        letter = std_alphabet[random_num];

        printf("What is %c?\n", letter);

        scanf("%15s", user_guess);

        if (strcmp(user_guess, "quit") == 0)
        {
            break;
        }

        char validate = morse_to_std(user_guess);

        if (validate == letter)
        {
            printf("Correct!\n\n");
        }
        else
        {
            printf("Incorrect. Correct answer: %s\n\n",
                   morse_alphabet[random_num]);
        }
    }
}

int main()
{
    srand(time(NULL));
    practice_loop();

    return 0;
}
