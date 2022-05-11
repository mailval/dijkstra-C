/*
***********************************************************************************************
*                                                                                             *
*                                    Classe : PriorityQueue                                    *
*                                        Projet M326                                          *
*                                                                                             *
* Author: MAILLO Valentin & COLARD-CLAUDY Maéva - 2020                                        *
*                                                                                             *
* Fichier repris d'un TP éffectue au S5 en M312.                                              *
*                                                                                             *
* Arguments :                                                                                 *
*                                                                                             *
*      - value_type : Type des elements contenus.                                             *
*                                                                                             *
*      - std::vector<value_type> data : Tableau nommé data, au bout duquel les nouveaux       *
*                    éléments seront insérés.                                                 *
*                                                                                             *
*      - IndexType : Entier désignant le premier élément de data qui n'est pas encore "sorti".*
*                                                                                             *
* Constructeurs :                                                                             *
*                                                                                             *
*      - push(const value_type &) : Fonction qui permet d'inserer un élément.                  *
*                                                                                             *
*      - pop() : Fonction qui permet de supprimer l'élément au sommet.                        *
*                                                                                             *
*      - value_type & top() const : Fonction qui permet un accès à l'élément au sommet.       *
*                                                                                             *
*      - empty() const : Fonction qui nous indique si le conteneur est vide ou non.           *
*                                                                                             *
*      - OrderUp(IndexType i) : Fonction récursive qui réorganise data en inserant des        *
*                    éléments.                                                                *
*                                                                                             *
*      - OrderDown(IndexType i) : Fonction récursive qui réorganise data en supprimant des    *
*                    éléments.                                                                *
*                                                                                             *
*                                                                                             *
* Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
***********************************************************************************************
*/

#ifndef PriorityQueue_h
#define PriorityQueue_h
#include <vector>
#include <cassert>

template<typename T>
struct PriorityQueue {
    using value_type = T;
    void push(const value_type &);
    void pop();
    const value_type & top() const;
    bool empty() const {return data.size()==1;}
    
protected:
    typedef long IndexType;
    void OrderUp(IndexType i);
    void OrderDown(IndexType i);
    std::vector<value_type> data = {value_type()};
};


template<typename T> void
PriorityQueue<T>::push(const value_type & node){
    data.push_back(node);
    OrderDown(data.size()-1);
}

template<typename T> auto
PriorityQueue<T>::top() const -> const value_type & {
    assert(data.size()>=2);
    return data[1];
}

template<typename T> void
PriorityQueue<T>::pop(){
    assert(!empty());
    if (data.size()==2) {return data.pop_back();}
    data[1]=data.back();
    data.pop_back();
    OrderUp(1);
}

template<typename T> void
PriorityQueue<T>::OrderDown(IndexType i) {
    if(i==1) return;
    assert(i<data.size());
    assert(i>0);
    const IndexType j = i/2;
    if(data[j]>=data[i]) return;
    std::swap(data[i], data[j]);
    OrderDown(j);
}

template<typename T> void
PriorityQueue<T>::OrderUp(IndexType i){
    assert(i>0 && i<data.size());
    const IndexType j = 2*i, k = j+1;
    if(k>=data.size()){
        if(j>=data.size() || data[j]<=data[i]) return;
        std::swap(data[i], data[j]);
    } else {
        const IndexType l = (data[j]>=data[k] ? j : k);
        if(data[i]>=data[l]) return;
        std::swap(data[i],data[l]);
        return OrderUp(l);
    }
}


#endif /* PriorityQueue_h */
