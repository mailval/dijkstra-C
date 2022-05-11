/*
 ***********************************************************************************************
 *                                                                                             *
 *                                       Classe : Graph                                        *
 *                                        Projet M326                                          *
 *                                                                                             *
 * Author: MAILLO Valentin & COLARD-CLAUDY Maéva - 2020                                        *
 *                                                                                             *
 *                                                                                             *
 * Arguments :                                                                                 *
 *                                                                                             *
 *      - taille : Entier qui stocke la taille de notre graphe de la forme (taille * taille)   *
 *      - parete : Double qui nous permet de connaitre la proportion d'arêtes crée             *
 *      - psommet : Double qui nous permet de connaitre la proportion de sommets crée          *
 *      - sommets : Vecteur de Point qui stocke l'ensemble des points du graphe (le premier    *
 *                 point est la source et le dernier est le puits)                             *
 *      - aretes : Vecteur d'Arete qui stocke l'ensemble des arêtes créés dans les deux sens   *
 *                 c'est-à-dire que lorsque l'on crée une arête entre le point i et le point j *
 *                 deux arêtes sont créés l'arête (i,j) et l'arête (j,i) cela est necessaire   *
 *                 pour l'algorithme de Dijkstra et pour l'affichage.                          *
 *      - voisin : Vecteur de pair, le premier élément de la paire est un entier qui           *
 *                 correspond à chaque indice de nos points. Le second élément est un vecteur  *
 *                 d'entier correspondant à l'ensemble des indices des points voisins du point *
 *                 du premier élément de notre paire.                                          *
 *      - triangle : Booléen qui permettra de savoir si on doit créer une graphe carré ou un   *
 *                 graphe triangulaire.                                                        *
 *                                                                                             *
 * Constructeurs :                                                                             *
 *                                                                                             *
 *      - graph(int n) : Constructeur "classique" qui crée un graphe de taille n,              *
 *                  demande à l'utilisateur la forme du graphe souhaité, la probabilité        *
 *                  d'arêtes souhaité ainsi que la proportion de sommets souhaité.             *
 *      - graph(int n, double p, double ps, bool forme) : Constructeur plus spécifique de      *
 *                  graphe utilisé pour calculer la probabilité critique dans la fonction      *
 *                  probacritiqueSommet() (classe main) qui crée un graphe de taille n, de     *
 *                  forme carré si forme est false, ou triangulaire si forme est true,         *
 *                  qui associe la probabilité d'arêtes souhaité à p et qui associe la         *
 *                  probabilité de sommets souhaité à ps.                                      *
 *                                                                                             *
 * Fonctions :                                                                                 *
 *                                                                                             *
 *      - affichage (graph g) : Fonction qui utilise la classe bitmap_image.hpp afin de créer  *
 *                   une image représantant graphe g passé en paramètre.                       *
 *                   Cette fonction ne prend pas en compte la taille du graphe considéré,      *
 *                   pour des tailles supérieures à 40 l'affichage n'est pas vraiment lisible  *
 *                   mais l'exécution de cette fonction est rapide.                            *
 *      - affichageproportionnel (graph g) : Fonction qui utilise la classe bitmap_image.hpp   *
 *                   afin de créer une image représantant graphe g passé en paramètre.         *
 *                   Cette fonction prend en compte la taille du graphe considéré, pour des    *
 *                   tailles inférieures à 500 l'affichage est lisible mais l'exécution de     *
 *                   cette fonction est proportionnelle à la taille du graphe considéré donc   *
 *                   peut être relativement long.                                              *
 *                   Pour des tailles supérieures à 500 il est conseillé de ne pas essayer     *
 *                   d'afficher le graphe car le temps d'exécution est très long et l'image    *
 *                   prend beaucoup de place sur le disque (supérieur à 1G).                   *
 *                                                                                             *
 * Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
 ***********************************************************************************************
*/

#ifndef graph_h
#define graph_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <array>
#include <random>
#include <string.h>

#include "Aretes.h"
#include "Point.h"
#include "bitmap_image.hpp"

