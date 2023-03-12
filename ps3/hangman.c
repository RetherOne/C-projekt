#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
    int result = 0, sec_len = strlen(secret);

    for (int i = 0; sec_len > i; i++){
        for (int j = 0; strlen(letters_guessed) > j; j++){
            if (secret[i] == letters_guessed[j]){
                result++;
                break;
            }
        }
    }
    if (result == sec_len){
        return 1;
    }
    else{
        return 0;
    }
}

int is_letter_guessed(const char word[], char letter[]){
    for (int i = 0; strlen(word) > i; i++){
        if(word[i] == letter[0]){
            return 1;
        }
    }
    return 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int sec_len = strlen(secret);
    int i = 0;
    for (i = 0; 20 > i; i++){
        guessed_word[i] = '\0';
    }
    for(i = 0; i < sec_len; ++i){
        guessed_word[i] = '_';
    }
    for (i = 0; sec_len*2 > i; i++){
        for (int j = 0; strlen(letters_guessed) > j; j++){
            if (secret[i] == letters_guessed[j]){
                guessed_word[i] = secret[i];

            }
        }
    }    
}

void del_simv(char masiv[], char del[]){
    for (int i = 0; i < strlen(masiv); i++){
        if( masiv[i] == del[0] ){
            for(;i < strlen(masiv); i++){
                masiv[i] = masiv[i + 1];
            }
            break;
        }
    }
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
    int i = 0;
    char abc[]= "abcdefghijklmnopqrstuvwxyz";

    for(; i < strlen(letters_guessed); i++){
        char letter[1];
        letter[0] = letters_guessed[i];
        del_simv(abc, letter);
    }
    for(i = 0; i <= strlen(abc); i++){
        available_letters[i] = abc[i];
    }
 }

void hangman(const char secret[]){
    int live = 8;
    char available_letters[30] = "abcdefghijklmnopqrstuvwxyz";
    char abc[30] = "abcdefghijklmnopqrstuvwxyz";
    char letters_history[30] = "";
    char guessed_word[20];
    char *answers[4] = {"Good guess:", "Oops! You've already guessed that letter:", "Oops! That letter is not in my word:"};
    printf("Welcome to the game, Hangman!\nI am thinking of a word that is %li letters long.\n-------------\n", strlen(secret));

    while( live != 0){
        
        printf("You have %d guesses left.\n", live);
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: ");

        char letter[30];
        scanf("%s", letter);
        letter[0] = tolower(letter[0]);
        if (strcmp(letter, secret) == 0){
            printf("Congratulations, you won!\n");
            break;
        }
        else if(strlen(letter) > 1){
            printf("Sorry, bad guess. The word was %s.", secret);
            break;
        }

        if(is_letter_guessed(secret, letter)){
            int i = 0;
            if(is_letter_guessed(letters_history, letter)){
                i = 1;
            }
            letters_history[strlen(letters_history)] = letter[0];
            get_available_letters(letters_history, available_letters);
            get_guessed_word(secret, letters_history, guessed_word);
            printf("%s ", answers[i]);
            for (i = 0; strlen(guessed_word) - 1 > i; i++){
                printf("%c ", guessed_word[i]);
            }
            printf("%c\n", guessed_word[strlen(guessed_word) - 1]);
        }
        else{
            int i = 0;
            if (is_letter_guessed(letters_history, letter)){
                    i = 1;
                    live++;
                }
                else{
                    i = 2;
                }
            letters_history[strlen(letters_history)] = letter[0];
            get_available_letters(letters_history, available_letters);
            get_guessed_word(secret, letters_history, guessed_word);
            if (!is_letter_guessed(abc, letter)){
                printf("Oops! '%s' is not a valid letter: ", letter);
                live++;
            }
            else{
                printf("%s ", answers[i]);
            }
            for (i = 0; strlen(guessed_word) - 1 > i; i++){
                printf("%c ", guessed_word[i]);
            }
            printf("%c\n", guessed_word[strlen(guessed_word) - 1]);
            live--;
        }

        printf("-------------\n");

        if (is_word_guessed(secret, letters_history)){
            printf("Congratulations, you won!\n");
            break;
        }

    }
    if(live == 0){
        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
    }
}
