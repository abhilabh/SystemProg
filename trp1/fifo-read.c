#define BUFSIZE 100
int main(int argc, char *argv[])
{
  int fd, spcount, n, k;
  char buf[BUFSIZE+1];
  mkfifo("fifo", 0660);
  fd = open("fifo", O_RDONLY);
  n = read(fd, buf, BUFSIZE);
  buf[n] = 0;
  printf("%s\n", buf);
  spcount = 0;
  for (k=0; k < n; ++k) {
    if (buf[k] == ' ') ++spcount;
  }
  printf("%d\n", spcount);
}
