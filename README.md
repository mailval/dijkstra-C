# dijkstra-C

Implémentation de l'algorithme de Dijkstra, recherche du plus court chemin en C++ en. utilisant deux méthode :
- Une méthode de backtracking.
- Une méthode de Fast Marching pour la fonction coût.

<b> Chaque fichier a pour en-tête une description pour chaque fonction. </b>

Dans un premier temps le programme nous propose de choisir une taille de graphe. 
Le graphe en question est un graphe carré donc si nous choisisons n = 50 le graphe crée sera un grahe 50x50.

Ensuite le programme nous demande la probabilité des sommets qui correspond au pourcentage de sommets souhaité par rapport à un graphe plein.

Ensuite le programme nous demande la probabilité des arêtes qui correspond au pourcentage de arêtes reliants deux sommets.

On nous propose ensuite de choisir si le graphe a crée est carré ou trinagulaire.

Un graphe carré aura uniquement des arêtes avec ses voisins vertical et horizontale mais pas diagonal.
Un graphe trinagulaire aura des arêtes avec tout ses voisins c'est à dire avec tout les voisins adjacents.

Après execution le programme nous indique si il existe un chemin entre le haut et le bas du graphe crée. 
S'il existe un chemin il nous indique la longueur du chemin le plus court.

Voici un exemple de graphe crée pour un graphe carré avec proba_sommets = 1 et proba_arêtes = 0.6  : 

![Capture d’écran 2022-05-12 à 10 47 38](https://user-images.githubusercontent.com/105354135/168030871-e5f3064f-1e57-4bc2-9691-e575c2fd8fb7.png)


Voici un exemple de graphe crée pour un graphe triangulaire avec proba_sommets = 1 et proba_arêtes = 0.35  : 

![Capture d’écran 2022-05-12 à 10 50 22](https://user-images.githubusercontent.com/105354135/168031465-e000bc70-d9dc-4fdb-8fe9-0fee10247751.png)

Voici un exemple de graphe crée pour un graphe carré avec proba_sommets = 0.6 et proba_arêtes = 1  : 

![Capture d’écran 2022-05-12 à 10 56 57](https://user-images.githubusercontent.com/105354135/168032867-6755e63b-01db-47fb-8fd4-08a5583c00f1.png)

Voici un exemple de graphe crée pour un graphe triangulaire avec proba_sommets = 0.5 et proba_arêtes = 1  : 

![Capture d’écran 2022-05-12 à 10 58 46](https://user-images.githubusercontent.com/105354135/168033195-01f93417-8f3c-4120-8e1f-d3fc885225a5.png)

## Plan d'un musée 

Dans un second temps nous avons implémenter un algorithme qui prend en entrée un plan d'un musée et propose le chemin le plus court vers la sortie la plus proche pour une position aléatoire sur ce plan.

En utilisant la méthode de Fast Marching on calcul le chemin le plus court entre notre position et la sortie la plus proche.

Voici le plan du musée utilisé : 

![musee](https://user-images.githubusercontent.com/105354135/168037251-b13c8f6e-de2e-439c-8c57-c6617a40357e.png)

Et voici un exemple de sortie : 

![sortie](https://user-images.githubusercontent.com/105354135/168047199-f3680a65-2980-4dcd-80eb-30e27c27c8cb.jpg)

