/*
 ***********************************************************************************************
 *                                                                                             *
 *                                       Classe : Dijkstra                                     *
 *                                         Projet M326                                         *
 *                                                                                             *
 * Author: MAILLO Valentin - 2020                                                              *
 *                                                                                             *
 *                                                                                             *
 * Fonctions :                                                                                 *
 *                                                                                             *
 *      - DijkstraSimple(const graph & g) : Premier algorithme de Dijkstra implémenté.         *
 *                 Cette fonction renvoie une paire de vecteur. Le premier élement de la paire *
 *                 noté "valeurs" est un vecteur de double qui fait la même taille que         *
 *                 le vecteur sommet. Ce vecteur valeurs stocke pour chaque point du graphe    *
 *                 passé en paramètre la distance la plus courte avec la source en faisant     *
 *                 correspondre l'indice du point avec l'indice du vecteur valeurs             *
 *                 c'est-à-dire que le i-ème élément du vecteur valeurs correspondant à la     *
 *                 distance la plus courte avec le i-ème point du vecteur sommets du           *
 *                 graphe g passé en paramètre.                                                *
 *                 Nous avons ensuite amélioré cet algorithme en renvoyant aussi un vecteur    *
 *                 d'entier appelé "meilleurVoisins" qui stocke pour chaque point l'indice     *
 *                 de son meilleur voisin c'est-à-dire l'indice du point voisin ayant la       *
 *                 distance la plus courte. Comme pour le vecteur valeurs on fait correspondre *
 *                 l'indice du point étudié avec l'indice de ce point dans le vecteur sommets  *
 *                 du graphe g passé en paramètre.                                             *
 *                 Nous avons ensuite amélioré une seconde fois cet algorithme en              *
 *                 rajoutant une condition dans la boucle while qui permet à l'algoritme de    *
 *                 s'arrêter lorsqu'il a calculé le chemin le plus court entre la source       *
 *                 et le puits.                                                                *
 *                 Cette fonction est lente à l'exécution car nous re-parcourons à chaque fois *
 *                 les vecteurs arêtes et sommets de la classe graph afin de trouver l'indice  *
 *                 correspondant. Pour des graphes de taille élevé, ces vecteurs sont très     *
 *                 grands.                                                                     *
 *                                                                                             *
 *      - DijkstraFM(const graph & g) : Cet algorithme est l'algorithme de Dijkstra que        *
 *                 l'on utilisera dans le reste du programme.                                  *
 *                 Cette fonction renvoie la même paire de vecteur que la fonction             *
 *                 DijkstraSimple mais ne reparcourt pas les vecteurs sommets et aretes du     *
 *                 graphe g passé en paramètre ce qui nous permet d'avoir des calculs beaucoup  *
 *                 plus rapides que dans la fonction DijkstraSimple.                           *
 *                 Ici, on utilise le vecteur voisin du graphe g qui contient déjà les          *
 *                 informations que l'on a besoin : l'indice de chaque point du graphe et       *
 *                 les indices de tout ses voisins.                                            *
 *                 Nous avons ensuite amélioré de la même façon cet algorithme afin qu'il      *
 *                 renvoi le meilleur voisins de chaque point et qu'il s'arrête lorsqu'il      *
 *                 aura calculé le chemin le plus rapide entre la source et le puits.          *
 *                 De plus nous avons amélioré le calcul de la distance afin que cet           *
 *                 algorithme utilise la méthode de Fast-Marching.                             *
 *                                                                                             *
 *      - PlusCourtChemin(std::pair<std::vector<double>,std::vector<int>> values) : Cette      *
 *                 fonction prend en argument une paire de vecteur du même type que ce qui est *
 *                 renvoyé par l'algorithme de Dijkstra et retrouve le chemin le plus court    *
 *                 entre la source et le puits. Pour ce faire on utilise la méthode de         *
 *                 BackTracking.                                                               *
 *                 Comme dans l'algorithme de Dijkstra on s'intéresse uniquement aux indices   *
 *                 des points.                                                                 *
 *                 Cette fonction retourne donc un vecteur d'entier comportant les indices     *
 *                 des points à parcourir afin de retourver le chemin le plus court entre      *
 *                 la source et le puits.                                                      *
 *                                                                                             *
 *      - affichagepluscourtchemin(graph g, std::vector<int> pcm ) : Cette fonction permet de  *
 *                 créer une image représentant le graphe et trace le chemin le plus court     *
 *                 entre la source et le puits.                                                *
 *                 Ici on réutilise le code de la fonction affichage de la classe graph        *
 *                 en ajoutant une partie pour tracer les arêtes par lesquelles il faut passer *
 *                 pour rejoindre la source et le plus rapidement possible.                    *
 *                 Cette fonction prend en paramètre un graphe g qu'elle représente de la même *
 *                 façon que dans la fonction affichage de la classe graph et un vecteur       *
 *                 d'entier (type de retour de la fonction PlusCourtChemin) qui est parcouru   *
 *                 afin de tracer en rouge le chemin le plus court entre la source et le puits.*
 *                                                                                             *
 *      - affichagepcmproportionnel(graph g, std::vector<int> pcm ) : Cette fonction permet de *
 *                 créer une image représentant le graphe et trace le chemin le plus court     *
 *                 entre la source et le puits.                                                *
 *                 Ici on réutilise le code de la fonction affichageproportionnel de la        *
 *                 classe graph en ajoutant une partie pour tracer les arêtes par lesquelles   *
 *                 il faut passer pour rejoindre la source et le plus rapidement possible.     *
 *                 Cette fonction prend en paramètre un graphe g qu'elle représente de la même *
 *                 façon que dans la fonction affichageproportionnel de la classe graph et un  *
 *                 vecteur d'entier (type de retour de la fonction PlusCourtChemin) qui est    *
 *                 parcouru afin de tracer en rouge le chemin le plus court entre la source et *
 *                 le puits.                                                                   *
 *                 Les mêmes conseils seront donnés concernant l'utilisation de cette fonction.*
 *                                                                                             *
 *      - TestDijkstra() : Cette fonction permet de tester notre algorithme pour des graphes   *
 *                 choisis.                                                                    *
 *                 En exécutant cette fonction on affiche le nombre de sommet et d'arête du    *
 *                 graphe concidéré, on crée une image représentant ce graphe et on execute    *
 *                 l'algorithme de Dijkstra. Si il existe un chemin entre la source et le      *
 *                 puits on affiche la distance la plus courte les rejoignant et on crée une   *
 *                 image de ce graphe avec le chemin le plus court.                            *
 *                                                                                             *
 * Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
 ***********************************************************************************************
*/

