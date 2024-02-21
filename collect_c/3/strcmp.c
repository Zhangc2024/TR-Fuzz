int strcmp(char *s, char *t);

int main(void) {
	return 0;
}

int strcmp(char *s, char *t) {
	for (; *s == *t; s++, t++)
		if (*s == '\0') return 0;
	return  *s - *t;
}

