#include <stdio.h>


typedef struct directory_pages Directory_pages;
typedef struct heap_dictionary Heap_dictionary;

int last_page;
Heap_dictionary* HEAP;

// Atualiza numero de slots livres
int update_free_space(int heap_file, int page_id, int num_update);

// Criar nova tabela
int cr8_heapfile(int heap_id);

// Carrega informações do file manager
int fm_load(void);

// retorna o id da página com espaço livre ou avisa que nao existe. Além de atualizar free_space etc
// Considera que ela é chamada somente quando for escrever
int get_free_page(int heap_id);


// Pede para o dsm alocar espaço e retorna o id para a função freepage() chama função de adicionar página no heapfile e chama cr8 page directory
int cr8_page(void);


// Coloca a nova página no heapfile
int cr8_page_directory(int heap_id, int page_id, int disk_block);

// Retorna o endereço da página buscada
int fetch_page(int heap_id, int page_id);
