#include "funcoes.h"
#include <stdio.h>
#include <string.h>


typedef struct{
    char desc[300];
    char cat[100];
    char state[100];
    int prio;
} Tarefa; //cria a struct Tarefa onde há todas as variaveis do objeto Tarefa

Tarefa list[100]; //cria um array do struct Tarefa para manter as 100 tarefas que podem ser criadas
int i = 0;//cria um contador para o numero de tarefas

void criar(){//função que cria as tarefas
    Tarefa tarefa; //objeto tarefa onde serao guardados os atributos escaneados
    int estado;
    int categ;
    printf("\n");
    printf("Qual a categoria da tarefa?\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");//escolha da categoria
    scanf("%d", &categ);
    if (categ == 1){
      strcpy(tarefa.cat, "Limpeza");
    }
    else if (categ == 2){
      strcpy(tarefa.cat, "Trabalho");
    }
    else if (categ == 3){
      strcpy(tarefa.cat, "Organizacao");
    }
    else if (categ == 4){
      strcpy(tarefa.cat, "Outros");
    }
    else{//caso o usuario digite um valor invalido
      printf("Categoria invalida\n");
      menu();
    }
    printf("Qual a prioridade da tarefa?\n1-Urgente\n2-Necessaria\n3-Nao muito importante\n");//escolha da prioridade
    int prio;
    scanf("%d", &prio);
    if(prio!=1&&prio!=2&&prio!=3){//caso o usuario digite um valor invalido
      printf("Prioridade invalida\n");
      menu();
    }
    else{
      tarefa.prio = prio;//caso o usuario digite um valor valido
    }
    printf("Qual o estado da tarefa?\n1-Completo\n2-Em andamento\n3-Nao iniciado\n");//escolha do estado
    scanf("%d", &estado);
    if(estado == 1){
      strcpy(tarefa.state, "Completo");
    }
    else if(estado == 2){
      strcpy(tarefa.state, "Em andamento");
    }
    else if(estado == 3){
      strcpy(tarefa.state, "Nao iniciado");
    }
    else{
      printf("Estado invalido\n");
      menu();
    }
    printf("Qual a descricao da tarefa?\n");//escolha da descricao
    scanf("%s", tarefa.desc);
  
    list[i] = tarefa; //coloca o objeto tarefa dentro do array list
    i++; //incrementa o número de tarefas
    menu();
}

