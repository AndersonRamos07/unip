#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pim_colors.h"

struct acesso
{
    char login[25];
    char senha[7];
};
struct acesso sistema;

struct ficha
{
    char nome[25];
    int cpf[15];
    int telefone[15];
    char endereco[65];
    int nascimento[10];
    char email[25];
    int diagnostico[10];
    int doenca; //diabetes, obesidade, hipertensão, tuberculose, outros.
};
struct ficha paciente;

void cadastrarAcesso(struct acesso *ac);

void confirmarAcesso(void);

// >>>>>>> PROGRAMA PRINCIPAL (main) <<<<<<<

int main(int argc, char *argv[]){

   confirmarAcesso();

   //cadastrarAcesso(&sistema);

    return 0;
};

void cadastrarAcesso(struct acesso *ac){
    
    FILE *pointer;

    pointer = fopen("access.txt", "w");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        system("clear");
        printf(STAMP "[======= ÁREA DE CADASTRO DE USUÁRIO =======]\n" ALPHA);
        printf("Digite seu email: "DGRAY "\n--servirá como login de acesso-- \n\t" ALPHA);
        scanf("%s", ac->login);
        fflush(stdin);
        printf("\nAgora uma senha:" DGRAY "\n--deverá conter 5 digitos-- \n\t" ALPHA);
        scanf("%s", ac->senha);
        fprintf(pointer, "login:\t%s\nsenha:\t%s\n", ac->login, ac->senha);
        fclose(pointer);
        printf(YELLOW "\vNovos dados de acesso cadastrados com sucesso!\n\7"ALPHA);
    };
};

void confirmarAcesso(void){
    char logtmp[25];
    char snhtmp[7];

    char complogin[25];
    char compsnh[7];

    int checkoutL, checkoutS;

    FILE *pointer;

    pointer = fopen("access.txt", "r");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        do{
        system("clear");
        printf(STAMP "[======= ÁREA DE ACESSO DO SISTEMA PIM-IV =======]\n" ALPHA);
        printf("Digite seu email: ");
        scanf("%s", logtmp);
        fflush(stdin);
        printf("\nDigite sua senha: ");
        scanf("%s", snhtmp);
        fscanf(pointer, "login:\t%s\nsenha:\t%s\n", complogin, compsnh);
        fclose(pointer);

        checkoutL = strcmp(logtmp, complogin);
        checkoutS = strcmp(snhtmp, compsnh);

        }while(checkoutL != 0 || checkoutS != 0);
            printf("\vBem vindo ao sistema!\n\v");
            exit(0);
        };
};