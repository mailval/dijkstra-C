/*
 ***********************************************************************************************
 *                                                                                             *
 *                                       Classe : Musée                                        *
 *                                         Projet M326                                         *
 *                                                                                             *
 * Author: MAILLO Valentin & COLARD-CLAUDY Maéva - 2020                                        *
 *                                                                                             *
 *                                                                                             *
 * Fonctions :                                                                                 *
 *                                                                                             *
 *      - ChargerImage() : Cette fonction permet d'extraire les informations utiles            *
 *                 de la photo musee.bmp.                                                      *
 *                 Ici, l'idée est de créer les mêmes élèments que dans la classe graph utiles *
 *                 à l'exécution de l'algorithme de Dijkstra.                                  *
 *                 On crée donc un vecteur de Point nommé "sommets" où on associe              *
 *                 à chaque pixel un point, si le pixel est bleu alors l'argument blue de      *
 *                 Point est "true", si il est rouge l'argument de Point red est "true", sinon *
 *                 le pixel est noir.                                                          *
 *                 Puis on crée un vecteur de paire v, le premier élément de la paire est      *
 *                 un entier qui stocke chaque indice des points créés auparavant.             *
 *                 Le second élement de la paire est un vecteur d'entier stockant l'indice     *
 *                 des voisins du point correspondant à l'indice du premier élément de         *
 *                 la paire.                                                                   *
 *                 Donc pour chaque point, on a son indice et l'indice de ses voisins,         *
 *                 évidemment les points bleus voisins sont reliés, de la même façon les       *
 *                 points rouges et les points bleus voisins sont réliés.                      *
 *                                                                                             *
 *      - DijkstraMusee(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,    *
 *                 std::vector<unsigned long> > > > info) : Cet algorithme est l'algorithme de *
 *                 Dijkstra que l'on utilise pour trouver la distance la plus courte entre     *
 *                 chaque point bleu et la sortie la plus proche.                              *
 *                 De la même façon on stocke le meilleurs voisins de chaque points.           *
 *                 Le calcul de la distance se fait par la méthode de Fast-Marching.           *
 *                                                                                             *
 *      - DijkstraMusee1(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,   *
 *                 std::vector<unsigned long> > > > info) : Cet algorithme est l'algorithme de *
 *                 Dijkstra. Ici cet algorithme retrourne un tableau de booléen.               *
 *                 Cette fonction nous permet de savoir si le déplacement lors d'une occurence *
 *                 Est sur l'axe des x et ou l'axe des y.                                      *
 *                 Cette fonction sert uniquement à implémenter la méthode de chemin optimal.  *
 *                                                                                             *
 *      - DijkstraMuseeOpti(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long, *
 *                 std::vector<unsigned long> > > > info, std::vector<double> valeurs,         *
 *                 std::vector<bool> direction) : Cet algorithme est l'algorithme de chemin    *
 *                 optimal. Ici cet algorithme prend les mêmes arguments que l'algorithme de   *
 *                 Dijkstra, un vecteur de booléen direction qui nous permet de savoir dans    *
 *                 sens se fait le déplacment, vers le haut ou vers la gauche et un vecteur de *
 *                 double qui stocke pour tous points du plan la distance entre ce point et sa *
 *                 sortie la plus proche.                                                      *
 *                 Cette fonction retourne un vecteur de paire qui stocke le meilleur voisin de*
 *                 chaque point, le premier élément la paire de chaque occurence de ce vecteur *
 *                 est la coordonnées x et le deuxieme élement de la paire est la coordonnée y.*
 *                                                                                             *
 *      - pcmMusee(std::pair<std::vector<double>,std::vector<int>> values, int alea) : Cette   *
 *                 fonction prend en argument une paire de vecteur du même type que ce qui est *
 *                 renvoyé par l'algorithme de Dijkstra pour le musée. Il retrouve le chemin   *
 *                 le plus court entre la sortie la plus proche et le point d'indice aléatoire.*
 *                 Pour ce faire on utilise la méthode de BackTracking.                        *
 *                 Comme dans l'algorithme de Dijkstra on s'intéresse uniquement aux indices   *
 *                 des points.                                                                 *
 *                                                                                             *
 *      - sortiemusee(std::vector<int> pcm, std::vector<Point> sommets) : Cette fonction       *
 *                 permet de créer une image qui recopie le plan du musée et y ajoute le       *
 *                 chemin le plus court entre un point et la sortie la plus proche.            *
 *                                                                                             *
 *      - affichagepcmproportionnel(graph g, std::vector<int> pcm ) : Cette fonction permet de *
 *                 créer une image représentant le graphe et trace le chemin le plus court     *
 *                 entre la source et le puits.                                                *
 *                 Ici on réutilise le code de la fonction affichageproportionnel de la        *
 *                 classe graph en ajoutant une partie pour tracer les arêtes par lesquelles   *
 *                 il faut passer pour rejoindre la source et le plus rapidement possible.     *
 *                 Cette fonction prend en paramètre un graphe g qu'elle représente            *
 *                 de la même façon que dans la fonction affichageproportionnel de la          *
 *                 classe graph et un vecteur d'entier (type de retour de la fonction          *
 *                 PlusCourtChemin) qui est parcouru afin de tracer en rouge le chemin le plus *
 *                 court entre la source et le puits.                                          *
 *                 Les mêmes conseils seront donnés concernant l'utilisation de cette fonction.*
 *                                                                                             *
 *      - TestMusee() : Cette fonction permet de tester notre algorithme de Dijkstra pour le   *
 *                 musée.                                                                      *
 *                 En exécutant cette fonction on affiche la distance entre chaque point et    *
 *                 la sortie la plus proche. On tire un point bleu au hasard et on crée une    *
 *                 image qui trace le chemin le plus court entre ce point et la sortie la      *
 *                 plus proche.                                                                *
 *                                                                                             *
 * Copyright © 2020 Valentin Maillo & Maéva Colard-Claudy. All rights reserved.                *
 ***********************************************************************************************
*/


