#include "recursive.c"
#define DIM_ORDERED 10    // dimension of ordered  integer array
#define DIM_NOT_ORDERED 5 // dimension of the not ordered integer array

int main()
{

    char *s = "ajajbaj";                                      // test string
    char *d = (char *)malloc((strlen(s) + 1) * sizeof(char)); // dynamic allocation of a string used for copy and reverse
    int vet[DIM_ORDERED] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // already ordered vector test: change the number inside to test various situation
    int x[] = {48, 24, 96, 12, 192};                          // vector to be ordered

    int evenS = 0; // sum of even numbers
    int oddsM = 1; // sum of the odds numbers

    long long int nFacorial = 5;   // used to calculate the factorial
    long long int nFibonacci = 20; // used to calculate the Fibonacci number

    int searchIndex = 0; // the search index

    // menu
    printf("a) Recursive copy\nb) Recursive reverse string\nc) First capital lettere recursive\n");
    printf("d) Palindrome string recursive\ne) Minimum recursive\n");
    printf("f) Binary search recursive\ng) Linear search recursive\nh) Bubble sort recursive\n");
    printf("i) Given an array: sum even numbers and multiply the odds ones\n");
    printf("l) Factorial: recursive vs iterative version\n");
    printf("m) Fibonacci: recursive vs iterative version\n");

    printf("\n- Inser your choice: ");
    char choice = getc(stdin);
    puts("");

    switch (choice)
    {
    case 'a':
        copyStringRecursive(s, d, strlen(s));
        printf("Recursive copy: %s", d);
        break;
    case 'b':
        invertStringRecursive(s, d, 0, strlen(s) - 1);
        printf("\nRecursive reverse string: %s", d);
        break;
    case 'c':
        printf("Index of the first capital letter: %d", firstCapitalLetterRecursive(s, strlen(s) - 1));
        break;
    case 'd':
        if (isPalindromeRecursive(s, strlen(s) - 1))
            printf("The string is palindrome");
        else
            printf("The string is not palindrome");
        break;
    case 'e':
        printf("Minimum: %d", minRecursive(vet, 10, *vet));
        break;
    case 'f':
        searchIndex = binarySearchRecursive(vet, 5, 0, DIM_ORDERED - 1);
        if (searchIndex != -1)
            printf("Position of 5: %d\n", searchIndex);
        else
            printf("The element has not being found\n");
        break;
    case 'g':
        searchIndex = linearSearchRecursive(vet, 24, DIM_ORDERED);
        if (searchIndex != -1)
            printf("Position of 5: %d", searchIndex);
        else
            printf("The element has not being found\n");
        break;
    case 'h':
        bubbleSortRecursive(x, DIM_NOT_ORDERED);
        printArray(x, DIM_NOT_ORDERED);
        break;
    case 'i':
        sumEvenMultiplyOdds(vet, &evenS, &oddsM, DIM_ORDERED);
        printf("The sum of even's numbers inside the vector is: %d\n", evenS);
        printf("The product of odds' numbers inside the vector is: %d\n", oddsM);
        break;
    case 'l':
        printf("Factorial recursive = Factorial iterative <=> %lli = %lli", factorialRecursive(nFacorial), factorialIterative(nFacorial));
        break;
    case 'm':
        printf("Fibonacci recursive = Fibonacci iterative <=> %lli = %lli", fibonacciRecursive(nFibonacci), fibonacciIterative(nFibonacci));
        break;
    default:
        printf("Wrong choice!");
        break;
    }

    return 0;
}