#ifndef Dijkstra_h
#define Dijkstra_h
#include "PriorityQueue.h"
#include "graph.h"

// ------ Dijkstra ------
/* Pseudo code de l'algorithme de Djistra
 
 * Entrées : un graphe à n sommets
 * Initialiser: un tableau valeurs de taille n à +infinie, sauf valeurs[source]=0; et un tableau final de taille n à false.
 * Tant qu'il existe i tel que final[i] == false:
      Choisir i tel que final[i] == false et que valeurs[i] est minimal.
      final[i] == true.
      Pour tout voisin j de i tel que final[j] == false (en notant dist la longueur de l’arête [i,j]):
             valeurs[j] = min(valeurs[j],valeurs[i] + dist).
 * Retourner valeurs.
 
 */

using NeighborType = std::pair<int,double>;
using GraphType = std::vector<std::vector<NeighborType> >;

std::pair<std::vector<double>,std::vector<int>> DijkstraSimple(const graph & g){
    // Dans cet algorithme on se réfère aux indices des points dans la tableau g.sommets
    // donc lorsque on parle du point i on parle du i-ème point dans le tableau g.sommet
    
    //Variables
    const size_t n = g.sommets.size(); // nombre de sommet du graph
    std::vector<double>  valeurs;
    std::vector<bool> final;
    PriorityQueue<std::pair<double ,int >> queue;
    std::vector<int> meilleurVoisins(n);
    
    
    // Initialisation
    valeurs.resize(n,1/0.); // Initialise le tableau valeurs de taille n à +infinie
    valeurs[0]=0; // Sauf pour la source où il vaut 0
    queue.push({0,0});
    meilleurVoisins[0]=0; // Le meilleur voisin de la source est lui même
    
    
    
    final.resize(n, false); // Initialise le tableau final de taille n à false
    
    for (int i = 0; i < n; i++) queue.push({ -valeurs[i], i });
    
    while (!queue.empty() and valeurs[n-1] > 10e8 ) { // Tant qu'il existe i tel que final[i] == false  et que nous sommes pas arrivé jusqu'au puits
        const int i = queue.top().second; // Indice du point traité à cette itration
        queue.pop();
        if (final[i]) continue; // Traitement déja fait
        
        final[i] = true;
        std::vector<Point> voisini;
        Point repere = g.sommets[i];
        
        for (auto j : g.aretes) {
            if(j.points[0] == repere) {
                voisini.push_back(j.points[1]); 
            }
        }
        
        for (auto voisin : voisini) { // Pour tout voisin j de i tel que final[j] == false
            int index = -1;
            for (int k = 0; k<n;k++) {
                if((g.sommets[k].get_x() == voisin.get_x()) and (g.sommets[k].get_y() ==voisin.get_y())){
                    index = k;
                }
            }
            int j = index;
            double dist = distance(g.sommets[i], g.sommets[j]);
             
            valeurs[j] = std::min(valeurs[j], valeurs[i] + dist);
            queue.push({ -valeurs[j], j });
            
            if(valeurs[j]==valeurs[i]+dist)
                meilleurVoisins[j]=i; //stockage du meilleur voisin de i
        }
    }
    
    return {valeurs,meilleurVoisins};
}