struct graph {
    int taille;
    double psommet;
    double parete;
    bool triangle;
    std::vector<Point> sommets;
    std::vector<Arete> aretes;
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > voisin;
    
    graph(int);
    graph(int, double, bool);
    graph(int, double, double, bool);
};


graph::graph (int n) {
        std::cout << "Entrez une probabilité pour les arètes (en décimal) : ";
        std::cin >> parete;
        std::cout << "Entrez une probabilité pour les sommets (en décimal) : ";
        std::cin >> psommet;
        std::string reponse;
        std::cout << "Voulez vous un réseau triangulaire ? : ";
        std::cin >> reponse;
        std::string rep = reponse;

        if ((rep == "oui") or (rep == "Oui")){
            triangle=true;
        }
        else {
            triangle= false;
        }
//    triangle = false;
//    parete = 0.53;
//    psommet =1;
    taille = n;
    
    sommets.push_back(Point(300,300)); // création du point source
    
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            sommets.push_back(Point(i,j));  // stockage des sommets
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis_y(0, 1);
            double alea= dis_y(gen);
            if (alea>psommet){
                sommets.back().here = false;  // selon la probabilités souhaité les sommets seront considéré comme existants si here = true
            }
        }
    }
    sommets.push_back(Point(-100,-100)); // création du point puits
    
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > v(sommets.size());  // vecteur où l'on stocke les indices des points et l'indice de ses voisins
    
    if (triangle == false) {
        std::cout << "" << std::endl;
        std::cout << "Voici un réseau carré"<<std::endl;
    }
    else {
        std::cout << "" << std::endl;
        std::cout << "Voici un réseau triangulaire"<<std::endl;
    }
    
    if (triangle == false) { // construction d'un réseau carré
        for (int i = 1; i < sommets.size()-2; i++) {
            v[i].first = i;
            std::vector<int> voisin;
            if ( ((i % n) != 0) and (i<(n-1)*n) ) { // les voisins des points supérieur gauche
                voisin.push_back(i+1);
                voisin.push_back(i+n);
            }
            else if ( ((i % n) == 0) and (i!=n*n) ) {  // ligne du bas
                voisin.push_back(i+n);
            }
            else if ((i>(n-1)*n) and (i!=n*n) ) {  //colonne de gauche
                voisin.push_back(i+1);
            }
        for (int j : voisin) {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_real_distribution<> dis_x(0, 1);
                    double alea = dis_x(gen);
                        if ((alea<parete) and (sommets[i].here) and (sommets[j].here) ) { // selon la probabilités choisi et l'existance ou non des points on créé des arêtes
                            std::array<Point, 2> a1{ {sommets[i], sommets[j]} };
                            std::array<Point, 2> a2{ {sommets[j], sommets[i]} };
                            aretes.push_back(a1);
                            aretes.push_back(a2);
                            v[i].second.push_back(j);
                            v[j].second.push_back(i);
                        }
                    }
                }
        }
    else { // construction d'un graph triangulaire
        for (int i = 1; i < sommets.size()-2; i++) {
            v[i].first = i;
            std::vector<int> voisin;
            if ( ((i % n) != 0) and (i<(n-1)*n) ) { // les voisins des points supérieur gauche
                voisin.push_back(i+1);
                voisin.push_back(i+n);
                voisin.push_back(i+n+1);
            }
            else if ( ((i % n) == 0) and (i!=n*n) ) {  // ligne du bas
                voisin.push_back(i+n);
            }
            else if ((i>(n-1)*n) and (i!=n*n) ) {  //colonne de gauche
                voisin.push_back(i+1);
            }
        for (int j : voisin) {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_real_distribution<> dis_x(0, 1);
                    double alea = dis_x(gen);
                    if ((alea<parete) and (sommets[i].here) and (sommets[j].here)) { // selon la probabilités choisi et l'existance ou non des points on créé des arêtes
                        std::array<Point, 2> a1{ {sommets[i], sommets[j]} };
                        std::array<Point, 2> a2{ {sommets[j], sommets[i]} };
                        aretes.push_back(a1);
                        aretes.push_back(a2);
                        v[i].second.push_back(j);
                        v[j].second.push_back(i);
                    }
                }
            }
    }
    v[0].first = 0; // le premier élément est le point d'indice 0
    for (int i = 1; i <= n;i++) { // pour chaque points sur la colonne de gauche on prend l'indice de ces point comme voisins de la source (d'indice 0)
        v[0].second.push_back(i);
        v[i].second.push_back(0);
    }
    
    v[sommets.size()-1].first = sommets.size()-1;
    v[sommets.size()-2].first = sommets.size()-2;
    for (int i = (n-1)*n+1; i <= sommets.size()-2;i++) { // pour chaque points sur la colonne de droite on prend l'indice de ces point comme voisins du puits (dernier élément de sommet)
        v[sommets.size()-1].second.push_back(i);
        v[i].second.push_back(sommets.size()-1);
    }
    
    voisin = v; // on associe l'argument de graph à la valeur v ( vecteur complet précédédemment)
    
    for (Point p : sommets) {
        if ((p.get_x()==1)and (p.here)){
            std::array<Point, 2> a1{ {sommets[0], p} };
            std::array<Point, 2> a2{ {p, sommets[0]} };
            aretes.push_back(a1);     // creation des aretes avec la source
            aretes.push_back(a2);
        }
    }
    
    for (Point p : sommets) {
        if ((p.get_x()==n)and (p.here)) {
            std::array<Point, 2> a1{ {sommets[sommets.size()-1], p} };
            std::array<Point, 2> a2{ {p, sommets[sommets.size()-1]} };
            aretes.push_back(a1);     // creation des aretes avec le puit
            aretes.push_back(a2);
    
        }
    }
}

