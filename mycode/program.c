#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID(x)

ID("$Id: main.c,v 4.25 1995/05/15 12:20:00 espie Exp espie $")

int main() {
    // int x = 1;
    // if(*(char*)&x == 1)
    //     printf("little-endian\n");
    // else
    //     printf("big-endian\n");
    // printf("%p\n", &x);
    // printf("%p\n", (char*)&x);
    // printf("%d\n", *(char*)&x);
    int n = 50;
    // n = n++;
    int tmp = n++;
    printf("tmp=%d\n", tmp);
    n = tmp;
    printf("n=%d\n", n);
}