std::pair<std::vector<double>,std::vector<int>> DijkstraFM(const graph & g){
    
    //Variables
    const size_t n = g.sommets.size(); // nombre de sommet du graph
    std::vector<double>  valeurs;
    std::vector<bool> final;
    PriorityQueue<std::pair<double ,int >> queue;
    std::vector<int> meilleurVoisins(n);
    
    
    // Initialisation
    valeurs.resize(n,1/0.); // Initialise le tableau valeurs de taille n à +infinie
    valeurs[0]=0; // Sauf pour la source où il vaut 0
    queue.push({0,0});
    meilleurVoisins[0]=0; // Le meilleur voisin de la source est lui même
    
    
    
    final.resize(n, false); // Initialise le tableau final de taille n à false
    
    for (int i = 0; i < n; i++) queue.push({ -valeurs[i], i });
    
    while (!queue.empty() and valeurs[n-1] > 10e8 ) { // Tant qu'il existe i tel que final[i] == false  et que nous sommes pas arrivé jusqu'au puits
        const int i = queue.top().second; // Indice du point traité à cette itration
        queue.pop();
        if (final[i]) continue; // Traitement déja fait
        
        final[i] = true;
        
        for (auto voisin : g.voisin[i].second) { // Pour tout voisin j de i tel que final[j] == false
            unsigned long j = voisin;
            double dist = -1;
            Point repere1 = g.sommets[i];
            Point repere2 = g.sommets[j];
            if (i==0 or i == n-1 or j==0 or j == n-1) {
                dist = 1;
            }
            else {
                dist = distance(repere1, repere2);
            }
             
            if (final[j]) continue; // Traitement déja fait
            
            double Delta = 2*dist - (valeurs[j]-2*valeurs[i])*(valeurs[j]-2*valeurs[i]);
            if ( Delta>=0) {
                valeurs[j] = (valeurs[j]+ std::sqrt(Delta))/2;
            }
            else {
                valeurs[j] = std::min(valeurs[j], valeurs[i] + dist);
            }
            
            queue.push({ -valeurs[j], j });
            
            if(valeurs[j]==valeurs[i]+dist)
                meilleurVoisins[j]=i; //stockage du meilleur voisin de i
        }
    }
    
    return {valeurs,meilleurVoisins};
}

