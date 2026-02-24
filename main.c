#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,i,j,a,b,n,count,index,countf,choix,m;
    char tab[50][50];
    char pion[2]={'O','X'};

    rejouer:
    printf("\t🔆🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🎮🔆\n");
    printf("\t    Bienvenue dans 1er mini-jeux :\n");

    printf("veillez saisir la taille du carré :");
    scanf("%d",&m);
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < m; j++)
        {
            tab[i][j]=' ';
        }
    }
    for (t = 0; t <= (m*m); t++)// repetition du programme , vo feno de mijanona
        {
            if (t==0)
            {
                goto tableau;
            }
            

            if ((t%2)!=0) //rah paire
            {
                n=0; // pion utiliser O
                printf("\tJOUEUR 1 : \n");
                joueur1:
                printf("Entrer la position de votre pion O:\n");
                printf("N° ligne : ");
                scanf("%d",&a);
                printf("N° colonne : ");
                scanf("%d",&b);
                index=1;

                if (tab[a][b]== pion[0] || tab[a][b]==pion[1])
                {
                    printf("\tCette case est deja occupée \n");
                    goto joueur1;
                }
                if ( a>=m || b>=m)
                {
                    printf("\tTaper une valeur de a et b inferieur a %d \n",m);
                    goto joueur1;// on peut utiliser la meme balise plusieurs fois
                }
            }
            else if((t%2)==0)
            {
                n=1; //pion utiliser 1
                printf("\tJOUEUR 2 : \n");
                joueur2:
                printf("Entrer la position de votre pion X:\n");
                printf("N° ligne : ");
                scanf("%d",&a);
                printf("N° colonne : ");
                scanf("%d",&b);
                index=2;
                if (tab[a][b]==pion[0] || tab[a][b]==pion[1])
                {
                    printf("\tCette case est deja occupée ! \n");
                    goto joueur2;
                }
                if (a>=m || b>=m)
                {
                    printf("\tTaper une valeur de a et b inferieur a %d \n",m);
                    goto joueur2;
                }
            }

            tab[a][b]=pion[n];// changement de la valeur d'un case du tableau
          

        // genere le tableau
        tableau:
            for ( i = 0; i < m; i++)
            {
                printf("  %d  ",i);
            }
            printf("\n");
            for( i = 0; i < m ;i++)
            {   
                for ( j = 0; j < m;j++)
                {
                    printf(" ___ ");
                }
                printf("\n");
                
                for( j = 0; j < m ;j++)   
                {
                    printf("¦_%c_¦",tab[i][j]);
                }
                printf("  %d",(i));
                printf("\n");
            }  
            printf("\n");
            
        // verification d'un potentiel vainqueur:___________________________________________________________________________
            // pour les lignes verticales
            for ( i = 0; i < m; i++)
            {
                count=0;
                for ( j = 0; j < (m-1) ; j++)
                {
                    if (tab[i][j]==tab[i][j+1] && tab[i][j]!=' ')
                    {
                        count++;
                    }
                }
                if (count==(m-1))
                {
                    printf("Bravo le JOUEUR %d a gagner 🥳🎉🎉🎉\n",index);
                    goto terminer;
                }
            }

            // pour les lignes horizontales
            for ( i = 0; i < m; i++)
            {
                count=0;
                for ( j = 0; j < (m-1); j++) // 2 tour suffit
                {
                    if (tab[j][i]==tab[j+1][i] && tab[j][i]!=' ')
                    {
                        count++;
                    }
                }
                if (count==(m-1))
                {
                    printf("Bravo le JOUEUR %d a gagner 🥳🎉🎉🎉\n",index);
                    goto terminer;
                }
            }

            // Pour la premier ligne diagonale
            count=0;
            for ( i = 0; i < (m-1) ; i++) // POUR COMPARER 3 CAS IL NE FAUT QUE 2 TOUR 
            {
                if (tab[i][i]==tab[i+1][i+1] && tab[i][i]!=' ')
                {
                    count++;
                }
                if (count==(m-1))
                {
                    printf("Bravo le JOUEUR %d a gagner 🥳🎉🎉🎉\n",index);
                    goto terminer;
                } 
            }

            //pour la deuxieme ligne diagonale
            j=(m-1);
            count=0;
            for ( i = 0; i < (m-1); i++)
            {
                
                if (tab[i][j]==tab[i+1][j-1] && tab[i][j]!=' ')
                {
                    count++;
                }
                
                if (count==(m-1))
                {
                    printf("Bravo le JOUEUR %d a gagner 🥳🎉🎉🎉\n",index);
                    goto terminer;
                }
                j--;   
            }

            //pour un match nul
            countf=0;
            for ( i = 0; i < m ; i++)
            {
                for( j = 0; j< m; j++)
                {
                    if ( count != 2 && count!=0 && tab[i][j]!=' ') // n'oublie pas ce programme se lie ligne par ligne
                    {
                        countf++;
                    }
                }
            }
            if(countf== (m*m))
            {
                printf("Match nul 💩💩\n");// dans tout les cas le programme se termineras ici
            }
            
            printf("\n"); 
        }

    terminer:
    printf("Pour rejouer taper 1\t\tPour quitter le mini-jeux taper 2\n");
    scanf("%d",&choix);
    if (choix==1) // il n'y auras pas de boucle infinie a grace a la reaffection de choix
    {
        goto rejouer;
    }
    else if (choix==2)
    {
        exit (0);
    }
           
}
