/*
*       *******       ///////
*       HEADER FUNCTIONS
*
*       AROS-001 - CONSTANTS
*       AROS-002 - STRUCTURES
*       AROS-003 - FUNCTIONS       
*       *******       ///////
*/
#ifndef pimfunctions
#define pimfunctions

// AROS-001

#define CLEAR_CLS "clear" // AROS-01: Alterar o "clear" para "cls" se for em ambiente Windows(SO)

// AROS-002

struct acesso{
    char login[25];
    char senha[7];
};
struct acesso sistema;
struct ficha{
    char nome[30], cpf[15], telefone[15], email[30], endereco[75];
    char cep[9];
    int diaN, mesN, anoN;
    int diaD, mesD, anoD;
    int doenca; //diabetes, obesidade, hipertensão, tuberculose, outros, mais de uma.
}; 
struct ficha paciente;

// AROS-003

void cadastrarPaciente(struct ficha *fc);

void confirmarAcesso(void);

void cadastrarAcesso(struct acesso *ac);

void boasVindas(void);

int retornar(char escolha);

// END

#endif