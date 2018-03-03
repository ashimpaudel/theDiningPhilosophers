#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct{
	int id;
	int totalPhilo;
}pArgs;

void return_forks(int philosopher_number);

void pickup_forks(int philosopher_number, int totalPhilo);
pthread_cond_t condVar;
pthread_mutex_t mutex;
void *solvePhilosophy(void* args);
int forks[1000];

int main(int argc, char*argv[]){
	if (argc != 2){
		printf("Format to run the program is:$ program [numberOfPhilosopher]");
		exit(0);
	}
	int totalPhilo;
	totalPhilo  = atoi(argv[1]);
	pthread_mutex_init (&mutex, NULL);
	pthread_cond_init (&condVar,NULL);
	
	//creating five philosopher, representing each of them with integer
	int i;
	srand(time(NULL)); 
	//int philosophers[] = {0,1,2,3,4};
	
	for (i=0; i<totalPhilo; i++)
		forks[i]=0;
	


	//create five threads
	pthread_t threads[totalPhilo];
	
	//call the threads
	while(1)
	{

		for(i=0; i<totalPhilo; i++){
			//instantiate the argument to be passed
			pArgs argm;
			argm.id = i;
			argm.totalPhilo = totalPhilo;
			pthread_t th;
			threads[i] = th;
			pthread_create(&threads[i], NULL,solvePhilosophy , &argm);
		}
	}


}

void *solvePhilosophy(void* args){
	//simulating the thinking state
	printf("philosopher %d is now thinkinking\n",((pArgs*)args)->id);
	sleep(rand()%3);
	//as soon as thinking state is done, philosopher is hungry and wish to grab chopsticks, i.e. enter the critical section
        
	printf("philosopher %d is now trying to pick up forks\n",((pArgs*)args)->id);
	pickup_forks(((pArgs*)args)->id,((pArgs*)args)->totalPhilo);	


}

void pickup_forks(int philosopher_number, int totalPhilo){
	int right = philosopher_number;
	int left = (philosopher_number + 1)%totalPhilo;
	int locked;
		
	//Before philosopher can enter critical section, checking is need to be performed
	pthread_mutex_lock(&mutex);
	while(forks[left] || forks[right]) 
		pthread_cond_wait(&mutex, &condVar);
	//Entering C.S
	//Simulate the behavior of eating by pausing thread the process/thread
	printf("philosopher %d is now eating..........................................\n", philosopher_number);
	sleep(rand()%3);
	return_forks(philosopher_number);
			
	
}



void return_forks(int philosopher_number){
	printf("philosopher %d done eating......................................................\n\n",philosopher_number);
	pthread_cond_signal(&condVar);
	pthread_mutex_unlock(&mutex);
	//philosopher returns back to thinking state
	sleep(rand()%3);
}
