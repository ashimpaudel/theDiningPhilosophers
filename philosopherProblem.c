#include <stdio.h>
#include <pthread.h>

typedef struct{
	int id;
}pArgs;

pthread_mutex_t mutex;
pthread_cond_t cond var;
pthread_mutex_init(&mutex,NULL);
pthread_cond_init(&cond_var,NULL);

int main(void){

	//creating five philosopher, representing each of them with integer
	int i;
	srand(time(NULL)); 
	int philosophers[] = {0,1,2,3,4};
	


	//create five threads
	pthread_t threads[5];
	
	//call the threads

	for(i=0; i<5; i++){
		//instantiate the argument to be passed
		pArgs argm;
		arg.id = i;

		void pthread_create(&threads[i], NULL,solvePhilosophy , &argm);
	}
	


}

void *solvePhilosophy(void* args){
	//simulating the thinking state
	sleep(rand()%3);
	//as soon as thinking state is done, philosopher is hungry and wish to grab chopsticks, i.e. enter the critical section
        pickup_forks((typecast)args->id);	


}

void pickup_forks(int philosopher_number){
		//Before philosopher can enter critical section, checking is need to be performed
	pthread_mutex_lock(&mutex)
	while(leftNeighbor is eating or rightNeighbor is eating)
		pthread_cond_wait(&mutex, &cond_var);
	//Entering C.S
	//Simulate the behavior of eating by pausing thread the process/thread
	sleep(rand()%3)
	return_forks(philosopher_number);
}

void return_forks(int philosopher_number){
	pthread_cond_signal(&cond var);
	pthread_mutex_unlock(&mutex);
	//philosopher returns back to thinking state
	sleep(rand()%3);
}
