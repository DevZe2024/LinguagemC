#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Montar um algoritmo usando como entrada 10 notas 
dos alunos de uma sala - quero saber quantos se encontram em cada conceito e também 
a média da classe.
Conceito Faixa de notas
A 10.0 - 9.0
B 8.9 - 8.0
C 7.9 - 6.1
D 6.0 - 4.1
E 4.0 - 0.0
Fazer o algoritmo com uso com contador e acumulado
*/

int main(void)
{
   // Variáveis do Projeto
    int menu, i, n;
    float notas[10], somaNotas = 0, mediaSala;
    char nomeCompleto[10][100];
    char primeiroNome[10][100]; // Para armazenar apenas o primeiro nome
    char programa;
    // Contadores de Conceitos
    int somaConceitoA = 0, somaConceitoB = 0, somaConceitoC = 0, somaConceitoD = 0, somaConceitoE = 0;

    printf("Ola !  \nVamos, verificar quantos alunos se encontram em cada conceito de media.\nVamos colocar o nome de todosos alunos, e suas respectivas notas\n apos fazer isso, vamos mostrar quantos se encontram em cada conceito.\nVamos iniciar ? Iremos verificar as notas de quantos alunos? \nLembrando que o limite maximo de alunos sao 10\n");

    // Verificação de entrada para a quantidade de alunos
    do 
    {
        printf("\nPor favor digite a quantidade de alunos a serem verificados: ");
        scanf(" %d", &n);
        getchar();

        if (n > 10 || n <= 0) 
        {
            printf("Opcao invalida! \nLimite maximo ultrapassado. \nPor favor coloque uma entrada valida para continuarmos! \nDigite um valor entre 1 e 10.\n");
        } 
        else
        {
            break;
        }

    } while (1);

    for ( i = 0; i < n; i++)
    {
        
        printf("\n\nPor favor, coloque o nome do %d aluno\n", i + 1);
        fgets(nomeCompleto[i], 100, stdin);
        
        // Remover o '\n' do final da string, se existir
        size_t len = strlen(nomeCompleto[i]);
        if (len > 0 && nomeCompleto[i][len - 1] == '\n') {
            nomeCompleto[i][len - 1] = '\0';
        }

        /*
        Explicações:

            size_t len = strlen(nome[i]);
            O que faz?
            * Calcula o comprimento (número de caracteres) da string armazenada em nome[i] e armazena esse valor na variável len.
            * strlen(nome[i]) retorna o número de caracteres antes do caractere nulo (\0) que marca o final da string.
            * size_t é o tipo de dado retornado por strlen, representando um valor sem sinal.

            if (len > 0 && nome[i][len - 1] == '\n')
            O que faz?
            Verifica se:
            * O comprimento da string (len) é maior que zero (ou seja, a string não está vazia).
            * O último caractere da string (nome[i][len - 1]) é um caractere de nova linha ('\n').
            O índice len - 1 acessa o último caractere da string (porque os índices começam em 0).

            nome[i][len - 1] = '\0';
            O que faz?
            * Se o último caractere for \n, ele é substituído pelo caractere nulo ('\0'). Isso marca o final da string, efetivamente "removendo" o \n.

        */

       // Extrair o primeiro nome
        char *token = strtok(nomeCompleto[i], " "); // Divide a string no primeiro espaço
        if (token != NULL) 
        {
            strcpy(primeiroNome[i], token); // Copia o primeiro nome para outra variável
        } 
        else 
        {
            strcpy(primeiroNome[i], nomeCompleto[i]); // Caso não tenha espaço, usa o nome inteiro
        }

        printf("\nAgora coloque a nota do %s (0 a 10): ", primeiroNome[i]);
        
        //controle de erro para notas, caso seja maior que 10 ou menor que 0, a nota é inválida
        do{
            scanf("%f", &notas[i]);
            if(notas[i] > 10 || notas[i] < 0){
                printf("Nota invalida!\n");
                printf("Por favor, digite uma nota entre 0 e 10\n");
            }
            else
            getchar();
        }while(notas[i] > 10 || notas[i] < 0);
        
        if (notas[i] >= 9.0)
            somaConceitoA ++; // Contador do Conceito A
        else if (notas[i] >= 8.0)
            somaConceitoB ++; // Contador do Conceito B
        else if (notas[i] >= 6.1)
            somaConceitoC ++; // Contador do Conceito C
        else if (notas[i] >= 4.1)
            somaConceitoD ++; // Contador do Conceito D
        else if (notas[i] <= 4.0)
            somaConceitoE ++; // Contador do Conceito E
        somaNotas = somaNotas + notas[i];
    }
    printf("\nSegue abaixo o quantitativo dos conceitos\n\n");
    printf("\n*******************************************\n");
    printf("*             RESULTADO FINAL            *\n");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*      %d Alunos ficaram no conceito A     *\n", somaConceitoA);
    printf("*      %d Alunos ficaram no conceito B     *\n", somaConceitoB);
    printf("*      %d Alunos ficaram no conceito C     *\n", somaConceitoC);
    printf("*      %d Alunos ficaram no conceito D     *\n", somaConceitoD);
    printf("*      %d Alunos ficaram no conceito E     *\n", somaConceitoE);
    printf("*                                         *\n");
    printf("*******************************************\n\n");
    
    /*
    Para melhorias após o programa ser concluído iniciar um menu interativo onde no menu terá opções de:
        * Mostrar os alunos que ficaram em cada conceito a definir pelo usuario:
            - Caso o usuario queira mostrar os conceitos e abaixo de cada conceito os respectivos alunos
            - Caso o usuario queira mostrar os alunos e seus respectivos conceitos
        * Mostrar a média da sala/ turma
        * Fazer Ranking de melhores alunos
        * Mostrar alunos por ordem alfabética
        * Exportar todo o conteúdo "útil" para um arquivo de texto txt
        * 
    */

    // menu interativo
    do 
    {
        printf("\nDeseja ir para o nosso menu interativo? (s/n): ");
        scanf(" %c", &programa);

        if (programa == 'n' || programa == 'N') {
            printf("Encerrando o programa...\n");
            return 0;
        } 
        else if (programa == 's' || programa == 'S') {
            printf("Entrando no menu interativo...\n");
            break;
        } 
        else {
            printf("Opcao invalida. Digite 's' para sim ou 'n' para nao.\n");
        }
    } while (1);

    do
    {
        printf("************************************************\n");
        printf("*          MENU DE INTERATIVIDADE              *\n");
        printf("************************************************\n");
        printf("*  PARA SAIR                  -->   DIGITE 0   *\n");
        printf("*  PARA SABER A MEDIA DA SALA -->   DIGITE 1   *\n");
        printf("*  MOSTRAR OS ALUNOS          -->   DIGITE 2   *\n");
        printf("*  MOSTRAR RANKING DOS ALUNOS -->   DIGITE 3   *\n");
        printf("*  EXPORTAR CONTEUDO          -->   DIGITE 4   *\n");
        printf("************************************************\n");
    
        switch (menu)
            {
            case 0:
                return 0;
                
            case 1 :
                function();
                break;
            
            case 2:
                functino();
                break;

            default:
                printf("Entrada Inválida!\n");
                printf("Por favor, utilize as entradas de acesso conforme pedido no meu interativo\n");
                printf("Caso queira sair do menu, digite 0\n");
                break;
            }
    } while(1);

    return 0;
}