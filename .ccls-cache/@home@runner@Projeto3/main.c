#include <stdio.h>
#include "funcoes.h"

int main(){
    lerarquivo("tarefas.bin");//lê se existe algum arquivo existente já com tarefas salvas
    printf("\nSeja bem vindo a sua lsta de tarefas.\n");
    menu();//chama a função menu criada no arquivo projeto.c

    return(0);
}