#include "projeto.h"
#include <stdio.h>

typedef struct{
    char desc[300];
    char cat[100];
    int prio;
} Tarefa; //cria a struct Tarefa onde há todas as variaveis do objeto Tarefa

Tarefa list[100]; //cria um array do struct Tarefa para manter as 100 tarefas que podem ser criadas
int i = 0;//cria um contador para o numero de tarefas

void criar(){//função que cria as tarefas
    Tarefa tarefa; //objeto tarefa onde serao guardados os atributos escaneados
    printf("\n");
    printf("Qual a categoria da tarefa?\n");
    scanf("%s", tarefa.cat);
    printf("Qual a descricao da tarefa?\n");
    scanf("%s", tarefa.desc);
    printf("Qual a prioridade da tarefa?\n");
    scanf("%d", &tarefa.prio);

    list[i] = tarefa; //coloca o objeto tarefa dentro do array list
    i++; //incrementa o número de tarefas
    menu();
}

void deletar(){ //função para deletar tarefa
    int del;
    printf("\n");
    printf("Digite qual o numero da tarefa deseja deletar:\n"); //pede o numero da tarefa qual se deseja apagar
    scanf("%d", &del);
    del--; //diminui um no valor pois a posição na array começa em 0
    for(del; del<i; del++){ //procura a tarefa dentro do array e tira ela colocando as tarefas subsequentes na posição
        list[del] = list[del+1];
    }
    i--;//diminui o numero de tarefas
    printf("Sua tarefa foi removida com sucesso.\n");
    menu();
}

void listar(){//função que lista as tarefas
    for(int x = 0; x<i; x++){ //estrutura de repetição que percorre o array com as tarefas e printa os atributos
        printf("\nTarefa %d:\n", x+1);
        printf("Descricao: %s\n",list[x].desc);
        printf("Categoria: %s\n",list[x].cat);
        printf("Prioridade: %d\n",list[x].prio);
    }
    menu();
}

void save(char *arquivo) {//função que salva o array em um arquivo
    FILE *file = fopen(arquivo, "wb");//abre o arquivo
    if (file == NULL) {//se caso der erro avisa
        perror("Erro ao abrir o arquivo");
    }

    // escrever a quantidade de tarefas
    fwrite(&i, sizeof(int), 1, file);

    // escrever as tarefas dentro do arquivo
    fwrite(list, sizeof(Tarefa), i, file);

    fclose(file);
    printf("Tarefas salvas com sucesso!\n");
}

void lerarquivo(char *arquivo) {//função para ler o arquivo salvo e salvar no array
    FILE *file = fopen(arquivo, "rb");//abre o arquivo para leitura
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
    }

    // lê a quantidade de tarefas
    fread(&i, sizeof(int), 1, file);

    // lê as tarefas e armazena no array
    fread(list, sizeof(Tarefa), i, file);

    fclose(file);
    printf("Tarefas carregadas com sucesso!\n");

}

void sair() {//função para sair
    save("tarefas.bin");//salva o array em um arquivo antes de sair
    printf("\nSaindo...\n");
}

void menu() {//função para o menu
    int escolha;
    printf("\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("0 - Sair\n");
    scanf("%d", &escolha);//vê a escolha do usuário e direciona para a função desejada
    if (escolha == 1) {
        criar();
    } else if (escolha == 2) {
        deletar();
    } else if (escolha == 3) {
        listar();
    } else if (escolha == 0) {
        sair();
    }else {
        printf("Digite uma opcao valida.\n");
        menu();
    }
}

