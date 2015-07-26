int  main(int argc, char *argv[ ])
   {
        int k;

        for( k=1; k < argc; k++)
        {
            // printf("argv[%d]   %s\t", k, argv[k]);

             if ( argv[k][0] == '-' )
				 		  printf("argv[%d]   %s\tis options\n", k, argv[k]);

                // printf("is an option\n");
            // else
              //   printf("is not an option\n");
         }
         return 0;
    }