void deletar(){ //função para deletar tarefa
    int del;
    printf("\n");
    printf("Digite qual o numero da tarefa que deseja deletar:\n"); //pede o numero da tarefa qual se deseja apagar
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
  int escolha;
  int categ;
  int prio;
  int state;
  printf("\nEscolha como voce deseja listar suas tarefas:\n1-Listar todas as tarefas\n2-Listar tarefas por categoria\n3-Listar tarefas por prioridade\n4-Listar tarefas por estado\n5-Listar por prioridade e categoria.\n");//escolha de como voce quer listar as tarefas
  scanf("%d", &escolha);
  if(escolha == 1){
    for(int x = 0; x<i; x++){ //estrutura de repetição que percorre o array com as tarefas e printa os atributos
        printf("\nTarefa %d:\n", x+1);
        printf("Descricao: %s\n",list[x].desc);
        printf("Categoria: %s\n",list[x].cat);
        printf("Prioridade: %d\n",list[x].prio);
        printf("Estado: %s\n",list[x].state);
    }
  }
  else if(escolha == 2){
      printf("Qual a categoria da tarefa?\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");//escolha da categoria
      scanf("%d", &categ);
      if (categ == 1){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Limpeza") == 0){//compara a categoria com a escolhida e printa as tarefas
            printf("\nTarefa %d:\n", x+1);
            printf("Descricao: %s\n",list[x].desc);
            printf("Categoria: %s\n",list[x].cat);
            printf("Prioridade: %d\n",list[x].prio);
            printf("Estado: %s\n",list[x].state);
          }
        }
      }
      else if (categ == 2){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Trabalho") == 0){//compara a categoria com a escolhida e printa as tarefas
            printf("\nTarefa %d:\n", x+1);
            printf("Descricao: %s\n",list[x].desc);
            printf("Categoria: %s\n",list[x].cat);
            printf("Prioridade: %d\n",list[x].prio);
            printf("Estado: %s\n",list[x].state);
          }
        }
      }
      else if (categ == 3){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Organizacao") == 0){//compara a categoria com a escolhida e printa as tarefas
            printf("\nTarefa %d:\n", x+1);
            printf("Descricao: %s\n",list[x].desc);
            printf("Categoria: %s\n",list[x].cat);
            printf("Prioridade: %d\n",list[x].prio);
            printf("Estado: %s\n",list[x].state);
          }
        }
      }
      else if (categ == 4){
        for(int x=0; x<i; x++){
          if(list[x].cat == "Outros"){//compara a categoria com a escolhida e printa as tarefas
            printf("\nTarefa %d:\n", x+1);
            printf("Descricao: %s\n",list[x].desc);
            printf("Categoria: %s\n",list[x].cat);
            printf("Prioridade: %d\n",list[x].prio);
            printf("Estado: %s\n",list[x].state);
          }
        }
      }
      else{//caso o usuario digite um numero que nao e escolhido
        printf("Categoria invalida\n");
        menu();
      }
  }
   else if(escolha == 3){
       printf("Qual a prioridade da tarefa?\n1-Urgente\n2-Necessaria\n3-Nao muito importante\n");//escolha da prioridade
      scanf("%d", &prio);
        if(prio!=1 && prio!=2 && prio!=3){//caso o usuario digite um numero que nao e escolhido
           printf("Prioridade invalida\n");
           menu();
         }
      for(int x=0; x<i; x++){
         if(list[x].prio == prio){//compara a prioridade com a escolhida e printa as tarefas
           printf("\nTarefa %d:\n", x+1);
           printf("Descricao: %s\n",list[x].desc);
           printf("Categoria: %s\n",list[x].cat);
           printf("Prioridade: %d\n",list[x].prio);
           printf("Estado: %s\n",list[x].state);
         }
        }
    }
    else if(escolha == 4){
       printf("Qual o estado da tarefa?\n1-Completo\n2-Em andamento\n3-Nao iniciado\n");//escolha do estado
       scanf("%d", &state);
       if (state == 1){
         for(int x=0; x<i; x++){
           if(strcmp(list[x].state, "Completo") == 0){//compara o estado com o escolhido e printa as tarefas
             printf("\nTarefa %d:\n", x+1);
             printf("Descricao: %s\n",list[x].desc);
             printf("Categoria: %s\n",list[x].cat);
             printf("Prioridade: %d\n",list[x].prio);
             printf("Estado: %s\n",list[x].state);
           }
         }
       }
       else if (state == 2){
         for(int x=0; x<i; x++){
           if(strcmp(list[x].state, "Em andamento") == 0){//compara o estado com o escolhido e printa as tarefas
             printf("\nTarefa %d:\n", x+1);
             printf("Descricao: %s\n",list[x].desc);
             printf("Categoria: %s\n",list[x].cat);
             printf("Prioridade: %d\n",list[x].prio);
             printf("Estado: %s\n",list[x].state);
           }
         }
       }
       else if (state == 3){
         for(int x=0; x<i; x++){
           if(strcmp(list[x].state, "Nao iniciado") == 0){//compara o estado com o escolhido e printa as tarefas
             printf("\nTarefa %d:\n", x+1);
             printf("Descricao: %s\n",list[x].desc);
             printf("Categoria: %s\n",list[x].cat);
             printf("Prioridade: %d\n",list[x].prio);
             printf("Estado: %s\n",list[x].state);
           }
         }
       }
       else{
         printf("Estado invalido\n");
         menu();
       }
    }
    else if(escolha == 5){
      printf("Qual a categoria da tarefa?\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");
      scanf("%d", &categ);
      printf("Qual a prioridade da tarefa?\n1-Urgente\n2-Necessaria\n3-Nao muito importante\n");
      scanf("%d", &prio);
      if(prio!=1 && prio!=2 && prio!=3){
         printf("Prioridade invalida\n");
         menu();
       }
      if (categ == 1){
            for(int x=0; x<i; x++){
              if(strcmp(list[x].cat, "Limpeza") == 0 && list[x].prio == prio){//compara a categoria com a escolhida e a prioridade com a escolhida
                printf("\nTarefa %d:\n", x+1);
                printf("Descricao: %s\n",list[x].desc);
                printf("Categoria: %s\n",list[x].cat);
                printf("Prioridade: %d\n",list[x].prio);
                printf("Estado: %s\n",list[x].state);
              }
            }
          }
          else if (categ == 2){
            for(int x=0; x<i; x++){
              if(strcmp(list[x].cat, "Trabalho") == 0 && list[x].prio == prio){//compara a categoria com a escolhida e a prioridade com a escolhida
                printf("\nTarefa %d:\n", x+1);
                printf("Descricao: %s\n",list[x].desc);
                printf("Categoria: %s\n",list[x].cat);
                printf("Prioridade: %d\n",list[x].prio);
                printf("Estado: %s\n",list[x].state);
              }
            }
          }
          else if (categ == 3){
            for(int x=0; x<i; x++){
              if(strcmp(list[x].cat, "Organizacao") == 0 && list[x].prio == prio){//compara a categoria com a escolhida e a prioridade com a escolhida
                printf("\nTarefa %d:\n", x+1);
                printf("Descricao: %s\n",list[x].desc);
                printf("Categoria: %s\n",list[x].cat);
                printf("Prioridade: %d\n",list[x].prio);
                printf("Estado: %s\n",list[x].state);
              }
            }
          }
          else if (categ == 4){
            for(int x=0; x<i; x++){
              if(list[x].cat == "Outros" && list[x].prio == prio){//compara a categoria com a escolhida e a prioridade com a escolhida
                printf("\nTarefa %d:\n", x+1);
                printf("Descricao: %s\n",list[x].desc);
                printf("Categoria: %s\n",list[x].cat);
                printf("Prioridade: %d\n",list[x].prio);
                printf("Estado: %s\n",list[x].state);
              }
            }
          }
          else{
            printf("Categoria invalida\n");
            menu();
          }
      }
    
  menu();
}