#ifndef musee_h
#define musee_h

#include "Point.h"
#include "Aretes.h"


std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > > ChargerImage() {
    
    bitmap_image image("musee.bmp");
    
    if (!image)
    {
        printf("Error - Failed to open: musee.png\n");
    }
    
    std::vector<Point> sommets;
    std::vector<Arete> aretes;
    
    
    const unsigned int height = image.height();
    const unsigned int width  = image.width();
    
    sommets.push_back(Point(0,0));  // création du point source
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            
            rgb_t colour;
            
            image.get_pixel(x, y, colour);
            sommets.push_back(Point(x+1,y+1)); // création des points du graph
            if ( (colour.blue == 255) and (colour.green == 50) and (colour.red == 4)){
                sommets.back().blue = true;  //permet de savoir si un point est bleu ==> si ce n'est pas un mur
            }
            if ( (colour.blue == 0) and (colour.green == 38) and (colour.red == 255)){
                sommets.back().red = true;  //permet de savoir si un point est rouge ==> si ce n'est pas un mur
            }
        }
    }
    
    sommets.push_back(Point(-100,-100));  // ajout du point source fictif qui est relié à tout les points rouges
    
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > v(sommets.size()); // creation du vecteur qui stockera tout les indices des points ainsi que l'indice de leurs voisins
    
    for (int i = 1; i < sommets.size()-2; i++) { // réutilisation de la méthode utilisée pour le graphe
        v[i].first = i;
        std::vector<int> voisin;
        voisin.push_back(i+1);
        voisin.push_back(i+height);
        for (int j : voisin) {
            if ( ((sommets[i].blue) and (sommets[j].blue)) or ((sommets[i].red) and (sommets[j].red)) or ((sommets[i].blue) and (sommets[j].red)) or ((sommets[i].red) and (sommets[j].blue)) ) {
                std::array<Point, 2> a1{ {sommets[i], sommets[j]} };
                std::array<Point, 2> a2{ {sommets[j], sommets[i]} };
                aretes.push_back(a1);
                aretes.push_back(a2);
                v[i].second.push_back(j);
                v[j].second.push_back(i);
            }
        }
    }
    
    v[0].first = 0; // la source a pour indice 0
    for (int i = 0; i < sommets.size();i++) { // on relie tout les points rouges à la source afin de choisir la sortie la plus proche pour chaque points
        if (sommets[i].red){
            v[0].second.push_back(i);
            v[i].second.push_back(0);
        }
    }
    
    v[sommets.size()-1].first = sommets.size()-1;
    v[sommets.size()-2].first = sommets.size()-2;
    
    v[sommets.size()-1].second.push_back(110350); // le points cible fictif (qui est un point bleu choisi arbitrairement)
    
    return { sommets, v} ;
}

