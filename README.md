# get_next_line
  
Projet Ecole 42 (Paris)
  
## Synopsis

int&emsp;get_next_line(int const fd, char **line)  

Le but de la fonction get_next_line est de lire depuis un descripteur de fichier et de renvoyer une ligne. Le caractère retour à la ligne delimite la ligne a renvoyer, il est inclus dans la chaine de caractères renvoyée par la fonction, à moins que la fin du fichier soit atteinte. Le resultat est enregistré via le pointeur sur chaine de caractères passé en paramètre.

Si il y a une erreur lors de la lecture, la fonction renvoie -1, 0 lorsque la fin du fichier est ateinte, 1 si tout s'est bien passé.
