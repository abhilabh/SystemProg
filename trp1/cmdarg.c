
int main(int argc, char *argv[])
{
	int i;
	printf("in main\n");

	printf("argc = %d\n", argc);
	for(i=0;i<=argc;i++)
	{
		printf("argv[%d] = %s\n",i,argv[i]);
	}
	return 0;
}