std::pair<std::vector<double>,std::vector<int>> DijkstraOptimal(const graph & g){
    
    //Variables
    const size_t n = g.sommets.size(); // nombre de sommet du graph
    std::vector<double>  valeurs;
    std::vector<bool> final;
    PriorityQueue<std::pair<double ,int >> queue;
    std::vector<int> meilleurVoisins(n);
    
    
    // Initialisation
    valeurs.resize(n,1/0.); // Initialise le tableau valeurs de taille n à +infinie
    valeurs[0]=0; // Sauf pour la source où il vaut 0
    queue.push({0,0});
    meilleurVoisins[0]=0; // Le meilleur voisin de la source est lui même
    
    
    
    final.resize(n, false); // Initialise le tableau final de taille n à false
    
    for (int i = 0; i < n; i++) queue.push({ -valeurs[i], i });
    
    while (!queue.empty() and valeurs[n-1] > 10e8 ) { // Tant qu'il existe i tel que final[i] == false  et que nous sommes pas arrivé jusqu'au puits
        const int i = queue.top().second; // Indice du point traité à cette itration
        queue.pop();
        if (final[i]) continue; // Traitement déja fait
        
        final[i] = true;
        
        for (auto voisin : g.voisin[i].second) { // Pour tout voisin j de i tel que final[j] == false
            unsigned long j = voisin;
            double dist = -1;
            Point repere1 = g.sommets[i];
            Point repere2 = g.sommets[j];
            if (i==0 or i == n-1 or j==0 or j == n-1) {
                dist = 1;
            }
            else {
                dist = distance(repere1, repere2);
            }
             
            if (final[j]) continue; // Traitement déja fait
            
            double Delta = 2*dist*dist + valeurs[j] + 2*valeurs[i] - 2*valeurs[j]*valeurs[j] - 4*valeurs[i]*valeurs[i];
            if ( Delta>=0) {
                valeurs[j] = (valeurs[j]+ std::sqrt(Delta))/2;
            }
            else {
                valeurs[j] = std::min(valeurs[j], valeurs[i] + dist);
            }
            
            queue.push({ -valeurs[j], j });
            
            if(valeurs[j]==valeurs[i]+dist)
                meilleurVoisins[j]=i; //stockage du meilleur voisin de i
        }
    }
    
    return {valeurs,meilleurVoisins};
}

std::vector<unsigned long> PlusCourtChemin(std::pair<std::vector<double>,std::vector<int>> values) {
    
    // Initialisation
    const size_t n = values.first.size();
    int distance = values.first[n-1];     // taille de notre plus court chemin
    std::vector<unsigned long> pluscourtchemin;

    // les premieres valeurs seront toujours le puits et son meilleur voisin
    pluscourtchemin.push_back(n-1);
    pluscourtchemin.push_back(values.second[n-1]);
    
    
    for (int k =0;k<distance-1;k++)
        for (int i = 0; i < n; i++ ){
            if (pluscourtchemin.back() == i) {
                if (pluscourtchemin.back() == 0) break;
                    pluscourtchemin.push_back(values.second[i]);
                }
    }
    return pluscourtchemin;
}

