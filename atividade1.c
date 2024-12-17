#include <stdio.h>

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
    int i, n;
    float notas;
    
    // Contadores de Conceitos
    int somaConceitoA = 0, somaConceitoB = 0, somaConceitoC = 0, somaConceitoD = 0, somaConceitoE = 0;

    for (i = 0; i < 10; i++)
    {    
        do{
            printf("Digite a nota do %do aluno: ", i + 1);
            scanf("%f", &notas);
            if(notas > 10 || notas < 0)
            {
                printf("Nota invalida!\n");
                printf("Por favor, digite uma nota entre 0 e 10\n");
            }
        }while(notas > 10 || notas < 0);    
        
        if (notas >= 9.0)
            somaConceitoA ++; // Contador do Conceito A
        else if (notas >= 8.0)
            somaConceitoB ++; // Contador do Conceito B
        else if (notas >= 6.1)
            somaConceitoC ++; // Contador do Conceito C
        else if (notas >= 4.1)
            somaConceitoD ++; // Contador do Conceito D
        else if (notas <= 4.0)
            somaConceitoE ++; // Contador do Conceito E
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
    
    return 0;
}