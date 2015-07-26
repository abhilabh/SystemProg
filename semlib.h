union semun
{
	int  val;    /* Value for SETVAL */
	struct semid_ds *buf; 
				/* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  
				/* Array for GETALL, SETALL */
	struct seminfo  *__buf;  
			/* Buffer for IPC_INFO (Linux-specific) */
};

int initsem(int flag);

int getsem(int semid);

int releasesem(int semid);