void affichagepluscourtchemin(graph g, std::vector<unsigned long> pcm ) {
    
    int n = g.taille;
    int distance = 900/n;
    bitmap_image image(1000,1000); // création d'une image de 1000x1000 pixels
    
    // initialisation du fond de  l'image en bleu
    image.set_all_channels(0, 0, 200);
    
    image_drawer draw(image);
    
    draw.pen_width(2);  // taille des traits tracé
    draw.pen_color(253, 108, 158);  // couleur des traits tracé
    
    draw.circle((image.width() / 80), (image.height() / 2), 10); // affichage du point source de couleur rose
    for (int i = 0;i<10;i++) {
        draw.circle((image.width() / 80), (image.height() / 2), i);
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if ((i == 300) and (iprime==1)) { // affichage des aretes de source
            draw.line_segment((image.width() / 80), (image.height() / 2), (image.width() -925), (image.height() -925)+distance*(jprime-1));
        }
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 255, 255);
    
    for (Point p : g.sommets){ // affichage des point du corps du graph
        int i = p.get_x();
        int j = p.get_y();
        if (p.here) {
            draw.circle(((image.width() -925)+(i-1)*distance), ((image.height() -925)+(j-1)*distance), 10);
        }
    }
    
    draw.pen_width(2);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int j = k.points[0].get_y();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if (( i<=iprime) and (j<=jprime)) {
            if ((i <= n) and (i==iprime)) { // affichage aretes verticales
                draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+(i-1)*distance, (image.height() -925)+distance+(j-1)*distance);
            }
            if ((j <= n)and (j==jprime) ) {  // affichage aretes horizontales
                draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+distance+(i-1)*distance, (image.height() -925)+(j-1)*distance);
            }
            if ( (i==iprime-1) and (j==jprime-1) ) {  // affichage aretes diagonales si existante
                draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+distance+(i-1)*distance, (image.height() -925)+distance+(j-1)*distance);
            }
        }
    }
    
    
    draw.pen_width(2);
    draw.pen_color(253, 108, 158);
    
    draw.circle((image.width()*79 / 80), (image.height() / 2), 10); // affichage du point puits de couleur rose
    for (int i = 0;i<10;i++) {
        draw.circle((image.width()*79 / 80), (image.height() / 2), i);
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if ((i == -100) and (iprime==g.taille)) { // affichage des aretes du puits
            draw.line_segment((image.width()*79 / 80), (image.height() / 2), (image.width()-925)+(n-1)*distance, (image.height() -925)+distance*(jprime-1));
        }
    }
    
    
    
    draw.pen_width(3);
    draw.pen_color(255, 0, 0);
    
    draw.line_segment((image.width()*79 / 80), (image.height() / 2), (image.width()-925)+(n-1)*distance, (image.height() -925) + distance*(g.sommets[pcm[1]].get_y()-1));  // affichage de l'arêtes partant de la source vers le premier point du chemin le plus court vers le puits
    
    draw.line_segment((image.width() / 80), (image.height() / 2), (image.width() -925), (image.height() -925)+distance*(g.sommets[pcm[pcm.size()-2]].get_y()-1));// affichage de l'arêtes partant du dernier point du corps vers le puits
    
    for(unsigned long k = pcm.size()-2; k>= 1;k--) {
        int i = g.sommets[pcm[k]].get_x();
        int j = g.sommets[pcm[k]].get_y();
        int iprime = g.sommets[pcm[k-1]].get_x();
        int jprime = g.sommets[pcm[k-1]].get_y();
        if ((i <= n) and (i==iprime) and (j < jprime)) { // affichage aretes verticales vers le bas
            draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+(i-1)*distance, (image.height() -925)+distance+(j-1)*distance);
        }
        if ((i <= n) and (i==iprime) and (j>jprime)) { // affichage aretes verticales vers le haut
            draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+(i-1)*distance, (image.height() -925)-distance+(j-1)*distance);
        }
        if ((j <= n)and (j==jprime) and (i<iprime) ) {  // affichage aretes horizontales vers la droite
            draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+distance+(i-1)*distance, (image.height() -925)+(j-1)*distance);
        }
        if ((j <= n)and (j==jprime) and (i>iprime) ) {  // affichage aretes horizontales vers la gauche
            draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)-distance+(i-1)*distance, (image.height() -925)+(j-1)*distance);
        }
        if ( (i==iprime-1) and (j==jprime-1) ) {  // affichage aretes diagonales vers la droite si existante
            draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+distance+(i-1)*distance, (image.height() -925)+distance+(j-1)*distance);
        }
        if ( (i==iprime+1) and (j==jprime+1) ) {  // affichage aretes diagonales vers la gauche si existante
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)-distance+(i-1)*distance, (image.height() *0.075)-distance+(j-1)*distance);
            
        }
    }
    
    image.save_image("chemin.bmp");  // nom de l'image crée
}

