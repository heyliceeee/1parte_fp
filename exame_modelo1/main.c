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



/**
 *
 * @param cidade1
 * @param cidade2
 * @return
 */
int obtemConexaoEntreCidades(int cidade1, int cidade2)
{
    int valor;

    do
    {
        printf("existe ligacao entre a cidade %d e a cidade %d ? (0 - nao | 1 - sim): \n", cidade1, cidade2);
        scanf("%d", &valor);

    } while (valor != 0 && valor != 1);

    return valor;
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
    int cidade1 = 1, cidade2 = 2;


    printf("START\n");


    printf("trajeto possivel: %d\n", verificaTrajeto(trajeto, cidades));


    int conexao = obtemConexaoEntreCidades(cidade1, cidade2);
    printf("conexao entre cidade %d e cidade %d: %d\n", cidade1, cidade2, conexao);


    printf("\nEND\n\n");
    return 0;
}
