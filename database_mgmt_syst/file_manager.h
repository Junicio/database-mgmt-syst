#include <stdio.h>

int last_page;

typedef struct {
    int page id;
    int disk_block;             // Qual bloco do disco a página se encontra
    int free_space;             // Quantidade de espaço livre que a página contém
    Directory_pages* next;      // Próxima página do diretório de página
} Directory_pages;

// Nome do Heap file e seu primeiro endereço
typedef struct {
    int heap_id;                    // Id do HeapFile (Tabela)
    Directory_pages* header_page;   // Endereço da primeira página no diretório
    Heap_dictionary* next;          // Próxima informações de outra tabela
} Heap_dictionary;


// Carrega informações do file manager
int fm_load(void);

// Atualiza numero de slots livres
int update_free_space(int heap_file, int page_id, int num_update);

// Criar nova tabela
int cr8_heapfile(int heap_id);


// retorna o id da página com espaço livre ou avisa que nao existe. Além de atualizar free_space etc
// Considera que ela é chamada somente quando for escrever
int free_page(int heap_id);


// Pede para o dsm alocar espaço e retorna o id para a função freepage() chama função de adicionar página no heapfile e chama cr8 page directory
int cr8_page(void);


// Coloca a nova página no heapfile
int cr8_page_directory(int heap_id, int page_id);

// Retorna o endereço da página buscada
int fetch_page(int page_id);
