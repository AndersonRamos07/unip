#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

char login [25]; char senha[25];
int cont = 0;

char nomep [25], emailp [50];
char ruaav [50]; int ruanum; char bairro [25], cidade [25], uf [3]; int cep [9]; //registro do endereço
int cpfp, telefonep, datap, datadp, febredorato; //"febredorato" é apenas pra não digitar aquele nome... hehe

//fdr 1 = diabetes, 2 = obesidade, 3 = hipertensão, 4 = tuberculose, 5 = outros

void boasVindas (void);

void confirmaLogin (void);

void novoCadastro (void);

int main(int argc, char **argv){

    boasVindas();       

    return 0;
}

void boasVindas(){
    int resposta;
    printf("\nSEJA BEM VIND@ AO SISTEMA DO PIM IV\n");

    printf("\nO que deseja fazer?\n\t1 - Acessar o Sistema:\n\t2 - Cadastrar novo acesso:\n\t...aperte qualquer outra tecla para sair!\nR: ");
    scanf("%d", &resposta);
        if(resposta==1){
            confirmaLogin();
        }
        else if(resposta==2){
            novoCadastro();
        }
        else{
            exit(0);
        };
}

void confirmaLogin (){
    printf("\n\t>>>>>>>teste de Acesso ao sistema<<<<<<<\n");
    printf("\n\tRetornando para a tela de Boas-Vindas!<-------\n\t\t");
    boasVindas();
};

void novoCadastro (){
    printf("\n\t>>>>>>>teste de novo cadastro<<<<<<<\n");
    printf("\n\tRetornando para a tela de Boas-Vindas!<-------\n\t\t");
    boasVindas();
};