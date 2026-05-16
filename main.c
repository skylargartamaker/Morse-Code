#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TOTAL_CHARS 36

char std_alphabet[TOTAL_CHARS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                         'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                         'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                         '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

char* morse_alphabet[TOTAL_CHARS] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                            "....", "..", ".---", "-.-", ".-..", "--", "-.",
                            "---", "--.-", ".-.", "-", "..-", "...-", "-.--",
                            "--..", ".----", "..---", "...--", "....-", ".....",
                            "-....", "--...", "---..", "----.", "-----"};

char* std_to_morse(char letter)
{
  for (int i = 0; i < TOTAL_CHARS; i++)
  {
    if (toupper(letter) == std_alphabet[i])
    {
      return morse_alphabet[i];
    }
  }

 return " ";
}

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

int main()
{
  char morse[16];
  printf("Enter a letter in morse: ");
  scanf("%s", morse);

  char std_alpha = morse_to_std(morse);

  if (std_alpha == ' ')
  {
    printf("Not a valid letter\n");
  }
  else
  {
    printf("%c\n", std_alpha);
  }
  
  
  return 0;
}
