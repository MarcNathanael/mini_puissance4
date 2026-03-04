#ifndef __MINI_H__
#define __MINI_H__

    #include<stdio.h>
    #include<stdlib.h>
    #define MAX_SIZE 8

    void initialiser_tableau(char tab[MAX_SIZE][MAX_SIZE], int m);
    void afficher_tableau(char tab[MAX_SIZE][MAX_SIZE], int m);
    void jouer_tour(char tab[MAX_SIZE][MAX_SIZE], int m, int t, int *index_ptr);
    int check_horizontal(char tab[MAX_SIZE][MAX_SIZE], int m);
    int check_vertical(char tab[MAX_SIZE][MAX_SIZE], int m);
    int check_diagonal(char tab[MAX_SIZE][MAX_SIZE], int m);
    int check_end(char tab[MAX_SIZE][MAX_SIZE], int m, int index);
    int terminer();

#endif