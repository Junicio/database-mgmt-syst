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
    int disk_block;
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
int check_page(int heap_id, int page_id);


// Verifica se há espaço na memoria e chama a política de substituição se necessário
Page* check_memory_space();


// Política de substituição
Page* clock_policies();


// Adiciona página na memoria a partir do seu endereço. Atraves de métodos do dsm
Page add_page_memory(int disk_block);


// Salva página no disco (métodos do dsm) e atualiza dados do frame_info
int save_page(Page* frame);


// Remove registro (é necessário busca-lo antes no req_record) e chama atualizaçao do file manager
int rmv_record(int heap_file_id, int page_id, int chave);


// Atualiza registro é necessário buscar para ver a diferença
int update_record(int heap_file_id, int page_id, int num_slot, Record record);


// Retorna o frame que possui a mesma página de um bloco
int num_frame(int disk_block);


// Atualiza dirt bit
void update_dirty_bit(int num_frame, int status);


// Atualiza pin count
void update_pin_count(int num_frame, int num);


// Retorna numero do slot do registro buscado sabendo a página
int req_record_page(int heap_file_id, int page_id, int chave);


// Retorna numero do slot do registro buscado com a página desconhecida
int req_record(int heap_file_id, int chave);
