// compiler comme ça : gcc q1.c tp2-prog1.c

int comparer(const void *a, const void *b) {
	int const	*aa = a;
	int const	*bb = b;

	return (*aa - *bb);
}
