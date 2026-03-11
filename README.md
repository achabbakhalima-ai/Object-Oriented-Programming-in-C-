## C++_Ateliers – Programmation Orientée Objet (POO) en C++

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat) 
![POO](https://img.shields.io/badge/Concepts-POO-green?style=flat) 
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=flat)

Ce repository contient mes **ateliers de Programmation Orientée Objet (POO) en C++**, réalisés dans le cadre de ma formation en **ingénierie du développement des applications informatiques**. Chaque atelier propose des exercices pratiques avec des objectifs précis pour renforcer les compétences en C++ et POO.

---

## 📁 Structure du repository
C++_Ateliers
│
├── Atelier1_POO # Types, expressions, tableaux dynamiques et pointeurs
├── Atelier2_POO # Fonctions, références, récursion et classes simples
├── Atelier3_POO # Gestion dynamique, piles, listes chaînées et classes avancées
├── Atelier4_POO # Héritage, héritage multiple et contrôle d’accès
└── Atelier5_POO # Templates, exceptions et opérateurs surchargés



---

## **Atelier 1 : Manipulation des types et tableaux dynamiques**

| Exercice | Objectif |
|----------|----------|
| 1 | Comprendre le type et la valeur des expressions avec `char`, `int` et `short` |
| 2 | Maîtriser les conversions implicites et explicites entre types numériques (`int`, `long`, `float`, `double`) |
| 3 | Manipuler les opérateurs logiques et ternaires pour évaluer des expressions complexes |
| 4 | Comprendre le comportement des opérateurs d’incrémentation (`++i`, `i++`) et des affectations composées (`+=`, `*=`) |
| 5 | Créer et manipuler dynamiquement un tableau d’entiers, rechercher le maximum, modifier via référence et inverser le tableau |

---

## **Atelier 2 : Fonctions, références, pointeurs et POO avancée**

| Exercice | Objectif |
|----------|----------|
| 1 | Créer une fonction qui compte le nombre de fois qu’elle est appelée |
| 2 | Déterminer si un nombre est multiple de 2, 3 ou 6 |
| 3 | Rechercher le minimum et le maximum dans un tableau avec indices et pointeurs |
| 4 | Utiliser des tableaux dynamiques pour créer un second tableau avec les carrés des éléments |
| 5 | Manipuler des variables via références et pointeurs dans des fonctions |
| 6 | Écrire des fonctions pour incrémenter et permuter des variables |
| 7 | Générer toutes les permutations possibles d’une chaîne de caractères (récursivité) |
| 8 | Créer et manipuler des classes `Voiture`, `vecteur3d`, `Complexe` |

---

## **Atelier 3 : Gestion dynamique et classes avancées**

| Exercice | Objectif |
|----------|----------|
| 1 | Implémenter une classe `Pile` avec méthodes `push` et `pop` |
| 2 | Simuler la gestion dynamique d’un fichier en mémoire et tester l’allocation / libération |
| 3 | Créer une liste simplement chaînée et manipuler ses éléments (ajout, suppression, affichage) |
| 4 | Créer les classes `Client` et `Compte` pour gérer des comptes bancaires, gérer le compteur global et appliquer des intérêts |

---

## **Atelier 4 : Héritage et contrôle d’accès**

| Exercice | Objectif |
|----------|----------|
| 1 | Créer des classes `Ressource`, `Livre`, `Magazine`, `Video` et `Telechargeable` avec héritage multiple |
| 2 | Surcharge d’opérateurs (`==`) et résolution de conflits de méthodes héritées |
| 3 | Créer une classe `Mediatheque` avec méthodes d’ajout, affichage et recherche de ressources |
| 4 | Créer les classes `Client`, `CompteBancaire`, `AgentBancaire` et `Banque`, sécuriser les accès aux données sensibles et simuler les opérations confidentielles |

---

## **Atelier 5 : Templates, exceptions et opérateurs**

| Exercice | Objectif |
|----------|----------|
| 1 | Créer une fonction template pour rechercher un élément dans différents conteneurs (`set`, `vector`, `list`) |
| 2 | Protéger un programme contre les erreurs de division via les exceptions |
| 3 | Créer une classe `vectok` pour permettre la copie et l’affectation sans erreur mémoire |
| 4 | Comprendre l’ordre d’appel des constructeurs en héritage multiple |
| 5 | Créer une fonction template pour calculer le carré d’une valeur générique |
| 6 | Créer une classe template `Point` et afficher correctement ses coordonnées |
| 7 | Manipuler des exceptions personnalisées et leur propagation entre fonctions |
| 8 | Implémenter une classe `Stack` avec opérateurs surchargés (`<<`, `>>`, `++`, `--`) et gérer les erreurs de pile |

---

## 💻 Compilation et exécution sous Windows

1. Cloner le repository
git clone https://github.com/<ton-utilisateur>/C++_Ateliers.git
2. Aller dans le dossier de l'atelier souhaité
cd C++_Ateliers\Atelier1_POO
3. Compiler le fichier C++ (remplacer nom_du_fichier.cpp par ton fichier)
g++ nom_du_fichier.cpp -o nom_programme.exe
4. Exécuter le programme compilé
nom_programme.exe
