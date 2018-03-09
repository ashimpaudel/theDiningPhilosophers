# theDiningPhilosophers
This program is the solution to the dining-philosopher's problem using p_threads and it's functions.

# Instructions to compile the program
1. clone this repo using git clone 
2. cd into the project directory
3. type make from command line
4. to execute the program run ./solvePhilosophy [number of philosopher]
5. [optional] to clean invoke make clean

# Snapshot of a running progarm
![alt text](https://image.ibb.co/g6yqDS/Screenshot_from_2018_03_05_23_42_10.png)

# Note to instructor
The program on master branch does not make use of pthread_cond_t variable. There is a separate program that uses condition variable on the branch called singleMutex. The version on singleMutex branch makes use of all the APIs and variable types stated on the text book but does not solve the bounded waiting problem. To run singleMutex branch the instructions are same.
