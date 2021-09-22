#include "libs/recursive.h"

/**
 * This function is used to copy a string into another
 * 
 * @param[in] source: the source string, whose content will be copied into another string
 * @param[in] dest: the destination string, that will contain a copy of the content of the source string 
 * @param[in] dim: the size of the string 
*/
void copyStringRecursive(char *source, char *dest, int dim)
{
    if (dim < 0)
    {
        return;
    }
    else
    {
        dest[dim] = source[dim];
        copyStringRecursive(source, dest, --dim);
    }
}

/**
 * This function is used to invert a string
 * 
 * @param[in] source: the source string, whose content will be the string to invert
 * @param[in] dest: the destination string, that will contain the inverted source string
 * @param[in] dim: the size of the string 
*/
void invertStringRecursive(char *source, char *dest, int l, int h)
{
    if (h < 0)
    {
        dest[strlen(source)] = '\0';
        return;
    }
    else
    {
        dest[l] = source[h];
        invertStringRecursive(source, dest, ++l, --h);
    }
}

/**
 * This function is used to find the first capital letter in a string
 * 
 * @param[in] source: the string where to search the first capital letter index
 * @param[in] dim: the size of the string 
 * @return an integer number: the index of the first capital letter. If this number is equals to dim, the string is lower-case
*/
int firstCapitalLetterRecursive(char *source, int dim)
{
    static int index = 0;

    if (index < (dim))
    {
        if (isupper(source[index]))
        {
            return index;
        }
        else
        {
            index++;
            return firstCapitalLetterRecursive(source, dim);
        }
    }
    else
    {
        return dim;
    }
}

/**
 * This function is used to reverse a string
 * 
 * @param[in] source: the string used to verify if it's palindrome or not
 * @param[in] dim: the size of the string 
 * @return a value greater than 0 if the string is palindrome, 0 if it is not palindrome
*/
int isPalindromeRecursive(char *source, int dim)
{
    static int i = 0;

    if (i == (int)strlen(source) / 2)
    {
        return 1; // la stringa in input è palindroma
    }
    else if (source[i] == source[dim])
    {
        i++;
        return isPalindromeRecursive(source, --dim);
    }
    else
    {
        return 0;
    }
}

/**
 * This function is used to find the minimum inside an integer array
 * 
 * @param[in] v: input array
 * @param[in] dim: the size of the array 
 * @param[in] currentMin: indicates the current minimum number in each recursion step
 * @return the minimum value
*/
int minRecursive(int *v, int dim, int currentMin)
{
    static int i = 1;

    if (i == dim)
    {
        return currentMin;
    }
    else if (v[i] < currentMin)
    {
        currentMin = v[i];
        i++;
        return minRecursive(v, dim, currentMin);
    }
    else
    {
        i++;
        return minRecursive(v, dim, currentMin);
    }
}

/**
 * Recursive version of binary search: given an array, its lower and higher bounds and
 * the value to search, the algorithm search the element by 
 * repeatedly dividing the search interval in half.
 * 
 * @param[in] v: an already ordered array
 * @param[in] key: the value to search
 * @param[in] low: the lower bound of the array
 * @param[in] high: the higher bound of the array
 * @return the index of the key or -1 if the element has not being found
*/
int binarySearchRecursive(int *v, int key, int low, int high)
{
    if (low <= high)
    {

        int middle = (low + high) / 2;

        if (v[middle] == key)
            return middle;

        if (key < v[middle])
            return binarySearchRecursive(v, key, low, middle - 1);

        if (key > v[middle])
            return binarySearchRecursive(v, key, middle + 1, high);
    }
    else
    {
        return -1;
    }
}

/**
 * Recursive version of a linear search
 * @param[in] v: an array
 * @param[in] key: the value to searc
 * @param[in] size: the size of the array
 * 
 * @return the index of the value searched or -1
*/
int linearSearchRecursive(int *v, int key, int size)
{
    size--;

    if (v[size] == key || size == -1)
        return size;
    else
        return linearSearchRecursive(v, key, size);
}

/**
 * Recursive version of bubblesort
 * 
 * @param [in] v: the array to order
 * @param [in] size: the size of the array
*/
void bubbleSortRecursive(int *v, int size)
{
    size--;

    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (v[i] > v[i + 1]) 
        {
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }

    return bubbleSortRecursive(v, size);
}

/**
 * Function to prin an array
 * 
 * @param [in] v: the array to order
 * @param [in] size: the size of the array
*/
void printArray(int *v, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", v[i]);
}

/**
 * Given an array this function is used to sum even numbers and multiply the odds one
 * 
 * @param[in] v: input array
 * @param[in] sum: sum of even numbers
 * @param[in] prod: multiplication of odds numbers
 * @param[in] dim: the size of the array 
*/
void sumEvenMultiplyOdds(int *v, int *sum, int *prod, int dim)
{
    static int i = 0;
    if (dim <= 0)
    {
        return; // caso base
    }
    else
    {
        if ((v[i] % 2) == 0)
        {
            *sum += v[i];
        }
        else
        {
            *prod *= v[i];
        }

        i++;
        sumEvenMultiplyOdds(v, sum, prod, --dim);
    }
}

/**
 * Function to calculate the factorial of a number (RECURSIVE VERSION)
 * 
 * @param[in] n: the number whose factorial will be calculated by this function
 * @return the factorial of n
*/
long long int factorialRecursive(long long int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorialRecursive(n - 1));
}

/**
 * Function to calculate the factorial of a number (ITERATIVE VERSION)
 * 
 * @param[in] n: the number whose factorial will be calculated by this function
 * @return the factorial of n
*/
long long int factorialIterative(long long int n)
{
    long long int fac = 1;
    int i = n;

    while (i >= 1)
    {
        fac = fac * i;
        i--;
    }

    return fac;
}

/**
 * Function to calculate the fibonacci sequence (RECURSIVE VERSION)
 * 
 * @param[in] n: the number whose fibonacci sequence will be calculated by this function
 * @return the fibonacci sequence of n
*/
long long int fibonacciRecursive(long long int n)
{
    if (n >= 0)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        else
        {
            return fibonacciIterative(n - 1) + fibonacciRecursive(n - 2);
        }
    }
    else
    {
        return -1;
    }
}

/**
 * Function to calculate the fibonacci sequence (ITERATIVE VERSION)
 * 
 * @param[in] n: the number whose fibonacci sequence will be calculated by this function
 * @return the fibonacci sequence of n
*/
long long int fibonacciIterative(long long int n)
{
    int f1 = 0, f2 = 1, f;
    do
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        n--;
    } while (n > 1);
    return f;
}
