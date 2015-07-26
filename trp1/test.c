     char *p = "hello";
     char buf[ ] = "hello";
     printf("%0X\n", p);

     printf("%0X    %s\n", buf, buf);
     printf("%0X\n", "hello");
	  printf("%0X\n", "Hello");

     *p = 'H';
     printf("%0X\n", p);
     printf("%0X %s\n", buf, buf);
     printf("%0X\n", "hello");
