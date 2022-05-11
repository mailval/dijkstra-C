/*
*******************************************************************************
*                                                                             *
*                 Problème du plus court chemin                               *
*                                                                             *
*                                                                             *
* Author: MAILLO Valentin & COLARD-CLAUDY Maéva                               *
*                                                                             *
* Note: Projet réalisé au cours de la licence L3 MINT à l'université          *
*       Paris-Saclay                                                          *
*                                                                             *
* Copyright © 2020 Maeva COLARD-CLAUDY & Valentin MAILLO. All rights reserved.*
*                                                                             *
*******************************************************************************
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <array>
#include <random>
#include <cmath>

#include "graph.h"
#include "Aretes.h"
#include "Dijkstra.h"
#include "musee.h"
#include "bitmap_image.hpp"

void probacritiqueAretes() {
    int n = 100;  // taille du graph concidéré
    double k = 0;  // compteur
    int nb = 100;  // nombre d'observations
    bool forme = false; // forme du graph souhaité (si true crée des graphes triangulaire, false crée des graphes carré)
    for (int i = 0; i < nb; i++ ) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis_x(0, 1);
        double p = dis_x(gen);  // création d'un double aléatoire compris entre 0 et 1
        graph g = graph(n,p,1, forme);  // création d'un graph de taille n, p représente la probabilité de création des aretes, de forme souhaitée
        std::pair<std::vector<double>,std::vector<int>> values2 = DijkstraFM(g); // cherche le plus court chemin entre tout les points du graph
        if ( values2.first[g.sommets.size()-1] > 10e8) { // si y'a pas un chemin entre le soucre et le puit
            k++;
        }
    }
    std::cout <<"la probabilité critique observé pour un graph de taille " << n << " pour " << nb << " observations est de " << k/nb<< std::endl;
}

void probacritiqueSommet() {
    int n = 100;  // taille du graph concidéré
    double k = 0;  // compteur
    int nb = 100;  // nombre d'observations
    bool forme = true; // forme du graph souhaité (si true crée des graphes triangulaire, false crée des graphes carré)
    for (int i = 0; i < nb; i++ ) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis_x(0, 1);
        double p = dis_x(gen);  // création d'un double aléatoire compris entre 0 et 1
        graph g = graph(n,1,p, forme);  // création d'un graph de taille n, p représente la probabilité de création des sommet, de forme souhaitée
        std::pair<std::vector<double>,std::vector<int>> values2 = DijkstraFM(g); // cherche le plus court chemin entre tout les points du graph
        if ( values2.first[g.sommets.size()-1] > 10e8) { // si y'a pas un chemin entre le soucre et le puit
            k++;
        }
    }
    std::cout <<"la probabilité critique observé pour un graph de taille " << n << " pour " << nb << " observations est de " << k/nb<< std::endl;
}


int main(int argc, const char * argv[]) {
    
    float temps;
    clock_t t1, t2;
    
    t1 = clock();
    
    int n;
    std::cout << "Entrez la taille du graphe souhaité : ";
    std::cin >> n;
    
    
    TestDijkstra(n);
    
    std::string reponse;
    std::cout << "Voulez vous executer le calcul du chemin le plus court pour le musée ? : ";
    std::cin >> reponse;
    std::string rep = reponse;
    
    if ((rep == "oui") or (rep == "Oui")) {
        std::cout << "Vous avez besoins de l'image musee.bmp fourni dans le rendu. " << std::endl;
        TestMusee();
    }
    
    
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    std::cout<< " " << std::endl;
    std::cout<< "le temps d'execution a été de " << temps << "s" <<std::endl;


return 0;
}
