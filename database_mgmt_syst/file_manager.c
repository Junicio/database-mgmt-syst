#include "file_manager.h"
#include "disk_space_manager.h"

struct directory_pages{
    int page_id;
    int disk_block;             // Qual bloco do disco a página se encontra
    int free_space;             // Quantidade de espaço livre que a página contém
    Directory_pages* next;      // Próxima página do diretório de página
};

// Nome do Heap file e seu primeiro endereço
struct heap_dictionary{
    int heap_id;                    // Id do HeapFile (Tabela)
    Directory_pages* header_page;   // Endereço da primeira página no diretório
    Heap_dictionary* next;          // Próxima informações de outra tabela
};

int cr8_page_directory(int heap_id, int page_id, int disk_block) {
    Heap_dictionary* aux = HEAP;
    Directory_pages* new_page = (Directory_pages*)malloc(sizeof(Directory_pages));
    Directory_pages* pg_aux = NULL;

    while(aux != NULL) {
        if(heap_id == aux->heap_id) {
            new_page->page_id = page_id;
            new_page->disk_block = page_id;
            new_page->free_space = 4;
            new_page->next = NULL;

            pg_aux = aux->header_page;
            if(pg_aux != NULL) {
                while(pg_aux->next != NULL) {
                    pg_aux = pg_aux->next;
                }
            } else {pg_aux = new_page; return 1;}
            pg_aux->next = new_page;

            return 1;
        }
        aux = aux->next;
    }

    return 0;
}

int initHeap() {
    HEAP = (Heap_dictionary*)malloc(sizeof(Heap_dictionary));
    HEAP->heap_id = 0;
    HEAP->header_page = NULL;
    HEAP->next = NULL;
}

int fm_load(void) {
}

int get_free_page(int heap_id) {
    Heap_dictionary* hp_aux = HEAP;
    Directory_pages* pg_aux = NULL;

    while(hp_aux != NULL) {
        if(heap_id == hp_aux->heap_id) {
            pg_aux = hp_aux->header_page;

            while(pg_aux != NULL) {
                if(pg_aux->free_space > 0) {
                    return pg_aux->page_id;
                }
            }
        }
    }

    return -1;
}

int fetch_page(int heap_id, int page_id) {
    Heap_dictionary* hp_aux = HEAP;
    Directory_pages* pg_aux = NULL;

    while(hp_aux != NULL) {
        if(hp_aux->heap_id == heap_id) {
            pg_aux = hp_aux->next;

            while(pg_aux != NULL) {
                if(pg_aux->page_id == page_id) {
                    return pg_aux->disk_block;
                }
                pg_aux = pg_aux->next;
            }
        }
    }

    return -1;
}

int cr8_page(void) {

}
