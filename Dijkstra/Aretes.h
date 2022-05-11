/*
 ***********************************************************************************************
 *                                                                                             *
 *                                       Classe : Arete                                        *
 *                                        Projet M326                                          *
 *                                                                                             *
 * Author: MAILLO Valentin - 2020                                                              *
 *                                                                                             *
 *                                                                                             *
 * Arguments :                                                                                 *
 *                                                                                             *
 *      - points : Tableau de type Point de taille 2. Le premier élément de ce tableau est     *
 *             le premier point de l'arête. Le second élément de ce tableau est le second      *
 *             point de l'arête.                                                               *
 *                                                                                             *
 * Constructeur :                                                                              *
 *                                                                                             *
 *      - Arete(std::array<Point, 2>) : Constructeur de Arête qui prend en argument un tableau *
 *                       de type Point de taille 2, et l'associe à Point.                      *
 *                       La forme particulière de ce constructeur est dûe au fait que le type  *
 *                       de ce tableau est un type créé et pas un type par défaut.             *
 *                                                                                             *
 * Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
 ***********************************************************************************************
*/

#ifndef Aretes_h
#define Aretes_h

#include "Point.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>



struct Arete {
    std::array<Point,2> points;  
    Arete(std::array<Point, 2>);
    bool operator==(Arete const&);
};

Arete::Arete(std::array<Point, 2> a)
    : points(a)
{}

bool Arete::operator==(Arete const& a) {
    if (points[0] == a.points[0] and points[1] == a.points[1]) {
        return true;
    }
    else{
        return false;
    }
        
}

#endif /* Aretes_h */
