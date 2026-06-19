# 🎮 Projet : Jeu du SUTOM

> **Un jeu de devinette de mots en C.**

> Le joueur dispose de 6 essais pour deviner un mot secret.
> La première lettre est révélée au départ.
> Les sorties sont colorees 
> si un mot est trop court ou long, alors on renvoi un message d'erreur

---

## 📋 Fonctionnalités

* [x] **Affichage dynamique** : Si le mot contient exactement 4 lettres, on l'affiche sous forme de `[ ][ ][ ][ ]`.
* [x] **Aide** : La première lettre est révélée automatiquement.
* [x] **Validation** : Vérification de la longueur du mot saisi.
* [x] **Système de jeu** : Limite de 6 essais avec messages "Gagné" ou "Perdu".
* [x] **Interface** : Affichage coloré via macros.
* [x] **Lexique** : Intégration du dictionnaire Morphalou comme base de données lexicale.
* [x] **Validation2** : Vérification de de l'existance du mot.

---
## Participation
les fonctions ont été rédigés par Amna et Alexandra, toutes les deux ont contribué à la rédaction du code, des fichiers tests et du README
---

## 🛠️ Installation & Compilation

Pour compiler le projet, utilise un compilateur C :

```bash
gcc sutom.c -o jeu_sutom
./jeu_sutom
```
---

## 🧪 Protocole de Tests

Pour valider le comportement du moteur de jeu, nous utilisons des fichiers de redirection d'entrée. Chaque fichier simule les saisies clavier d'un utilisateur.

### Détail des scénarios
* **Test 1 (`test1.txt`)** : 
    * *But* : Vérifier que le jeu s'arrête immédiatement après une victoire.
    * *Séquence* : Saisie 1 (faux), Saisie 2 (faux), Saisie 3 (**correcte**).
* **Test 2 (`test2.txt`)** : 
    * *But* : Vérifier que le message "Perdu" s'affiche et que le programme se termine après le 6ème échec.
* **Test 3 (`test3.txt`)** : 
    * *But* : vérification de la gestion des lettres répétées .

### Lancer tous les tests:

```bash
./sutom < test/test1.txt
./sutom < test/test2.txt
./sutom < test/test3.txt
```
