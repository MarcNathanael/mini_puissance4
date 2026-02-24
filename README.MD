# Mini Puissance 4 (CLI) 🎮

Un mini-jeu de plateau en mode console développé en C. Contrairement au Puissance 4 classique, ce projet permet de définir une taille de grille personnalisée (NxN) et nécessite d'aligner des pions sur toute la longueur de la grille pour gagner.


  0    1    2  
 ___  ___  ___ 
¦_O_¦¦_X_¦¦___¦  0
 ___  ___  ___ 
¦____¦¦_O_¦¦___¦  1
 ___  ___  ___ 
¦_X_¦¦___¦¦_O_¦  2

## Concept et aspect 
Ce projet a servi de base pour l'apprentissage de :

*Matrices 2D : Manipulation d'un plateau de jeu via tab[50][50].
*Logique de Victoire : Algorithmes de vérification horizontale, verticale et diagonale.
*Gestion des Sauts : Utilisation de l'instruction goto pour la gestion des tours et les erreurs de saisie.
*Boucle de Jeu : Système de "Rejouer" et gestion des tours alternés entre deux joueurs.
