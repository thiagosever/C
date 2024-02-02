#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<math.h>
#include<locale.h>


#define MAX_ATENDIMENTOS 999
struct atendimento
{
    int tipo_atendimento;
    char nome[30];
    char cpf[15];
};

struct atendimento atendimentos[MAX_ATENDIMENTOS];
int num_atendimentos, i = 0;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);}

void cadastrar_atendimento(){

    if(num_atendimentos<MAX_ATENDIMENTOS){
        
        printf("Digite o nome para atendimento:");
        limparBufferEntrada();
        fgets(atendimentos[num_atendimentos].nome, sizeof(atendimentos[num_atendimentos].nome), stdin);
        fflush(stdin);
        printf("Digite o número do CPF:");
        scanf("%s", atendimentos[num_atendimentos].cpf);
        fflush(stdin);
        printf("Escolha o tipo de atendimento:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n");
        scanf("%d", &atendimentos[num_atendimentos].tipo_atendimento);
        fflush(stdin);
        num_atendimentos++;
        system("clear");
        printf("Atendimento cadastrado!\n");
        
    }
    else{
            printf("Sem espaço para cadastrar novos atendimentos, chame um atendente.\n");
    }
}

void listar_atendimento(){
    
    if (num_atendimentos>0){
        for(i=0;i<num_atendimentos;i++){
            
            printf("\nNome: %s\n", atendimentos[i].nome);
            printf("CPF: %s\n", atendimentos[i].cpf);
            printf("Tipo de Atendimento - %d.\n", atendimentos[i].tipo_atendimento);

            switch (atendimentos[i].tipo_atendimento)
            {
            case 1:
                printf("Abertura de Conta\n");
                break;
            case 2:
                printf("Caixa\n");
                break;
            case 3:
                printf("Gerente Pessoa Física\n");
                break;
            case 4:
                printf("Gerente Pessoa Jurídica\n");
                break;
        
            default:
                printf("Número inválido, por favor, selecionar uma opção de 1 a 4.");
                break;
            }

            printf("=================================\n");

        }
    }else{
        system("clear");
        printf("Nenhum atendimento registrado até o momento.");
    }
}

void listar_atendimento_setor(){
    
    int atendimento_selecionado;
    printf("Escolha o tipo de atendimento que deseja listar:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &atendimento_selecionado);

    if (num_atendimentos > 0){
        for(int i=0; i<num_atendimentos;i++){
            if(atendimentos[i].tipo_atendimento == atendimento_selecionado){
                printf("\nNome: %s\n", atendimentos[i].nome);
                printf("\nCPF: %s\n", atendimentos[i].cpf);
                printf("\nTipo de Atendimento: %d\n", atendimentos[i].tipo_atendimento);

                switch (atendimentos[i].tipo_atendimento){
                case 1:
                    printf("Abertura de Conta\n");
                    break;
                case 2: 
                    printf("Caixa\n");
                    break;
                case 3:
                    printf("Gerente Pessoa Física\n");
                    break;
                case 4:
                    printf("Gerente Pessoa Jurídica\n");
                    break;

                default:
                    system("clear");
                    printf("Erro. Tipo de atendimento não reconhecido.");

                }
                printf("================================\n");
            }
        }
    }else{
        system("clear");   
        printf("Sem atendimentos registrados até o momento.\n");
    }

}

int main(){

    int op;
    setlocale(LC_ALL, "Portuguese");

    while(op!=4){
        printf("\nBem vindo ao sistema de Atendimento\n 1 - Solicitar Atendimento\n 2 - Listar Atendimento\n 3 - Listar Atendimento por Setor\n 4 - Sair\n Escolha uma das opções:\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
            case 1:
                system("clear");
                cadastrar_atendimento();
                break;
            case 2:
                system("clear");
                listar_atendimento();
                break;
            case 3:
                system("clear");
                listar_atendimento_setor();
                break;
            case 4:
                system("clear");
                printf("Sistema encerrado.\n");
                break;

            default:
                printf("Selecione uma opção válida.\n");
                break;
        }
    }
    return(0);
}

