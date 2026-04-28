# Push Swap - Projet 42

## Description

Push Swap est un projet algorithmique dont l’objectif est de trier une pile d’entiers en utilisant un ensemble limité d’instructions.
Le programme doit générer la plus petite séquence d’opérations possible pour trier les données, en respectant les contraintes imposées.

Le projet met l’accent sur l’optimisation, la complexité algorithmique et la manipulation de structures de données.

---

## Compilation

Pour compiler le projet :

```bash
make
```

Cela génère l’exécutable `push_swap`.

---

## Lancement du programme

Après compilation, lancez le programme avec une liste d’entiers en argument :

```bash
./push_swap 2 1 3 6 5 8
```

Le programme affiche une suite d’instructions permettant de trier la pile.

---

## Utilisation

Le programme prend en entrée une liste d’entiers et retourne les opérations nécessaires pour les trier.

Exemple :

```bash
./push_swap 3 2 1
```

Sortie possible :

```
pb
pb
sa
pa
pa
```

Les instructions autorisées incluent notamment :

* `sa`, `sb`, `ss` : swap des éléments en haut de la pile
* `pa`, `pb` : push entre les piles
* `ra`, `rb`, `rr` : rotation vers le haut
* `rra`, `rrb`, `rrr` : rotation vers le bas

---

## Vérification

Pour vérifier que la sortie est correcte, vous pouvez utiliser un checker :

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Le résultat attendu est :

```
OK
```

---

## Tests

Vous pouvez générer des tests aléatoires :

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Cela permet de mesurer le nombre d’opérations générées.

---

## Notes

* Les performances sont évaluées en fonction du nombre d’opérations
* Une gestion rigoureuse des erreurs est attendue (doublons, invalides, overflow)
* Le comportement dépend de l’algorithme implémenté

---