void alterar(){
  int x;
  int con;
  int escolha;
  int novo;
  printf("Digite o numero da tarefa que deseja alterar:\n");//escolhe a tarefa que deseja alterar
  scanf("%d", &x);
  x--;
  printf("\nTarefa %d:\n", x+1);
  printf("Descricao: %s\n",list[x].desc);
  printf("Categoria: %s\n",list[x].cat);
  printf("Prioridade: %d\n",list[x].prio);
  printf("Estado: %s\n",list[x].state);
  printf("Confirme se esta e a tarefa desejada. 1-Sim 2-Nao\n");//confirma se a tarefa escolhida é a tarefa que deseja alterar
  scanf("%d", &con);
  if(con == 2){
    menu();
  }
  else if(con != 1){
    printf("Digite um valor valido\n");
    menu();
  }
  printf("Escolha oque voce quer mudar na tarefa.\n1-Descricao\n2-Categoria\n3-Prioridade\n4-Estado\n");//escolhe oque voce quer mudar na tarefa
  scanf("%d", &escolha);
  if(escolha == 1){
    printf("Digite a nova descricao:\n");
    scanf("%s", list[x].desc);
  }
  else if(escolha == 2){
    printf("Digite a nova categoria:\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");
      scanf("%d", &novo);
      if (novo == 1){
        strcpy(list[x].cat, "Limpeza");
      }
      else if (novo == 2){
        strcpy(list[x].cat, "Trabalho");
      }
      else if (novo == 3){
        strcpy(list[x].cat, "Organizacao");
      }
      else if (novo == 4){
        strcpy(list[x].cat, "Outros");
      }
      else{
        printf("Categoria invalida\n");
        menu();
      }
  }
  else if(escolha == 3){
    printf("Digite a nova prioridade:\nUrgente\n2-Necessaria\n3-Nao muito importante\n");
    int prio;
    scanf("%d", &prio);
    if(prio!=1&&prio!=2&&prio!=3){
      printf("Prioridade invalida\n");
      menu();
    }
    else{
      list[x].prio = prio;
    }
  }
  else if(escolha == 4){
    printf("Digite o novo estado:\n-Completo\n2-Em andamento\n3-Nao iniciado\n");
      scanf("%d", &novo);
      if(novo == 1){
        strcpy(list[x].state, "Completo");
      }
      else if(novo == 2){
        strcpy(list[x].state, "Em andamento");
      }
      else if(novo == 3){
        strcpy(list[x].state, "Nao iniciado");
      }
      else{
        printf("Estado invalido\n");
        menu();
      }
  }
  else{
    printf("Escolha invalida\n");
    menu();
  }
  menu();
}

