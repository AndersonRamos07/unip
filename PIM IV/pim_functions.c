/*
*       *******       ///////
*       FUNCTIONS
*
*       AROS-001 - HEADER
*       AROS-002 - FUNCTIONS
*
*       *******       ///////
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AROS-001

#include "pim_colors.h"
#include "pim_functions.h"

// AROS-002

void boasVindas(void){
    char aswer;
    system(CLEAR_CLS); // AROS-C
    printf(STAMP "[  ||     =============================     ||  ]\n" ALPHA);
    printf(STAMP "[::++::== CONTROLE PANDEMICO (COVID-19) ==::++::]\n" ALPHA);
    printf(STAMP "[  ||     =============================     ||  ]\n" ALPHA);
    printf("\n * O QUE DESEJA FAZER?\n\t\v 1 - Acessar o Sistema:\n\t 2 - Cadastrar novo acesso:\n\t 3 - Protocolo de Fichas:\n\t\v ...aperte '0'(zero) para sair!\n\n * R: ");
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
            case '0':
                break;            
            };
            printf(YELLOW "Selecione uma opção válida! \n" ALPHA);
        }while(aswer != '0');
        system("pause");
};

void cadastrarAcesso(struct acesso *ac){
    
    FILE *pointer;

    pointer = fopen("access.txt", "w");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        system(CLEAR_CLS); // AROS-C
        printf(STAMP "[  ||     =============================     ||  ]\n" ALPHA);
        printf(STAMP "[::++::== CONTROLE PANDÊMICO (COVID-19) ==::++::]\n" ALPHA);
        printf(STAMP "[  ||     "BSTAMP"=====CADASTRO DE USUÁRIO====="ALPHA STAMP"     ||  ]\n" ALPHA);
        printf("\n * Digite seu email: "DGRAY "--servirá como login de acesso-- \n\t" ALPHA);
        scanf("%s", ac->login);
        fflush(stdin);
        printf("\n * Agora uma senha:" DGRAY "--deverá conter 5 digitos-- \n\t" ALPHA);
        scanf("%s", ac->senha);
        fprintf(pointer, "login:\t%s\nsenha:\t%s\n", ac->login, ac->senha);
        fclose(pointer);
        printf(YELLOW "\vNovos dados de acesso cadastrados com sucesso!\n\7"ALPHA);
    };
    exit(0);
};

void confirmarAcesso(void){
    char logtmp[25], complogin[25];
    char snhtmp[7], compsnh[7];
    int checkoutL, checkoutS;

    FILE *pointer;

    pointer = fopen("access.txt", "r");

    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }do{
        system(CLEAR_CLS); // AROS-C
        printf(STAMP "[  ||     =============================     ||  ]\n" ALPHA);
        printf(STAMP "[::++::== CONTROLE PANDÊMICO (COVID-19) ==::++::]\n" ALPHA);
        printf(STAMP "[  ||     "GSTAMP"===========ACESSAR==========="ALPHA STAMP"     ||  ]\n" ALPHA);
        printf("\n * Digite seu email: \n\t");
        scanf("%s", logtmp);
        fflush(stdin);
        printf("\n * Digite sua senha: \n\t");
        scanf("%s", snhtmp);
        fscanf(pointer, "login:\t%s\nsenha:\t%s\n", complogin, compsnh);
        fclose(pointer);

        checkoutL = strcmp(logtmp, complogin);
        checkoutS = strcmp(snhtmp, compsnh);

        }while(checkoutL != 0 || checkoutS != 0);
        cadastrarPaciente(&paciente);
};

void cadastrarPaciente(struct ficha *fc){
    int idade = 0;
    int tem = 0;

    FILE *pointer;

    pointer = fopen("registered.txt", "a");
    
    if(pointer == NULL){
        printf("Erro ao abrir o arquivo!");
    }else{
        system(CLEAR_CLS); // AROS-C
        printf(STAMP "[  ||     =============================     ||  ]\n" ALPHA);
        printf(STAMP "[::++::== CONTROLE PANDÊMICO (COVID-19) ==::++::]\n" ALPHA);
        printf(STAMP "[  ||     "YSTAMP"=====CADASTRO DE PACIENTE===="ALPHA STAMP"     ||  ]\n" ALPHA);
        INI: printf("\nNome do paciente:....... \n\t");
        fgets(fc->nome, 25, stdin);
        printf("\nCPF:....... \n\t");
        fgets(paciente.cpf, 25, stdin);
        printf("\nTelefone:....... \n\t");
        fgets(paciente.telefone, 25, stdin);
        printf("\nE-mail:....... \n\t");
        fgets(paciente.email, 25, stdin);
        printf("\nEndereço:....... \n\t");
        fgets(paciente.endereco, 75, stdin);
        printf("\nCEP:....... \n\t");
        scanf("%s", fc->cep);
        fflush(stdin);
            printf("\nData de nascimento:");
            printf("\n....... Dia:");scanf("%d", &paciente.diaN);
            printf("....... Mês:");scanf("%d", &paciente.mesN);
            printf("....... Ano:");scanf("%d", &paciente.anoN);
            fflush(stdin);
            printf("\nData do diagnótico:");
            printf("\n....... Dia:");scanf("%d", &paciente.diaD);
            printf("....... Mês:");scanf("%d", &paciente.mesD);
            printf("....... Ano:");scanf("%d", &paciente.anoD);
            printf("\nO paciente possui alguma dessas doenças?\n Se sim, digite o número correspondente:");
            printf("\n\t\v-Diabetes?(1)\n\t-Obesidade?(2)\n\t-Hipertensão?(3)\n\t-Tuberculose?(4)\n\t-Outras?(5)\n\t-Mais de uma?(6)\n\v\t Digite '0'(zero) Caso negativo!\n\nR: ");
                scanf("%d", &tem);
                    switch (tem)
                    {
                        case 1:
                            tem = 1;
                            break;
                        case 2:
                            tem = 2;
                            break;
                        case 3:
                            tem = 3;
                            break;
                        case 4:
                            tem = 4;
                            break;
                        case 5:
                            tem = 5;
                            break;
                            case 6:
                                tem = 6;
                                break;
                            case 0:
                                tem = 0;
                                break;
                            default:
                                printf(YELLOW "Favor clicar em uma das opções válidas!\n" ALPHA);
                        };
                idade = (paciente.anoD - paciente.anoN);
                if(idade >= 65 || tem > 0){
                    printf(RED "\v *** PACIENTE PERTENCE AO GRUPO DE RISCO *** \n" ALPHA);
                    fprintf(pointer, "CEP:\t%s\nIdade:\t%d anos\n\n", fc->cep, idade);
                    fclose(pointer);
                    printf(YELLOW"ARQUIVO GERADO PARA ENVIO À SECRETARIA DE SAÚDE\n" ALPHA);
                }else{
                    printf(YELLOW "\vNovos dados de paciente cadastrados com sucesso!\n\7"ALPHA);
                };
        //   retornarCadastro();        
        };
    exit(0);
};

// END

/*
int retornarCadastro(){
    int choice;
     printf("\n * O QUE DESEJA FAZER AGORA?\n\t\v 1 - Realizar outro cadastro:\n\t 2 - Retornar ao menu inicial:\n\t 3 - Sair do Sistema:\n\t\v\n\n * R: ");
        do{
            scanf("%c", &choice);
            switch (choice)
            {
            case '1':
                confirmarAcesso();
                break;
            case '2':
                cadastrarAcesso(&sistema);
                break;
            case '0':
                break;            
            };
            printf(YELLOW "Selecione uma opção válida! \n" ALPHA);
        }while(aswer != '0');
        return 0;
}
*/