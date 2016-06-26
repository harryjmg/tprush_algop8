/*
**	q3 : Pourquoi memset ?
*/

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct 		s_str {
	char			*str;
	struct s_str	*next;
}					t_str;

void			lst_add_end(t_str **list, char *str) {
	t_str		*new_elem;
	t_str		*tmp;

	new_elem = (t_str *)malloc(sizeof(t_str));
	new_elem->str = strndup(str, strlen(str) - 1);
	new_elem->next = NULL;
	tmp = *list;
	if (!(*list))
	{
		*list = new_elem;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_elem;
}

void			print_list(t_str *list) {
	while (list) {
		printf("%s\n", list->str);
		list = list->next;
	}
}

int				lst_len(t_str *list) {
	int			i;

	i = 0;
	while (list)
		i++;
	return (i);
}

int				comparer_isort(const void *a, const void *b) {
	
	return (strcmp(a, b));
}

void			print_tab(char **tab, int sz) {
	int			i;

	i = 0;
	while (i < sz) {
		printf("%s\n", tab[i]);
		i++;
	}
}

void			isort(void *base, size_t nel, size_t width, int (*comparer)(const void *, const void *)) {
	int			i, j;
	char		*x;
	char		**tab;

	tab = base;
	i = 1;
	while (i < nel) {
		x = tab[i];
		j = i;
		while (j > 0 && (*comparer)(tab[j - 1], x) > 0) {
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = x;
		i++;
	}
}

int				main(void) {
	char		*buf;
	size_t		linecap = 200000;
	char		**tab;
	t_str		*str_lst;
	FILE 		*std_in = fopen("/dev/stdin", "r");
	int			i, j;

	//	1. ON MET DANS UNE LISTE
	buf = malloc(sizeof(char) * 200001);
	i = 0;
	str_lst = NULL;
	while (getline(&buf, &linecap, std_in) > 1) {
		lst_add_end(&str_lst, buf);  // - 1 pour amputer les \n
		bzero(buf, strlen(buf));
		i++;
	}
	if (buf)
		free(buf); // on tire la chasse derriere nous

	//	2. TRANSFERT DES POINTEURS DANS TABLEAU POUR TRI
	tab = malloc(sizeof(char *) * i);
	j = 0;
	while (j < i)
	{
		tab[j] = str_lst->str;
		str_lst = str_lst->next;
		j++;
	}

	//	3. ON TRIE LE TABLEAU
	print_tab(tab, i); 	// on affiche avant
	isort(tab, i, sizeof tab[0], &comparer_isort);
	printf("\n");
	print_tab(tab, i);	// on affiche apres
 	return (0);
}
