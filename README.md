#get_next_line
  
Projet Ecole 42 (Paris)
  
##Synopsis
  
int&emsp;get_next_line(int const fd, char **line)  

Le but de la fonction get_next_line est de lire depuis un ou plusieurs descripteurs de fichiers et de renvoyer une ligne. Le charactere retour a la ligne delimite la ligne a renvoyer, il est inclus dans la chaine de charactere renvoyee par la fonction, a moins que la fin du fichier soit atteinte. Le resultat est enregistre via le pointeur sur chaine de charactere passe en parametre.

Si il y a une erreur lors de la lecture, la fonction renvoie -1, 0 lorsque la fin du fichier est ateinte, 1 si tout s'est bien passé.
