#include <time.h>
     #include <stdio.h>
     
     #define size 256
     
     int
     main (void)
     {
       char buffer[size];
       time_t curtime;
       struct tm *loctime;
     
       /* get the current time. */
      // curtime = time (NULL);
     
       /* convert it to local time representation. */
       loctime = localtime(&curtime);
     
       /* print out the date and time in the standard format. */
       fputs (asctime (loctime), stdout);
     
       /* print it out in a nice format. */
       strftime (buffer, size, "today is %a, %b %d.\n", loctime);
       fputs (buffer, stdout);
       strftime (buffer, size, "the time is %i:%m %p.\n", loctime);
       fputs (buffer, stdout);
     
       return 0;
     }