void affichagepcmproportionnel(graph g, std::vector<unsigned long> pcm ) {
    
    int n=g.taille;
    int distance=36;
    bitmap_image image(40*n,40*n); // création d'une image
    
    // initialisation du fond de  l'image en bleu
    image.set_all_channels(0, 0, 200);
    
    image_drawer draw(image);
    
    draw.pen_width(2);  // taille des traits tracé
    draw.pen_color(253, 108, 158);  // couleur des traits tracé
    
    draw.circle((image.width() / 80), (image.height() / 2), 10); // affichage du point source de couleur rose
    for (int i = 0;i<10;i++) {
        draw.circle((image.width() / 80), (image.height() / 2), i);
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if ((i == 300) and (iprime==1)) { // affichage des aretes de source
            draw.line_segment((image.width() / 80), (image.height() / 2), (image.width() *0.075), (image.height() *0.075)+distance*(jprime-1));
        }
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 255, 255);
    
    for (Point p : g.sommets){ // affichage des point du corps du graph
        int i = p.get_x();
        int j = p.get_y();
        if (p.here) {
            draw.circle(((image.width() *0.075)+(i-1)*distance), ((image.height() *0.075)+(j-1)*distance), 10);
        }
    }
    
    draw.pen_width(2);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int j = k.points[0].get_y();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if (( i<=iprime) and (j<=jprime)) {
            if ((i <= n) and (i==iprime)) { // affichage aretes verticales
                draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+distance+(j-1)*distance);
            }
            if ((j <= n)and (j==jprime) ) {  // affichage aretes horizontales
                draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+distance+(i-1)*distance, (image.height() *0.075)+(j-1)*distance);
            }
            if ( (i==iprime-1) and (j==jprime-1) ) {  // affichage aretes diagonales si existante
                draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+distance+(i-1)*distance, (image.height() *0.075)+distance+(j-1)*distance);
            }
        }
    }
    
    
    draw.pen_width(2);
    draw.pen_color(253, 108, 158);
    
    draw.circle((image.width()*79 / 80), (image.height() / 2), 10); // affichage du point puits de couleur rose
    for (int i = 0;i<10;i++) {
        draw.circle((image.width()*79 / 80), (image.height() / 2), i);
    }
    
    draw.pen_width(1);
    draw.pen_color(255, 200, 0);
    
    for (Arete k : g.aretes) {
        int i = k.points[0].get_x();
        int iprime = k.points[1].get_x();
        int jprime = k.points[1].get_y();
        if ((i == -100) and (iprime==g.taille)) { // affichage des aretes du puits
            draw.line_segment((image.width()*79 / 80), (image.height() / 2), (image.width()*0.075)+(n-1)*distance, (image.height() *0.075)+distance*(jprime-1));
        }
    }
    
    
    
    draw.pen_width(3);
    draw.pen_color(255, 0, 0);
    
    draw.line_segment((image.width()*79 / 80), (image.height() / 2), (image.width()*0.075)+(n-1)*distance, (image.height() *0.075) + distance*(g.sommets[pcm[1]].get_y()-1));
    
    draw.line_segment((image.width() / 80), (image.height() / 2), (image.width() *0.075), (image.height() *0.075)+distance*(g.sommets[pcm[pcm.size()-2]].get_y()-1));
    
    for(unsigned long k = pcm.size()-2; k>= 1;k--) {
        int i = g.sommets[pcm[k]].get_x();
        int j = g.sommets[pcm[k]].get_y();
        int iprime = g.sommets[pcm[k-1]].get_x();
        int jprime = g.sommets[pcm[k-1]].get_y();
        if ((i <= n) and (i==iprime) and (j < jprime)) { // affichage aretes verticales vers le bas
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+distance+(j-1)*distance);
        }
        if ((i <= n) and (i==iprime) and (j>jprime)) { // affichage aretes verticales vers le haut
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+(i-1)*distance, (image.height() *0.075)-distance+(j-1)*distance);
        }
        if ((j <= n)and (j==jprime) and (i<iprime) ) {  // affichage aretes horizontales vers la droite
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+distance+(i-1)*distance, (image.height() *0.075)+(j-1)*distance);
        }
        if ((j <= n)and (j==jprime) and (i>iprime) ) {  // affichage aretes horizontales vers la gauche
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)-distance+(i-1)*distance, (image.height() *0.075)+(j-1)*distance);
        }
        if ( (i==iprime-1) and (j==jprime-1) ) {  // affichage aretes diagonales vers la droite si existante
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+distance+(i-1)*distance, (image.height() *0.075)+distance+(j-1)*distance);
        }
        if ( (i==iprime+1) and (j==jprime+1) ) {  // affichage aretes diagonales vers la gauche si existante
            draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)-distance+(i-1)*distance, (image.height() *0.075)-distance+(j-1)*distance);
        }
    }
    
    image.save_image("chemin.bmp");  // nom de l'image crée
}

