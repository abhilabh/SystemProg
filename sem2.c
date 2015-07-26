#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/types.h>
#include <linux/ipc.h>
#include <linux/sem.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  key_t key;
  int semid;
  union semun arg;
  struct sembuf lock_res = {0, -1, 0};
  struct sembuf rel_res = {0, 1, 0};
  struct sembuf push[2] = {1, -1, IPC_NOWAIT, 2, 1, IPC_NOWAIT};
  struct sembuf pop[2] = {1, 1, IPC_NOWAIT, 2, -1, IPC_NOWAIT};

  int i;

  if(argc < 2){
    exit(0);
  }

  key = ftok("/etc/fstab", getpid());

  semid = semget(key, 3, 0666 | IPC_CREAT);

  arg.val = 1;
  semctl(semid, 0, SETVAL, arg);

  arg.val = atol(argv[1]);
  semctl(semid, 1, SETVAL, arg);

  arg.val = 0;
  semctl(semid, 2, SETVAL, arg);

  for (i = 0; i < 5; i++){
    pid = fork();
    if (!pid){
      for (i = 0; i < 20; i++){
	sleep(rand()%6);
	if (semop(semid, &lock_res, 1) == -1){
	  perror("semop:lock_res");
	}
	if (semop(semid, &push, 2) != -1){
	  printf("---> Process:%d\n", getpid());
	}
	else{
	  printf("---> Process:%d  BUFFER FULL\n", getpid());
	}
	semop(semid, &rel_res, 1);
      }
      exit(0);
    }
  }

  for (i = 0;i < 100; i++){
    sleep(rand()%3);
    if (semop(semid, &lock_res, 1) == -1){
      perror("semop:lock_res");
    }
    if (semop(semid, &pop, 2) != -1){
      printf("<--- Process:%d\n", getpid());
    }
    else printf("<--- Process:%d  BUFFER EMPTY\n", getpid());
    semop(semid, &rel_res, 1);
  }

  semctl(semid, 0, IPC_RMID);

  return 0;
}