void exportar(){
  int escolha;
  int categ;
  int prio;
  int state;
  printf("\nEscolha como voce deseja exportar suas tarefas:\n1-Exportar por prioridade\n2-Exportar por categoria\n3-Exportar por prioridade e categoria.\n");//escolhe como voce deseja exportar suas tarefas
  scanf("%d", &escolha);
  if(escolha == 1){
    FILE *p = fopen("prioridade.txt", "w");
    printf("Qual a prioridade da tarefa?\n1-Urgente\n2-Necessaria\n3-Nao muito importante\n");
      scanf("%d", &prio);
      if(prio!=1 && prio!=2 && prio!=3){
         fclose(p);
         printf("Prioridade invalida\n");
         menu();
       }
      for(int x=0; x<i; x++){
       if(list[x].prio == prio){
         fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a prioridade escolhida
       }
      }
      fclose(p);
  }
  else if(escolha == 2){
    FILE *p = fopen("categoria.txt", "w");
    printf("Qual a categoria da tarefa?\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");
        scanf("%d", &categ);
        if (categ == 1){
          for(int x=0; x<i; x++){
            if(strcmp(list[x].cat, "Limpeza") == 0){
              fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria escolhida
            }
          }
          fclose(p);
        }
        else if (categ == 2){
          for(int x=0; x<i; x++){
            if(strcmp(list[x].cat, "Trabalho") == 0){
              fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria escolhida
            }
          }
          fclose(p);
        }
        else if (categ == 3){
          for(int x=0; x<i; x++){
            if(strcmp(list[x].cat, "Organizacao") == 0){
              fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria escolhida
            }
          }
          fclose(p);
        }
        else if (categ == 4){
          for(int x=0; x<i; x++){
            if(list[x].cat == "Outros"){
              fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria escolhida
            }
          }
          fclose(p);
        }
        else{
          fclose(p);
          printf("Categoria invalida\n");
          menu();
        }
    }
    else if(escolha == 3){
      FILE *p = fopen("categoria_prioridade.txt", "w");
      printf("Qual a categoria da tarefa?\n1-Limpeza\n2-Trabalho\n3-Organizacao\n4-Outros\n");
      scanf("%d", &categ);
      printf("Qual a prioridade da tarefa?\n1-Urgente\n2-Necessaria\n3-Nao muito importante\n");
      scanf("%d", &prio);
      if(prio!=1 && prio!=2 && prio!=3){
         printf("Prioridade invalida\n");
         menu();
       }
      if (categ == 1){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Limpeza") == 0 && list[x].prio == prio){
            fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria e prioridade escolhidas
          }
        }
        fclose(p);
      }
      else if (categ == 2){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Trabalho") == 0 && list[x].prio == prio){
            fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria e prioridade escolhidas
          }
        }
        fclose(p);
      }
      else if (categ == 3){
        for(int x=0; x<i; x++){
          if(strcmp(list[x].cat, "Organizacao") == 0 && list[x].prio == prio){
            fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria e prioridade escolhidas
          }
        }
        fclose(p);
      }
      else if (categ == 4){
        for(int x=0; x<i; x++){
          if(list[x].cat == "Outros" && list[x].prio == prio){
            fprintf(p, "Tarefa %d: %d  %s  %s  %s\n", x+1, list[x].prio, list[x].cat, list[x].state, list[x].desc);//exporta as tarefas com a categoria e prioridade escolhidas
          }
        }
        fclose(p);
      }
      else{
        fclose(p);
        printf("Categoria invalida\n");
        menu();
      }
  }

  menu();
}

void save(char *arquivo) {//função que salva o array em um arquivo
    FILE *file = fopen(arquivo, "wb");//abre o arquivo
    if (file == NULL) {//se caso der erro avisa
        perror("Erro ao abrir o arquivo");
    }

    for(int x=0;x<i;x++){
      fwrite(list[x].desc, sizeof(list[x].desc), 1, file);
      fwrite(list[x].cat, sizeof(list[x].cat), 1, file);
      fwrite(list[x].state, sizeof(list[x].state), 1, file);
      int prio = list[x].prio +'0';
      fwrite(&prio, sizeof(prio), 1, file);
    }//salva o array no arquivo

    fclose(file);
    printf("Tarefas salvas com sucesso!\n");
}

void lerarquivo(char *arquivo) {//função para ler o arquivo salvo e salvar no array
  int x = 0;
  char prio; 
  FILE *file = fopen(arquivo, "rb");//abre o arquivo para leitura
  if (file == NULL) {
    FILE *file = fopen(arquivo, "wb");
    fclose(file);
    menu();
  }

  while (!feof(file)) {
    Tarefa tarefa;
    fread(tarefa.desc, sizeof(list[x].desc), 1, file);
    fread(tarefa.cat, sizeof(list[x].cat), 1, file);
    fread(tarefa.state, sizeof(list[x].state), 1, file);
    fread(&prio, sizeof(prio), 1, file);
    tarefa.prio =  prio - '0';
    list[x] = tarefa;
    x++;
  }//lê o arquivo e salva no array

  i = x-1;  
  
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
    printf("4 - Alterar tarefa\n");
    printf("5 - Exportar\n");
    printf("0 - Sair\n");
    scanf("%d", &escolha);//vê a escolha do usuário e direciona para a função desejada
    if (escolha == 1) {
        criar();
    } else if (escolha == 2) {
        deletar();
    } else if (escolha == 3) {
        listar();
    } else if (escolha == 4) {
        alterar();
    } else if (escolha == 5){
        exportar();
    } else if (escolha == 0) {
        sair();
    }else {
        printf("Digite uma opcao valida.\n");
        menu();
    }
}

