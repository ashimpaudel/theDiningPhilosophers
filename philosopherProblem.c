#include <stdio.h>
#include <pthread.h>

typedef struct{
	int id;
}pArgs;
int main(void){

	//creating five philosopher, representing each of them with integer
	int i;
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

}
	

