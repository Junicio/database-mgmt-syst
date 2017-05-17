#include <stdio.h>
#include "page.h"

//Array da memória
Page* memoria;

// Numero de paginas na memoria
#define MEM_SIZE 10


typedef struct {
    int pin_count;
    int dirt_bit;
    Page* frame;       // Referencia para o frame das quais as informações se referem
} Frame_info;

typedef struct {
    Frame_info* frame_info;       // Biblioteca de dados do Buffer Manager
    Page* memory_ref;       	  // Referencia ao primeiro endereço da memória
    Frame_info* current_frame;    // Referência ao frame corrente (para política de clock)
} Buffer_manager;



// Aloca os espaços para o buffer manager
int  bf_init(int num_frames);


// Inserção de um novo registro na página
int cr8_record(Record rcd, int heap_id);


// Verifica se a página ja está na memória (Página retornada pelo free_page())
int check_page(int page_id);


// Verifica se há espaço na memoria e chama a política de substituição se necessário
Page* check_memory_space();

// Política de substituição
Page* clock_policies();

// Adiciona página na memoria a partir do seu endereço. Atraves de métodos do dsm
Page add_page_memory(int disk_block);


// Salva página no disco (métodos do dsm) e atualiza dados do frame_info
int save_page(Page* frame);


