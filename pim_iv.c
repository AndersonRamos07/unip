#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define ALPHA "\x1b[0m"
#define GRAY "\e[0;37m"
#define DGRAY "\e[1;30m"

typedef enum { false, true } bool;

char login [25]; char senha[25];
int count = 0;

//REGISTRO DO PACIENTE

char nomeP [25], cpfP [15], telefoneP [20], emailP [50]; //DADOS DE CONTATO
char endereco [70], cep[9]; //DADOS DE ENDEREÇO
char dataP, datadP; //DATAS
int febredorato; //"febredorato" é apenas pra não digitar aquele nome... hehe

//COMO IRÁ FUNCIONAR OS ID DAS PATOLOGIAS
//fdr 1 = diabetes, 2 = obesidade, 3 = hipertensão, 4 = tuberculose, 5 = outros

void boasVindas (void);

void confirmaLogin (void);

void novoCadastro (void);

void informeDP (void);

int main(int argc, char **argv){

    confirmaLogin();       

    return 0;
}

void boasVindas(){
    system("clear");
    int resposta;
    printf(GREEN "\nSEJA BEM VIND@ AO SISTEMA DO PIM IV\n" ALPHA);

    printf("\nO que deseja fazer?\n\t\v 1 - Acessar o Sistema:\n\t 2 - Cadastrar novo acesso:\n\t 3 - Inserir dados do Paciente:\n\t ...aperte qualquer outra tecla para sair!\n\nR: ");
    scanf("%d", &resposta);
        switch(resposta){
            case 1:
                confirmaLogin();
            break;
            case 2:
                novoCadastro();
            break;
            case 3:
                informeDP();
            break;
            default:
                printf("Favor selecione uma das opções!\n");
                confirmaLogin();
        };
}

void confirmaLogin (){
    system("clear");
    printf(RED "\n\t>>>>>>>ACESSO AO SISTEMA<<<<<<<\n" ALPHA);
    printf("\v\nInsira o login: " DGRAY " --digita qualquer coisa--" ALPHA "\n\t");
    scanf("%s", &login[0]);
    printf("\v\nInsira a senha: " DGRAY " --relaxa que não tem senha nenhuma--" ALPHA "\n\t");
    scanf("%s", &senha[0]);
    printf("\n\tRetornando para a tela de Boas-Vindas!<-------\n\v");
    boasVindas();
};

void novoCadastro (){
    system("clear");
    printf(RED "\n\t>>>>>>>NOVO CADASTRO<<<<<<<\n" ALPHA);
    printf("\v\nInsira o login: " DGRAY " --digita qualquer coisa--" ALPHA "\n\t");
    scanf("%s", &login[0]);
    printf("\v\nInsira a senha: " DGRAY " --digita uma senha qualquer--" ALPHA "\n\t");
    scanf("%s", &senha[0]);
    printf("\n\tRetornando para a tela de Boas-Vindas!<-------\n\v");
    boasVindas();
};

void informeDP (){
    int cont = 0;
    system("clear");
    printf(BLUE "\v >>>Informe os dados do paciente: \n" ALPHA);
        printf("\v\tNome: \n\t");
        scanf("%s", &nomeP[cont]);
        setbuf(stdin, NULL);
        printf("\v\tCPF: \n\t");
        scanf("%s", &cpfP[cont]);
        setbuf(stdin, NULL);
        printf("\v\tTelefone: \n\t");
        scanf("%s", &telefoneP[cont]);
        setbuf(stdin, NULL);
        printf("\v\t Endereço completo: " DGRAY "Exemplo: Rua Dr. Ulisses, 23 - Vila UNIP, São Paulo - SP \n\t" ALPHA);
        scanf("%s", &endereco[cont]);
        setbuf(stdin, NULL);
        printf("\n\t CEP: \n\t");
        scanf("%s", &cep[cont]);
        setbuf(stdin, NULL);             
    printf(GREEN "\n\v Testado!\n\v" ALPHA);
    cont++;
    exit(0);
}