std::pair<std::vector<double>,std::vector<int>> DijkstraMusee(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > > info) {
    
    //Variables
    std::vector<Point> sommets = info.first;
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > voisin = info.second;
    const size_t n = sommets.size(); // nombre de sommet du graph
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
    
    
    while (!queue.empty()) { // Tant qu'il existe i tel que final[i] == false  et que nous sommes pas arrivé jusqu'au puits
        
        const int i = queue.top().second; // Indice du point traité à cette itration
        queue.pop();
        if (final[i]) continue; // Traitement déja fait
        
        final[i] = true;
        
        for (auto voisin : voisin[i].second) { // Pour tout voisin j de i tel que final[j] == false
            unsigned long j = voisin;
            
            double dist;
            Point repere1 = sommets[i];
            Point repere2 = sommets[j];
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

std::vector<bool> DijkstraMusee1(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > > info) {
    
    //Variables
    std::vector<Point> sommets = info.first;
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > voisin = info.second;
    const size_t n = sommets.size(); // nombre de sommet du graph
    std::vector<double>  valeurs;
    std::vector<bool> final;
    PriorityQueue<std::pair<double ,int >> queue;
    std::vector<int> meilleurVoisins(n);
    std::vector<bool> direction(n);
    
    
    // Initialisation
    valeurs.resize(n,1/0.); // Initialise le tableau valeurs de taille n à +infinie
    valeurs[0]=0; // Sauf pour la source où il vaut 0
    queue.push({0,0});
    meilleurVoisins[0]=0; // Le meilleur voisin de la source est lui même
    
    
    
    final.resize(n, false); // Initialise le tableau final de taille n à false
    
    for (int i = 0; i < n; i++) queue.push({ -valeurs[i], i });
    
    
    while (!queue.empty()) { // Tant qu'il existe i tel que final[i] == false  et que nous sommes pas arrivé jusqu'au puits
        
        const int i = queue.top().second; // Indice du point traité à cette itration
        queue.pop();
        if (final[i]) continue; // Traitement déja fait
        
        final[i] = true;
        
        for (auto voisin : voisin[i].second) { // Pour tout voisin j de i tel que final[j] == false
            unsigned long j = voisin;
            
            double dist;
            Point repere1 = sommets[i];
            Point repere2 = sommets[j];
            if (i==0 or i == n-1 or j==0 or j == n-1) {
                dist = 1;
            }
            else {
                dist = distance(repere1, repere2);
            }
            if ( sommets[i].get_x() == sommets[j].get_x()) {
                direction[j] = false; // dx : mouvement vers le haut ou le bas
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
    
    return direction;
}

std::vector<std::pair< double ,double > > DijkstraMuseeOpti(std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > > info, std::vector<double> valeurs, std::vector<bool> direction) {
    
    //Variables
    std::vector<Point> sommets = info.first;
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > voisin = info.second;
    const size_t n = sommets.size(); // nombre de sommet du graph
    int h = 0.5;
    std::vector<std::pair< double ,double > > gamma(n);
    
    gamma[0].first = valeurs[110350];
    
    gamma[0].second = valeurs[110350];
    
    for(int i = 1; i < n; i++) {
        std::pair<double, double> D;
        if (direction[i]) {
            D.first  = 0;
            D.second  = valeurs[i];
        }
        else {
            D.first  = valeurs[i];
            D.second  = 0;
        }
        gamma[i].first = sommets[i].get_x() - h * D.first;
        gamma[i].second = sommets[i].get_y() - h * D.second;
    }
    
    return gamma;
}



std::vector<int> pcmMusee(std::pair<std::vector<double>,std::vector<int>> values, int alea) {
    // Initialisation
    const size_t n = values.first.size();
    int distance = values.first[alea];     // taille de notre plus court chemin
    std::vector<int> pluscourtchemin;

    // les premieres valeurs seront toujours le puits et son meilleur voisin
    pluscourtchemin.push_back(alea);
    pluscourtchemin.push_back(values.second[alea]);
    
    
    for (int k =0;k<distance-1;k++)
        for (int i = 0; i < n; i++ ){
            if (pluscourtchemin.back() == i) {
                if (pluscourtchemin.back() == 0) break;
                    pluscourtchemin.push_back(values.second[i]);
                }
    }
    return pluscourtchemin;
}

void sortiemusee(std::vector<int> pcm, std::vector<Point> sommets) {
    
    bitmap_image image("musee.bmp");
    
    if (!image)
    {
        printf("Error - Failed to open: musee.png\n");
    }
    
    const unsigned int height = image.height();
    const unsigned int width  = image.width();
    
    bitmap_image musee(width,height);
    musee.set_all_channels(255, 255, 255);
    
    image_drawer draw(musee);
    
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            rgb_t colour;
            image.get_pixel(x, y, colour);
            musee.set_pixel(x, y, colour.red, colour.green , colour.blue);
        }
    }

    for(unsigned long k = pcm.size()-2; k>= 1;k--) {
        int i = sommets[pcm[k]].get_x();
        int j = sommets[pcm[k]].get_y();

        musee.set_pixel(i, j, 255, 0 , 0);
    }
    musee.save_image("sortie.bmp");
}

void TestMusee(){
    
    std::pair<std::vector<Point>,std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > > info = ChargerImage();
    std::vector<Point> sommets = info.first;
    std::vector<std::pair< unsigned long ,std::vector<unsigned long> > > voisin = info.second;
    
    std::pair<std::vector<double>,std::vector<int>> values = DijkstraMusee(info);
    
    
//    std::vector<bool> direction = DijkstraMusee1(info);
//    std::vector<std::pair< double ,double > > values2 = DijkstraMuseeOpti(info , values.first, direction);
    
    for (int i = 1; i< values.first.size(); i++) {
        if (values.first[i]<10e8 and sommets[i].blue) {  // on affiche la distance entre tout les points bleu et leurs sortie la plus proche
            std::cout << "La distance la plus courte du point "  << sommets[i] << " vers la sortie la plus proche est de " <<values.first[i]-1 << std::endl;
        }
    }
    

//    for (int i = 1; i< values2.size(); i++) {
//        if (values2[i].first < 10e3 and values2[i].second < 10e3 and values2[i].first > -10e3 and values2[i].second > -10e3 ) {
//            std::cout << sommets[i]<< "==>" <<(values2[i].first) << "," << (values2[i].second) <<  std::endl;
//        }
//    }
    
    std::vector<int> pointbleu;
    for (int i = 0; i < sommets.size(); i++) {
        if ( sommets[i].blue)
            pointbleu.push_back(i); // on prend l'indice de tout nos points bleus
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(0, pointbleu.size()-1);
    int alea = dis_x(gen);
    
    values.second[sommets.size()-1] = pointbleu[alea];  // on choisi un point bleu aléatoirement et on le stock en tant que point cible
    std::cout <<"" << std::endl;
    std::cout << "La distance la plus courte du point "  << sommets[pointbleu[alea]] << " tiré au hasard vers la sortie la plus proche est de " <<values.first[pointbleu[alea]]-1 << std::endl; // on affiche la distance entre ce point choisi aléatoirement et sa sortie la plus proche
    
    std::vector<int> pcm = pcmMusee(values, pointbleu[alea]);
    
    sortiemusee(pcm, sommets);  // on crée une image représentant ce chemin
    
    std::cout <<"" << std::endl;
    std::cout << "Affichage du chemin le plus court vers la sortie du point tiré au hasard" << std::endl;
    
}


#endif /* musee_h */
