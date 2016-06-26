# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>

int				comparer(const void *a, const void *b) {
	const char 	*aa = *(const char **)a;
	const char	*bb = *(const char **)b;

	return (strcmp(aa, bb));
}

void			print_tab(char **tab, int sz) {
	int			i;

	i = 0;
	while (i < sz) {
		printf("%s\n", tab[i]);
		i++;
	}
}

int				main(void) {
	char		*buf;
	size_t		linecap = 100;
	char		*tab[1000];
	FILE 		*std_in = fopen("/dev/stdin", "r");
	int			i;

	buf = malloc(sizeof(char) * 101);
	i = 0;
	bzero(buf, 100);
	while (getline(&buf, &linecap, std_in) > 1) {
		tab[i] = strndup(buf, strlen(buf) - 1); // - 1 pour amputer les \n
		bzero(buf, 100);
		i++;
	}
	print_tab(tab, i); 	// on affiche avant
	qsort(tab, i, sizeof tab[0], &comparer);
	printf("\n");
	print_tab(tab, i);	// on affiche apres
 	return 0;
}
