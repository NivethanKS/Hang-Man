#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 7
#define WORD_SIZE 50

void draw_hangman(int tries);

int main() {
    char word[WORD_SIZE] = "programming";
    char guessed_word[WORD_SIZE];
    int tries = 0;
    int found_letter = 0;
    int word_length = strlen(word);

    for (int i = 0; i < word_length; i++) {
        guessed_word[i] = '-';
    }
    guessed_word[word_length] = '\0';

    while (tries < MAX_TRIES && strcmp(word, guessed_word) != 0) {
        char guess;
        found_letter = 0;

        printf("Guessed word: %s\n", guessed_word);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        for (int i = 0; i < word_length; i++) {
            if (tolower(word[i]) == tolower(guess)) {
                guessed_word[i] = word[i];
                found_letter = 1;
            }
        }

        if (!found_letter) {
            tries++;
            draw_hangman(tries);
        }
    }

    if (strcmp(word, guessed_word) == 0) {
        printf("Congratulations, you guessed the word: %s\n", word);
    } else {
        printf("You lost! The word was: %s\n", word);
    }

    return 0;
}

void drawhangman(int tries) {
    printf("  __\n");
    printf(" |    |\n");
    printf(" |    %c\n", tries > 0 ? 'O' : ' ');
    printf(" |   %c%c%c\n", tries > 1 ? '/' : ' ', tries > 2 ? '|' : ' ', tries > 3 ? '\' : ' ');
    printf(" |   %c %c\n", tries > 4 ? '/' : ' ', tries > 5 ? '\' : ' ');
    printf("|_\n\n");
}
