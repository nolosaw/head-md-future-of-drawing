# Unity first test

## What I want to do 

Un jeu ou une image en noir et blanc s'affiche par défaut sur l'écran, mais quand la personne clique à un endroit, c'est un fragment d'un autre image en couleur qui apparaît comme un halo autour de la zone où la personne a cliqué, en déplacant la souris, la personne peut découvrir l'image en couleur dans son entièreté.

## Qu'est-ce qui se passe ?

- 4 " couches" 
    - 1. Image statique noire de l'île (quelques détails visibles en gris/blanc)
    - 2. Animation en boucle de l'île en couleur
    - 3. éléments sonores d'histoire (commencent on trigger)
    - 4. sons ambiants (tournent en boucle)

- Quand on touche
    - L'image noir disparaît autour de la zone touchée
    - On voit l'animation
    - Si proche d'une histoire, elle commence
    - Son activé, vlume dépend de la proximité avec la zone centrale du son

- Quand on se déplace
    - les actions suivent le mouvement du curseur

- Quand on enlève
    - La couche de noir reprennd le dessus (pas d'un coup mais progressivement)
    - Les sons s'arrêtent

## Comment ?

s