graph::graph (int n, double p, double ps, bool forme) {
    
    // les commentaires sont identiques au premier constructeur
    
    
    triangle = forme;
    parete = p;
    psommet = ps;
    taille = n;
    
    sommets.push_back(Point(300,300)); // création du point source
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                sommets.push_back(Point(i,j));  // stockage des sommets
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis_y(0, 1);
                double alea= dis_y(gen);
                if (alea>psommet){
                    sommets.back().here = false;  // selon la probabilités souhaité les sommets seront considéré comme existants si here = true
                }
            }
        }
        sommets.push_back(Point(-100,-100)); // création du point puits
        
        std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > v(sommets.size());  // vecteur où l'on stocke les indices des points et l'indice de ses voisins
        
        
        if (triangle == false) { // construction d'un réseau carré
            for (int i = 1; i < sommets.size()-2; i++) {
                v[i].first = i;
                std::vector<int> voisin;
                if ( ((i % n) != 0) and (i<(n-1)*n) ) { // les voisins des points supérieur gauche
                    voisin.push_back(i+1);
                    voisin.push_back(i+n);
                }
                else if ( ((i % n) == 0) and (i!=n*n) ) {  // ligne du bas
                    voisin.push_back(i+n);
                }
                else if ((i>(n-1)*n) and (i!=n*n) ) {  //colonne de gauche
                    voisin.push_back(i+1);
                }
            for (int j : voisin) {
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_real_distribution<> dis_x(0, 1);
                        double alea = dis_x(gen);
                            if ((alea<parete) and (sommets[i].here) and (sommets[j].here) ) { // selon la probabilités choisi et l'existance ou non des points on créé des arêtes
                                std::array<Point, 2> a1{ {sommets[i], sommets[j]} };
                                std::array<Point, 2> a2{ {sommets[j], sommets[i]} };
                                aretes.push_back(a1);
                                aretes.push_back(a2);
                                v[i].second.push_back(j);
                                v[j].second.push_back(i);
                            }
                        }
                    }
            }
        else { // construction d'un graph triangulaire
            for (int i = 1; i < sommets.size()-2; i++) {
                v[i].first = i;
                std::vector<int> voisin;
                if ( ((i % n) != 0) and (i<(n-1)*n) ) { // les voisins des points supérieur gauche
                    voisin.push_back(i+1);
                    voisin.push_back(i+n);
                    voisin.push_back(i+n+1);
                }
                else if ( ((i % n) == 0) and (i!=n*n) ) {  // ligne du bas
                    voisin.push_back(i+n);
                }
                else if ((i>(n-1)*n) and (i!=n*n) ) {  //colonne de gauche
                    voisin.push_back(i+1);
                }
            for (int j : voisin) {
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_real_distribution<> dis_x(0, 1);
                        double alea = dis_x(gen);
                        if ((alea<parete) and (sommets[i].here) and (sommets[j].here)) { // selon la probabilités choisi et l'existance ou non des points on créé des arêtes
                            std::array<Point, 2> a1{ {sommets[i], sommets[j]} };
                            std::array<Point, 2> a2{ {sommets[j], sommets[i]} };
                            aretes.push_back(a1);
                            aretes.push_back(a2);
                            v[i].second.push_back(j);
                            v[j].second.push_back(i);
                        }
                    }
                }
        }
        v[0].first = 0; // le premier élément est le point d'indice 0
        for (int i = 1; i <= n;i++) { // pour chaque points sur la colonne de gauche on prend l'indice de ces point comme voisins de la source (d'indice 0)
            v[0].second.push_back(i);
            v[i].second.push_back(0);
        }
        
        v[sommets.size()-1].first = sommets.size()-1;
        v[sommets.size()-2].first = sommets.size()-2;
        for (int i = (n-1)*n+1; i <= sommets.size()-2;i++) { // pour chaque points sur la colonne de droite on prend l'indice de ces point comme voisins du puits (dernier élément de sommet)
            v[sommets.size()-1].second.push_back(i);
            v[i].second.push_back(sommets.size()-1);
        }
        
        voisin = v; // on associe l'argument de graph à la valeur v ( vecteur complet précédédemment)
        
        for (Point p : sommets) {
            if ((p.get_x()==1)and (p.here)){
                std::array<Point, 2> a1{ {sommets[0], p} };
                std::array<Point, 2> a2{ {p, sommets[0]} };
                aretes.push_back(a1);     // creation des aretes avec la source
                aretes.push_back(a2);
            }
        }
        
        for (Point p : sommets) {
            if ((p.get_x()==n)and (p.here)) {
                std::array<Point, 2> a1{ {sommets[sommets.size()-1], p} };
                std::array<Point, 2> a2{ {p, sommets[sommets.size()-1]} };
                aretes.push_back(a1);     // creation des aretes avec le puit
                aretes.push_back(a2);
        
            }
        }
    }


