#include <stdio.h>
#include "page.h"

//Array da memória
Page* memoria;

// Numero de paginas na memoria
#define MEM_SIZE 10


typedef struct {
    int pin_count;
    int dirt_bit;
    Page* slot;       // Referencia para o frame das quais as informações se referem
} Frame_info;

typedef struct {
    Frame_info* frame_info;       // Biblioteca de dados do Buffer Manager
    Page* memory_ref;       	  // Referencia ao primeiro endereço da memória
    Frame_info* current_frame;    // Referência ao frame corrente (para política de clock)
} Buffer_manager;


// Lista circular de frames info?
