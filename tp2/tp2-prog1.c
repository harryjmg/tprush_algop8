/* tp2-prog1.c

   Trier quelques chaines de caractères avec la fonction de bibliothèque qsort,
*/
# include <stdlib.h>
# include <stdio.h>

int comparer(const void *, const void *);

enum {
  N = 5,
};

int
main(){
  char * tab[N] = {
    "premier",
    "deuxième",
    "troisième",
    "quatrième",
    "cinquième"
  };
  int nel = N;
  int i;

  qsort(tab, nel, sizeof tab[0], &comparer);

  for(i = 0; i < nel; i++)
    printf("%s\n", tab[i]);

  return 0;
}
