#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void             return_forks(int philosopher_number, int totalPhilo);
void             pickup_forks(int philosopher_number, int totalPhilo);
void*            solvePhilosophy(void* args);
pthread_mutex_t* mutex;

typedef struct{
	        int id;
	        int totalPhilo;
}pArgs;



int main(int argc, char** argv){
	if (argc != 2) {
		printf("Invalid Format. Format to run program is ./solvePhilosophy [n]");
		exit(1);
	}
	
	
	int   totalPhilo;
	int   i;

	totalPhilo = atoi(argv[1]);
	mutex      = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*totalPhilo); //mutex = forks
	
	for (i = 0; i < totalPhilo; ++i)
		pthread_mutex_init(&mutex[i],NULL);
	
	srand(time(NULL));

	pthread_t* threads;
        threads	= (pthread_t*)malloc(totalPhilo*sizeof(pthread_t));                 //threads = philosophers
	for (i = 0; i < totalPhilo; ++i)
	{

	        pArgs argm;
		argm.id = i;
		argm.totalPhilo = totalPhilo;
		pthread_create(&threads[i],NULL,solvePhilosophy,&argm);
	}

	for (i = 0; i < totalPhilo; ++i)
		pthread_join(threads[i],NULL);

	return 0;
}

void* solvePhilosophy(void* args){
	 
	int phil_id = ((pArgs*)args)->id;
	int totalPhilo = ((pArgs*)args)->totalPhilo;
	
	while (1) {
		printf("philosopher %d is now thinking                                             #\n",phil_id);
		sleep(rand()%3); 
		printf("philosopher %d is trying to pickup fork                                    #\n",phil_id);
		pickup_forks(phil_id, totalPhilo);			
		sleep(rand()%3); 
		return_forks(phil_id, totalPhilo);
	}
	return NULL;
}

void pickup_forks(int philosopher_number, int totalPhilo){
	int left = philosopher_number;
	int right= (philosopher_number+1)%totalPhilo;
	pthread_mutex_lock(&mutex[left]); 
	pthread_mutex_lock(&mutex[right]); 
	printf("philosopher %d is now eating################################################\n", philosopher_number);
}

void return_forks(int philosopher_number, int totalPhilo){
	int left = philosopher_number;
	int right= (philosopher_number+1)%totalPhilo;
	printf("philosopher %d is done eating###############################################\n", philosopher_number);
	pthread_mutex_unlock(&mutex[left]);  
	pthread_mutex_unlock(&mutex[right]); 

}


