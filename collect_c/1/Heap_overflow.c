#define BUFSIZE 256
int main(int argc, char **argv) {
char *buf;
buf = (char *)malloc(BUFSIZE);
strcpy(buf, argv[1]);
}



