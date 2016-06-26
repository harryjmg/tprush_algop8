#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void		afficher_choisies(int *tab, int *choisies, int n) {
	int		i;

	printf("Patates retenues : ");
	i = 0;
	while (i < n) {
		if (choisies[i] == 1)
			printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

void		afficher_tab(int *tab, int n) {
	int		i;

	i = 0;
	while (i < (n - 1))
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("%d\n", tab[i]);
}

void		init_tab(int *tab, int n) {
	int		i;

	i = 0;
	srand(time(NULL));
	while (i < n)
	{
		tab[i] = 150 + rand() % 101;
		i++;
	}
}

void		init_choisies(int *tab, int n) {
	int		i;

	i = 0;
	while (i < n) {
		tab[i] = 0;
		i++;
	}
}

int			recherche(int *tab, int *choisies, int nb_patates, int but, int i_patate, int poids) {
	if (poids == but)
		return (1);
	if (poids > but)
		return (0);
	if (i_patate > nb_patates)
		return (0);
	choisies[i_patate] = 1;
	if (recherche(tab, choisies, nb_patates, but, i_patate + 1, poids + tab[i_patate]))
		return (1);
	choisies[i_patate] = 0;
	if (recherche(tab, choisies, nb_patates, but, i_patate + 1, poids))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int		nb_patates, but, i, poids;
	int		*tab, *choisies;

	if (ac != 2) {
		printf("usage: %s [nb_patates]\n", av[0]);
		return (1);
	}
	nb_patates = atoi(av[1]);
	but = (nb_patates / 2) * 200;
	tab = malloc(sizeof(int) * nb_patates);
	choisies = malloc(sizeof(int) * nb_patates);
	init_tab(tab, nb_patates);
	init_choisies(choisies, nb_patates);
	printf("Patates de base : ");
	afficher_tab(tab, nb_patates);
	printf("Poids recherché : %d\n", but);
	i = 0;
	poids = 0;
	if (recherche(tab, choisies, nb_patates, but, 0, 0))
		afficher_choisies(tab, choisies, nb_patates);
	else
		printf("Pas de solutions\n");	
	return (0);
}