void TestDijkstra(int n){
    
    graph g = graph(n);
    std::cout <<g<< std::endl;
    std::pair<std::vector<double>,std::vector<int>> values2 = DijkstraFM(g);
    std::pair<std::vector<double>,std::vector<int>> values3 = DijkstraOptimal(g);
    
    int reponse;
    std::cout << "Voulez vous un affichage : " << std::endl;
    std::cout << "1/ Peu lisible pour les grandes tailles de graphe mais rapide (conseillé pour les tailles inférieur à 50) " << std::endl;
    std::cout << "2/ Lisible mais plus longs pour les grandes tailles de graphe (ne pas dépasser la taille 500)" << std::endl;
    std::cout << "3/ Pas d'affichage " << std::endl;
    std::cout << "Entrez le numéro choisi (1, 2 ou 3) : ";
    std::cin >> reponse;

    if (reponse == 1) {
        affichage(g);
        std::cout <<"" << std::endl;
        if ( values2.first[g.sommets.size()-1] <10e8) {
            //std::cout <<"La distance minimal entre la source et le puits est de (simple) " << values1.first[g.sommets.size()-1] << std::endl;
            std::cout <<"La distance minimal entre la source et le puits est de (Fast Marching)  " << values2.first[g.sommets.size()-1] << std::endl;
            std::cout <<"" << std::endl;
            std::vector<unsigned long> pcm = PlusCourtChemin(values2);
            affichagepluscourtchemin(g, pcm);
            std::cout <<"Une image traçant le chemin le plus court entre la source et le puits à été créé" << std::endl;
        }

        else {
            std::cout << "La source et le puits ne sont pas réliés"<< std::endl;
        }
    }

    else if ( reponse ==2) {
        affichageproportionnel(g);
        std::cout <<"" << std::endl;
        if ( values2.first[g.sommets.size()-1] <10e8) {
            //std::cout <<"La distance minimal entre la source et le puits est de (simple) " << values1.first[g.sommets.size()-1] << std::endl;
            std::cout <<"La distance minimal entre la source et le puits est de (Fast Marching)  " << values2.first[g.sommets.size()-1] << std::endl;
            std::cout <<"" << std::endl;
            std::vector<unsigned long> pcm = PlusCourtChemin(values2);
            affichagepcmproportionnel (g, pcm);
            std::cout <<"Une image traçant le chemin le plus court entre la source et le puits à été créé" << std::endl;
        }

        else {
            std::cout << "La source et le puits ne sont pas réliés"<< std::endl;
        }
    }

    else {
        std::cout <<"" << std::endl;
        if ( values2.first[g.sommets.size()-1] <10e8) {
            //std::cout <<"La distance minimal entre la source et le puits est de (simple) " << values1.first[g.sommets.size()-1] << std::endl;
            std::cout <<"La distance minimal entre la source et le puits est de ( par la méthode de Fast Marching)  " << values2.first[g.sommets.size()-1] << std::endl;
            std::cout <<"" << std::endl;
            std::vector<unsigned long> pcm = PlusCourtChemin(values2);
            std::cout <<"" << std::endl;
        }

        else {
            std::cout << "La source et le puits ne sont pas réliés"<< std::endl;
        }
    }
    
//        affichage(g);
//        std::cout <<"" << std::endl;
//        if ( values2.first[g.sommets.size()-1] <10e8) {
//            //std::cout <<"La distance minimal entre la source et le puits est de (simple) " << values1.first[g.sommets.size()-1] << std::endl;
//            std::cout <<"La distance minimal entre la source et le puits est de (Fast Marching)  " << values2.first[g.sommets.size()-1] << std::endl;
//            std::cout <<"La distance minimal entre la source et le puits est de (Optimal)  " << values3.first[g.sommets.size()-1] << std::endl;
//            std::cout <<"" << std::endl;
//            std::vector<unsigned long> pcm = PlusCourtChemin(values2);
//            affichagepluscourtchemin(g, pcm);
//            std::cout <<"" << std::endl;
//        }
//
//        else {
//            std::cout << "La source et le puits ne sont pas réliés"<< std::endl;
//        }
}

#endif /* Dijkstra_h */
