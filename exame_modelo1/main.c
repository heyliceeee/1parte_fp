#include <stdio.h>

#define NUM_CIDADES 6
#define TAM_TRAJETO 6



/**
 * dado um trajeto entre as cidades, verifica se o trajeto e possivel
 * @param trajeto array
 * @param cidades matriz
 * @return 1 se o trajeto for possivel, caso contrario 0
 */
int verificaTrajeto(int trajeto[TAM_TRAJETO], int cidades[NUM_CIDADES][NUM_CIDADES])
{
    for(int i=0; i < TAM_TRAJETO-1; i++) //percorrer trajetos
    {
        if(cidades[trajeto[i]][trajeto[i+1]] == 0) //verificar se na cidade atual e da seguinte ha conexao
        {
            return 0;
        }
    }

    return 1;
}



int main()
{
    int cidades[NUM_CIDADES][NUM_CIDADES] = {
            {1, 0, 1, 0, 0, 1},
            {0, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1},
            {0, 1, 0, 1, 1, 0},
            {0, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1}
    };
    int trajeto[TAM_TRAJETO] = {0, 2, 1, 3, 4, 5};


    printf("START\n");

    printf("trajeto possivel: %d\n", verificaTrajeto(trajeto, cidades));

    printf("\nEND\n\n");
    return 0;
}
