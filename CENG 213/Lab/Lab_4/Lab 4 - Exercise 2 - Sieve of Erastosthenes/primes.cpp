#include "Queue.h"
#include <iostream>

/*
Write a program that finds prime numbers using the Sieve of Erastosthenes, an algorithm devised by a Greek mathematician
of the same name who lived in the third century BC. The algorithm finds all prime numbers up to some maximum value n, 
as described by the following pseudocode:

Create a queue of numbers to process.
Fill the queue with the integers 2 through n inclusive
Create an empty result queue to store primes.
Repeat the following steps:
Obtain the next prime p by removing the first value from the queue of numbers.
     Put p into the result queue of primes.
Loop through the queue of numbers, eliminating all numbers that are divisible by p.
while (p is less than the square root of n).

All remaining values in the numbers queue are prime, so transfer them to the result primes queue.

EXAMPLE:
Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29 
*/

Queue <int> SieveOfEratosthenes(int n) {
    // TODO: 
    Queue <int> numbers;
    Queue <int> primes;
    int count=0;
    for (int i = 2; i <= n; i++ ){
        numbers.enqueue(i);
        count++;
    }
    for(int j=0;j<count;j++){
        int A = numbers.dequeue();
        int flag=0;
        for(int c = 2; c <= A/2; c++){  
            if(A % c == 0){ 
                flag=1;  
                break;  
            }  
        }
        if(flag ==0){
            primes.enqueue(A);
        }
    }    
             
    
	
    return primes;
}
