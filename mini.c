#include "mini.h"

int main()
{
    int t,i,j,a,b,n,count,index,countf,choix,m;
    char tab[MAX_SIZE][MAX_SIZE];
    char esp[1]=" ";
    char pion[2]={'O','X'};

    rejouer:
    printf("\t🔆🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🔆\n");
    printf("\t    Bienvenue dans 1er mini-jeux :\n");
    do
    {
        printf("veillez saisir la taille du carré :");
        scanf("%d",&m);
    } while ( m <=  1 || m > MAX_SIZE );
    
    initialiser_tableau(tab, m);

    for (t = 0; t <= (m*m); t++)// repetition du programme , des que les case sont remplis ca s'arrete
    {
            if (t==0)
            {
                afficher_tableau(tab, m);
                continue;
            }
            
            jouer_tour(tab, m, t, &index);
            //On affiche le tableau mis à jour
            afficher_tableau(tab, m);

            // On appelle la fonction terminer. Si elle retourne 1, on rejoue
            if (check_end(tab, m, index) == 1) 
            {
                // Si la partie est finie (victoire ou nul), ALORS on demande s'il veut rejouer
                if (terminer() == 1) 
                {
                    goto rejouer;
                } 
                else 
                {
                    printf(" A la prochaine !!\n");
                    return 0; // Quitte le programme proprement
                }
            }
    }
    return 0;
}