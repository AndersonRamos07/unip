#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

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
    char cep[9];
    int diaN[3];
    int mesN[3];
    int anoN[5];
    char email[25];
    int diaD[3];
    int mesD[3];
    int anoD[5];
    int doenca; //diabetes, obesidade, hipertensão, tuberculose, outros.
};
struct ficha paciente;

void boasVindas(void);

void cadastrarAcesso(struct acesso *ac);

void confirmarAcesso(void);

void cadastrarPaciente(struct ficha *fc);

// >>>>>>> PROGRAMA PRINCIPAL (main) <<<<<<<

int main(int argc, char *argv[]){

    //boasVindas();

    cadastrarPaciente(&paciente);

   //confirmarAcesso();

   //cadastrarAcesso(&sistema);

    return 0;
};

void boasVindas(void){
    char aswer;
    system("clear");
    printf(STAMP "[======= ÁREA DE CADASTRO DE USUÁRIO =======]\n" ALPHA);
        printf("O que deseja fazer?\n\n");
        printf("\nO que deseja fazer?\n\t\v 1 - Acessar o Sistema:\n\t 2 - Cadastrar novo acesso:\n\t 3 - Protocolo de Fichas:\n\v ...aperte '0'(zero) para sair!\n\nR: ");
        do{
            scanf("%c", &aswer);
            switch (aswer)
        {
        case '1':
            confirmarAcesso();
            break;
        case '2':
            cadastrarAcesso(&sistema);
            break;
        };
        }while(aswer != '1' || aswer != '2' || aswer != '3' || aswer != '0');
            printf(YELLOW "Clica numa opção aceitável, né Einstein!\n" ALPHA);
}

void cadastrarAcesso(struct acesso *ac){
    
    FILE *pointer;

    pointer = fopen("access.txt", "w");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        system("clear");
        printf(STAMP"[======= ÁREA DE CADASTRO DE USUÁRIO =======]\n" ALPHA);
        printf("Digite seu email: "DGRAY "\n--servirá como login de acesso-- \n\t" ALPHA);
        scanf("%s", ac->login);
        fflush(stdin);
        printf("\nAgora uma senha:" DGRAY "\n--deverá conter 5 digitos-- \n\t" ALPHA);
        scanf("%s", ac->senha);
        fprintf(pointer, "login:\t%s\nsenha:\t%s\n", ac->login, ac->senha);
        fclose(pointer);
        printf(YELLOW "\vNovos dados de acesso cadastrados com sucesso!\n\7"ALPHA);
    };
    exit(0);
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
            printf(YELLOW "\vBem vindo ao sistema!\n\v" ALPHA);
            exit(0);
        };
};

void cadastrarPaciente(struct ficha *fc){
    int idade = 0;
    int calc = 0;
    int tem = 0;

    FILE *pointer;

    pointer = fopen("fichas.txt", "a");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        system("clear");
        printf(STAMP"[======= ÁREA DE CADASTRO DE PACIENTE =======]\n" ALPHA);
            printf("\vNome do paciente:....... \t");
            scanf("%s", fc->nome);
            fflush(stdin);
            printf("\nCPF:....... \t");
            scanf("%d", fc->cpf);
            fflush(stdin);
            printf("\nTelefone:....... \t");
            scanf("%d", fc->telefone);
            fflush(stdin);
            printf("\nEndereço:....... \t");
            scanf("%s", fc->endereco);
            fflush(stdin);
            printf("\nCEP:....... \t");
            scanf("%s", fc->cep);
            fflush(stdin);
            printf("\nData de nascimento:....... \t");
            scanf("%d/\b%d/\b%d\b", fc->diaN, fc->mesN, fc->anoN);
            fflush(stdin);
            printf("\nE-mail:....... \t");
            scanf("%s", fc->email);
            fflush(stdin);
            printf("\nData do diagnóstico:....... \t");
            scanf("%d[^\n]", fc->diaD); printf("\b /");
            scanf("%d[^\n]", fc->mesD); printf("\b /");
            scanf("%d[^\n]", fc->anoD);
            fflush(stdin);

            idade = *fc->anoN;
            calc = (2020 - idade);
            if(calc >= 65 || tem > 0){
                printf(RED "\vPACIENTE PERTENCE AO GRUPO DE RISCO\n" ALPHA);
                fprintf(pointer, "CEP:\t%s\nIdade:\t%d anos\n\n", fc->cep, calc);
                printf(YELLOW"GERADO ARQUIVO PARA ENVIO À SS");
            };
            
            fclose(pointer);
        printf(YELLOW "\vNovos dados de acesso cadastrados com sucesso!\n\7"ALPHA);
    };
    exit(0);
};