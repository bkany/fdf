#include "minirt.h"
#include <stdio.h>

int main()
{
	int			fd;
	char 			*line;
	int			error;

// OUVERTURE DU FICHIER set.rt
	fd = open("./set.rt", O_RDONLY);
	
	// A CHAQUE LIGNE, INITIALISATION DES STRUCTURES POUR REMPLISSAGE DU SET 
	while ((error = get_next_line(fd, &line)) > 0)
	{
		// REMPLISSAGE DES ELEMENTS LIGNE PAR LIGNE
		// printf("%d: %s\n", error, line);
	}
	printf("%d: %s", error, line);
	close(fd);
​
    return (0);	

}
