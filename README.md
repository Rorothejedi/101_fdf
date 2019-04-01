# fdf

Projet de programmation graphique, mettant en avant le placement de points dans l’espace, comment les relier avec des segments et surtout comment observer la scène depuis un certain point de vue avec la conception d'un maillage en wireframe.

## Sujet

[PDF fdf](https://github.com/Rorothejedi/101_fdf/blob/master/fdf.fr.pdf)

## Fonctionnalités

- 3 types de projections ([isométrique](https://github.com/Rorothejedi/101_fdf/blob/master/README.md#projection-isom%C3%A9trique), [cavalière](https://github.com/Rorothejedi/101_fdf/blob/master/README.md#projection-cavali%C3%A8re) et [oblique](https://github.com/Rorothejedi/101_fdf/blob/master/README.md#projection-oblique)).
- Déplacement avec les flèches du clavier.
- Gestion de la sensibilité des déplacement.
- Gestion des couleurs (7 différentes) en fonction de l'axe Z.
- Les traits en dehors de l'écran ne sont pas calculés.
- Interface affichant les commandes et certaines informations en temps réel (projection, sensibilité, couleurs).

## Utilisation

### Compilation du programme :

```
$> make
```

### Lancement de la fenetre graphique :

```
$> ./fdf [target_file]
```

### Exemple de contenu du fichier cible :

```
$> cat maps/42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
Chaque nombre correspond à un point dans l'espace :
 - La position horizontale correspond à son abscisse.
 - La position verticale correspond à son ordonneé.
 - La valeur correspond à son altitude.

> Realisé et testé sur MacOs Sierra V.10.12.6

## Images du projet

### Projection isométrique

![Image 0 fdf](https://github.com/Rorothejedi/101_fdf/blob/master/img_project/img_project_0.png)
Source : [Wikipédia - perspective isométrique](https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique)

------------------------------------

### Projection cavalière

![Image 1 fdf](https://github.com/Rorothejedi/101_fdf/blob/master/img_project/img_project_1.png)
Source : [Wikipédia - perspective cavalière](https://fr.wikipedia.org/wiki/Perspective_cavali%C3%A8re)

------------------------------------

### Projection oblique

![Image 2 fdf](https://github.com/Rorothejedi/101_fdf/blob/master/img_project/img_project_2.png)
Source : [Wikipédia - projection oblique](https://en.wikipedia.org/wiki/Oblique_projection#Cabinet_projection)
