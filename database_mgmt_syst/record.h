#include <stdio.h>

/*
    Estrutura registro

    Tamanho fixo para cada Heap file
    Incialmente comporta um int e um char, posteriormente será um conjunto de bytes
*/

#define RECORD_SIZE 16

typedef struct {
    int id;
    char name[10];
} Record;
