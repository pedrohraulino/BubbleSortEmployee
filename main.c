#include "funcionario.c"  //.c compila gcc -o main main.c

#define MAX_FUNCIONARIO 10

int main() {

    int escolha, contador = 0, contador2 = 0, sair = 0;

    Funcionario *VarFuncionario[10];

    // criando arquivo de texto para armazenar os dados dos funcionarios.
    //FILE *arquivo = fopen("funcionario.txt", "w");
    FILE *arquivo;
    if(arquivo == NULL) {
        exit(1);
    }

    //SalvarDados(arquivo, VarFuncionario, contador);

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;
    
    char nome[50], cargo[50];
    int documento;

    do {
        menu();
        scanf("%d", &escolha); 

        switch(escolha){
            case 1: // Cadastrando os dados na struct Funcionario.
                 do{
                        contador2++;
                        printf("FUNCIONARIO %i \n", contador2);
                        printf("Informe Seu Nome: ");
                        scanf(" %[^\n]", nome);

                        printf("Informe Seu Cargo: ");
                        scanf(" %[^\n]", cargo);

                        printf("Informe Seu Documento: ");
                        scanf("%d", &documento);

                        VarFuncionario[contador] = CriarFuncionario(nome, cargo, documento);
                        Ordenar(arquivo, VarFuncionario, contador);
                        
                        printf("Continuar Cadastrando (1) SIM / (2) NAO ");
                        scanf("%d", &sair);

                        if(sair != 1 && sair != 2) {
                            while(sair != 1 && sair != 2) { 
                                printf("Voce digitou um numero incorreto! \n");
                                printf("Continuar cadastrando (1) SIM / (2) NAO: \n");
                                scanf("%d", &sair);
                            }
                        }
                        if(contador == MAX_FUNCIONARIO) {
                            printf("Limite de cadastro foi atingido! \n");
                            break;
                        }    

                    contador++;
                 } while(sair != 2 && contador != 10);
        
                break;

            case 2: // Listando os dados do arquivo. 
                while(sair != 1) {
                    if(contador == 0) {
                        printf("Voce precisa fazer algum cadastro! \n");
                        printf("Digite 1 para sair! \n");
                        scanf("%d", &sair);
                    } else if(contador != 0) {
                        printf("LISTA ATUALIZADA! \n");
                        printf("Digite 1 para sair! \n");
                        scanf("%d", &sair);    
                    }
                }
                    
                break;

            case 3: // Fechando o programa.
                printf("OBRIGADO POR USAR O PROGRAMA! \n");
                printf("SAINDO... \n");
                break;

            default:
                printf("\nNumero errado! Tente novamente! \n\n");
        }
        
    } while(escolha != 3);

    /* Passando os dados para a função bublleSort.
    bubbleSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("Ordenado com Bubble Sort ");
    */

    clock_t inicio = clock();
       
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.50f\n", tempo);
    
    return 0;
}