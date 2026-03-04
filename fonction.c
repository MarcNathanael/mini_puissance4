#include "mini.h"

int terminer() 
{
    int choix;
    printf("Pour rejouer taper 1\t\tPour quitter le mini-jeux taper 2\n");
    scanf("%d", &choix);
    return choix; // On retourne 1 ou 2 au main
}

void initialiser_tableau(char tab[MAX_SIZE][MAX_SIZE], int m) {
    int i, j;
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < m; j++) 
        {
            tab[i][j] = ' ';
        }
    }
}

void afficher_tableau(char tab[MAX_SIZE][MAX_SIZE], int m) {
    int i, j;
    for (i = 0; i < m; i++) {
        printf("  %d  ", i);
    }
    printf("\n");
    for(i = 0; i < m; i++) {   
        for (j = 0; j < m; j++) {
            printf(" ___ ");
        }
        printf("\n");
        
        for(j = 0; j < m; j++) {
            printf("¦_%c_¦", tab[i][j]);
        }
        printf("  %d", (i));
        printf("\n");
    }  
    printf("\n");
}

int check_vertical(char tab[MAX_SIZE][MAX_SIZE], int m) {
    int i, j, count;
    for (i = 0; i < m; i++) {
        count = 0;
        for (j = 0; j < (m - 1); j++) {
            if (tab[i][j] == tab[i][j+1] && tab[i][j] != ' ') {
                count++;
            }
        }
        if (count == (m - 1)) return 1; // Gagné
    }
    return 0;
}

int check_horizontal(char tab[MAX_SIZE][MAX_SIZE], int m) 
{
    int i, j, count;
    for (i = 0; i < m; i++) 
    {
        count = 0;
        for (j = 0; j < (m - 1); j++) {
            if (tab[j][i] == tab[j+1][i] && tab[j][i] != ' ') {
                count++;
            }
        }
        if (count == (m - 1)) return 1; // Gagné
    }
    return 0;
}

int check_diagonal(char tab[MAX_SIZE][MAX_SIZE], int m)
{
    int i, j, count;
    
    // Première diagonale (\)
    count = 0;
    for (i = 0; i < (m - 1); i++) {
        if (tab[i][i] == tab[i+1][i+1] && tab[i][i] != ' ') {
            count++;
        }
    }
    if (count == (m - 1)) return 1;

    // Deuxième diagonale (/)
    j = (m - 1);
    count = 0;
    for (i = 0; i < (m - 1); i++) {
        if (tab[i][j] == tab[i+1][j-1] && tab[i][j] != ' ') {
            count++;
        }
        j--;   
    }
    if (count == (m - 1)) return 1;

    return 0;
}

int check_end(char tab[MAX_SIZE][MAX_SIZE], int m, int index) 
{
    // 1. On vérifie si quelqu'un a gagné
    if (check_horizontal(tab, m) || check_vertical(tab, m) || check_diagonal(tab, m)) 
    {
        printf("Bravo le JOUEUR %d a gagner 🥳🎉🎉🎉\n", index);
        return 1; // Le jeu s'arrête
    }

    // 2. On vérifie le match nul (si le tableau est plein)
    int i, j, countf = 0;
    for (i = 0; i < m; i++) 
    {
        for(j = 0; j < m; j++) 
        {
            if (tab[i][j] != ' ') 
            {
                countf++;
            }
        }
    }
    if(countf == (m * m)) {
        printf("Match nul 💩💩\n");
        return 1; // Le jeu s'arrête
    }

    return 0; // Personne n'a gagné et le tableau n'est pas plein : on continue
}

void jouer_tour(char tab[MAX_SIZE][MAX_SIZE], int m, int t, int *index_ptr) {
    int a, b, n;
    char pion[2] = {'O', 'X'};

    if ((t % 2) != 0) {
        n = 0; // Joueur 1 (O)
        *index_ptr = 1;
        printf("\tJOUEUR 1 : \n");
        
        joueur1:
        printf("Entrer la position de votre pion O :\n");

        printf("N° ligne : ");
        if (scanf("%d", &a) != 1) {
            printf("\t⚠️ Erreur : Tapez un chiffre, pas une lettre !\n");
            while(getchar() != '\n'); 
            goto joueur1;
        }


        printf("N° colonne : ");
        if (scanf("%d", &b) != 1) {
            printf("\t⚠️ Erreur : Tapez un chiffre, pas une lettre !\n");
            while(getchar() != '\n');
            goto joueur1;
        }

        if (a < 0 || a >= m || b < 0 || b >= m) {
            printf("\t❌ Valeur hors limites ! (Max %d)\n", m - 1);
            goto joueur1;
        }
        if (tab[a][b] != ' ') {
            printf("\t🚫 Cette case est déjà occupée !\n");
            goto joueur1;
        }
    } 
    else {
        n = 1; // Joueur 2 (X)
        *index_ptr = 2;
        printf("\tJOUEUR 2 : \n");
        
        joueur2:
        printf("Entrer la position de votre pion X :\n");
        
        printf("N° ligne : ");
        if (scanf("%d", &a) != 1) {
            printf("\t⚠️ Erreur : Tapez un chiffre !\n");
            while(getchar() != '\n');
            goto joueur2;
        }

        printf("N° colonne : ");
        if (scanf("%d", &b) != 1) {
            printf("\t⚠️ Erreur : Tapez un chiffre !\n");
            while(getchar() != '\n');
            goto joueur2;
        }

        if (a < 0 || a >= m || b < 0 || b >= m) {
            printf("\t❌ Valeur hors limites ! (Max %d)\n", m - 1);
            goto joueur2;
        }

        if (tab[a][b] != ' ') {
            printf("\t🚫 Cette case est déjà occupée !\n");
            goto joueur2;
        }
    }

    tab[a][b] = pion[n]; 
}