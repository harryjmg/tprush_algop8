/* mkstring.c

  Imprimer des chaines de caractères au hasard (pour tester le programme
  de tri).
*/
# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <unistd.h>

int
main(int ac, char * av[]){
  int nstring, ln;
  int i, j;

  if (ac != 3){
    fprintf(stderr, "usage: %s nombre-de-chaine longueur\n", av[0]);
    return 1;
  }
  nstring = strtol(av[1], NULL, 0);
  ln = strtol(av[2], NULL, 0);

  srand(getpid());

  for(i = 0; i < nstring; i++){
    for(j = 0; j < ln; j++)
      printf("%c", rand() % 26 + 'a');
    printf("\n");
  }
  return 0;
}

    

  
