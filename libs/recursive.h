#pragma once

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/**
 * Function's prototypes for string manipulations
*/
void copyStringRecursive(char *source, char *dest, int dim);
void invertStringRecursive(char *source, char *dest, int l, int h);
int firstCapitalLetterRecursive(char *source, int dim);
int isPalindromeRecursive(char *source, int dim);

/**
 * Function prototypes to perform operations on arrays
*/
int minRecursive(int * v, int dim, int currentMin);
int binarySearchRecursive(int *v, int key, int low, int high);
int linearSearchRecursive(int *v, int key, int size);
void bubbleSortRecursive(int *v, int size);
void sumEvenMultiplyOdds(int *v, int *sum, int *prod, int dim);
void printArray(int *v, int size);

/**
 * Recursive vs Iterative classic algorithms
*/
long long int factorialRecursive(long long int n);
long long int factorialIterative(long long int n);
long long int fibonacciRecursive(long long int n);
long long int fibonacciIterative(long long int n);

