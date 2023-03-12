#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ballsortpuzzle.h"
#include <time.h>
#include <curses.h>

void del_simv(char masiv[], int del){
    for(int i = del;i < strlen(masiv); i++){
            masiv[i] = masiv[i + 1];
    }
}

void generator(const int rows, const int columns, char field[rows][columns]){
    int i, j;
    char simv[rows * columns];
    srand(time(NULL));

    for (i = 0; (rows * columns) > i; i++){
        simv[i] = '\0';
    }

    for(i = 0; i < rows * (columns - 2); i++){
        simv[i] = '@';
        if(columns > 3){
            i++;
            simv[i] = '*';
        }
        if(columns > 4){
            i++;
            simv[i] = '+';
        }
        if(columns > 5){
            i++;
            simv[i] = '^';
        }
        if(columns > 6){
            i++;
            simv[i] = 'A';
        }
        if(columns > 7){
            i++;
            simv[i] = 'B';
        }
        if(columns > 8){
            i++;
            simv[i] = 'C';
        }
    }
    //printf("%s\n", simv);
    int c_num = rand() % columns;
    int c2_num = rand() % columns;
    while (c2_num == c_num){
        c2_num = rand() % columns;
    }
    

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            if(strlen(simv) != 0  && j != c_num && j != c2_num){
                int r_num = rand()%strlen(simv);
                field[i][j] = simv[r_num];
                del_simv(simv, r_num);
            }
            else{
                field[i][j] = ' ';
            }
        }
    }
    //printf("last:%s\n", simv);
}
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){
    int first_simv_in_colum_to = 0, first_simv_in_colum_from = 0, colum = x - 1, colum2 = y - 1, i = 1;
    

    for(i = 0; i < rows; i++){
        if(field[i][colum] == ' '){
            first_simv_in_colum_from++;
        }
    }

    for(i = 1; i < rows; i++){
        if(field[i][colum2] == ' '){
            first_simv_in_colum_to++;
        }
    }
    //printf("from:%i\n", first_simv_in_colum_from);
    //printf("to:%i\n", first_simv_in_colum_to);
    if ((first_simv_in_colum_to + 1 == rows || field[first_simv_in_colum_from][colum] == field[first_simv_in_colum_to + 1][colum2]) && x != y && field[0][colum2] == ' ' && field[rows-1][colum] != ' '){
        field[first_simv_in_colum_to][colum2] = field[first_simv_in_colum_from][colum];
        field[first_simv_in_colum_from][colum] = ' ';
    }
}
bool check(const int rows, const int columns, char field[rows][columns]){
    int result = 0, same = 0;
    for(int i = 0; i < columns; i++){
        same = 0;
        for(int j = 0 ; j < rows; j++){
            if (field[j][i] == field[0][i]){
                same += 1;
            }
        }
        if(same == rows){
            result++;
        }
    }
    if(result == columns){
        return true;
    }
    else{
        return false;
    }
}


void game_field(const int rows, const int columns, char field[rows][columns]){

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);

    move((LINES / 2) - (rows / 2), COLS / 2 - 16);
    for(int i = 0; i < rows; i++){
        printw("%i", i+1);
        for (int j = 0; j < columns; j++){
            attron(COLOR_PAIR(8));
            printw("| ");
            attroff(COLOR_PAIR(8));

            if (field[i][j] == '@'){
                attron(COLOR_PAIR(1));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(1));
            }
            else if(field[i][j] == '*'){
                attron(COLOR_PAIR(2));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(2));
            }
            else if (field[i][j] == '+'){
                attron(COLOR_PAIR(3));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(3));
            }
            else if (field[i][j] == '^'){
                attron(COLOR_PAIR(4));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(4));
            }
            else if (field[i][j] == 'A'){
                attron(COLOR_PAIR(5));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(5));
            }
            else if (field[i][j] == 'B'){
                attron(COLOR_PAIR(6));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(6));
            }
            else if (field[i][j] == 'C'){
                attron(COLOR_PAIR(7));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(7));
            }
            else if (field[i][j] == ' '){
                attron(COLOR_PAIR(8));
                printw("%c", field[i][j]);
                attroff(COLOR_PAIR(8));
            }

            attron(COLOR_PAIR(8));
            printw(" |");
            attroff(COLOR_PAIR(8));
        }
        move((LINES / 2) - (rows / 2) + i + 1, COLS / 2 - 16);
    }

    for (int i = 0; i < columns; i++){
        printw("  ---");
    }

    printw("\n");

    move((LINES / 2) - (rows / 2) + rows + 1, COLS / 2 - 16);
    for (int i = 0; i < columns; i++){
        printw("   %i " , i + 1);
    }
}

void ball_sort_puzzle(){
        initscr();
        refresh();
        int r = 4, c = 6;
        char array_of_game[r][c];
        generator(r, c, array_of_game);
        while (!check(r, c, array_of_game)){

            int where, what;
            game_field(r, c, array_of_game);
            refresh();
            mvprintw(LINES - 5, (COLS/2) - 3, "What: ");
            scanw("%d", &what);

            mvprintw(LINES - 4, (COLS / 2) - 3, "Where: ");
            scanw("%d", &where);
            refresh();

            down_possible(r, c, array_of_game, what, where);
            clear();
            refresh();

        }
        refresh();
        mvprintw(LINES/2, (COLS / 2) - 4, "You WIN!");
        scanw("%d");
        clear();
        refresh();
        endwin();
    }