std::ostream & operator << (std::ostream & os, const graph & g) {  // surcharge de l'opérateur chevron afin d'afficher un graph
    os<<"\n";                                                      // ici nous donne le nombre de point du corps du grpah ainsi que le nombre d'arêtes
    int k =0;
    for (int i =0; i < g.sommets.size(); i++){
        if (g.sommets[i].here) {
            k++;
        }
    }
    os << "Nombre de sommets : " << k-2<<"\n";
    os << "Nombre d'aretes : " << g.aretes.size()/2<<"\n"<<"\n";
    return os;
}

void affichage(graph g) {
    
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
            if ((i <= n) and (i==iprime)) { // affichage aretes horizontales
                draw.line_segment((image.width() -925)+(i-1)*distance, (image.height() -925)+(j-1)*distance, (image.width() -925)+(i-1)*distance, (image.height() -925)+distance+(j-1)*distance);
            }
            if ((j <= n)and (j==jprime) ) {  // affichage aretes verticales
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
    
    image.save_image("graph.bmp");  // nom de l'image crée
}

void affichageproportionnel(graph g) {
    int n=g.taille;
    int distance=36;

    bitmap_image image(40*n,40*n); // création d'une image de taille variable en fonction de la taille de graph souhaité
    
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
            if ((i <= n) and (i==iprime)) { // affichage aretes horizontales
                draw.line_segment((image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+(j-1)*distance, (image.width() *0.075)+(i-1)*distance, (image.height() *0.075)+distance+(j-1)*distance);
            }
            if ((j <= n)and (j==jprime) ) {  // affichage aretes verticales
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
    
    image.save_image("graph.bmp");  // nom de l'image crée
}

#endif /* graph_h */
