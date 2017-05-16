#include <stdio.h>
#include "page.h"

//Array da memória
Record* memoria;


typedef struct {
    int pin_count;
    int dirt_bit;
    Record* slot;       // Referencia para o slot das quais as informações se referem
} Slot_info;

typedef struct {
    Slot_info* slot_info;       // Biblioteca de dados do Buffer Manager
    Record* memory_ref;         // Referencia ao primeiro endereço da memória
    Slot_info* current_frame;      // Referência ao frame corrente (para política de clock)
} Buffer_manager;


// Lista circular de slot info?
