/*
 ***********************************************************************************************
 *                                                                                             *
 *                                       Classe : Point                                        *
 *                                        Projet M326                                          *
 *                                                                                             *
 * Author: MAILLO Valentin & COLARD-CLAUDY Maéva - 2020                                        *
 *                                                                                             *
 *                                                                                             *
 * Arguments :                                                                                 *
 *                                                                                             *
 *      - coords : Tableau de double de taille 2. Le premier double représente la coordonnée x *
 *               d'un point. Le deuxième double représente la coordonnée y pour un point de    *
 *               coordonnée (x,y)                                                              *
 *      - blue : Booléen créé uniquement pour l'exploitation du plan du musée. Si le pixel     *
 *               correspondant au point considéré est bleu l'argument est "true", "false" si   *
 *               il n'est pas bleu. Utilisé dans la classe musée.                              *
 *      - red : Booléen créé uniquement pour l'exploitation du plan du musée. Si le pixel      *
 *               correspondant au point considéré est rouge l'argument est "true", "false" si  *
 *               il n'est pas rouge. Utilisé dans la classe musée.                             *
 *      - here : Booléen qui permet de savoir si le point peut recevoir des arêtes, "true" il  *
 *               il est considéré comme présent donc peut recevoir des arêtes, "false" il est  *
 *               considéré comme inéxistant donc ne peut pas recevoir d'arêtes.                *
 *                                                                                             *
 * Constructeur :                                                                              *
 *                                                                                             *
 *      - Point (double x, double y) : Constructeur qui associe au premier élément du tableau  *
 *               coords le double x et au deuxième élément du tableau coords le double y.      *
 *                                                                                             *
 * Fonctions :                                                                                 *
 *                                                                                             *
 *      - get_x() : Fonction qui renvoie le premier élément de coords.                         *
 *                                                                                             *
 *      - get_y() : Fonction qui renvoie le deuxième élément de coords.                        *
 *                                                                                             *
 *      - distance(const Point & A, const Point & B) : Fonction qui calcule la distance        *
 *               euclidienne entre le point A et le point B.                                   *
 *                                                                                             *
 * Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
 ***********************************************************************************************
*/


#ifndef Point_h
#define Point_h

struct Point {
public :
    
    bool blue;
    bool red;
    bool here;
    
    Point (double , double);
    
    double get_x () const &;
    double get_y () const &;
    
    bool operator==(Point const&);
    bool operator!=(Point const&);
    
    
protected :
    std::array<double,2> coords;

};

Point::Point (double x_, double y_) {
    // constructeur de Point qui prend deux doubles x et un y en argument
        coords[0] = x_;
        coords[1] = y_;
    blue = false;
    red = false;
    here = true;
    }

double Point:: get_x () const &{  // renvoi la cordonné x du point
    return coords[0];
}
    
double Point:: get_y () const &{  // renvoi la cordonné y du point
    return coords[1];
}

std::ostream & operator << (std::ostream & os, const Point & P) {  // permet d'afficher un point de la maniere suivante (x,y)
    os << "(" << P.get_x() << "," << P.get_y() << ")" ;
    return os;
}

double distance(const Point & A, const Point & B){ // calcul la distance euclidienne entre deux points
    return std::sqrt( (B.get_x()- A.get_x()) * (B.get_x()-A.get_x()) + (B.get_y()- A.get_y()) * (B.get_y()- A.get_y()) );
}

bool Point::operator==(Point const& b) {  // retourne true si les points sont identiques et false si ils sont différents
    if (get_x() == b.get_x() && get_y() == b.get_y())
        return true;
    else
        return false;
}

bool Point::operator!=(Point const& b) { // retourne true si les points sont différents et false si ils sont identiques
    if (get_x() != b.get_x() or get_y() != b.get_y())
        return true;
    else
        return false;
}

#endif /* Point_h */
