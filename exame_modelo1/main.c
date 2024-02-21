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
        printf("existe ligacao entre a cidade %d e a cidade %d ? (0 - nao | 1 - sim):  ", cidade1, cidade2);
        scanf("%d", &valor);

    } while (valor != 0 && valor != 1);

    return valor;
}


/**
 * verifica se a matriz e simetrica
 * @param cidades
 * @return 1 se for, caso contrario 0
 */
int verificaSimetria(int cidades[NUM_CIDADES][NUM_CIDADES])
{
    for(int i=0; i < NUM_CIDADES; i++) //percorrer linhas
    {
        for(int j=0; j < NUM_CIDADES; j++) //percorrer colunas
        {
            if(cidades[i][j] != cidades[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}



/**
 * verifica se no trajeto tem cidades validas e se nao tem cidades repetidas
 * @param trajeto
 * @return 1 se o trajeto tem cidades validas e se nao tem cidades repetidas, caso contrario 0
 */
int validaTrajeto(int trajeto[TAM_TRAJETO])
{
    for(int i=0; i < TAM_TRAJETO; i++)
    {
        if(trajeto[i] < 0 || trajeto[i] >= NUM_CIDADES) //cidade invalida
        {
            return 0;
        }
    }


    for(int i=0; i < TAM_TRAJETO-1; i++)
    {
        if(trajeto[i] == trajeto[i+1])//trajeto invalido
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
    int cidade1 = 1, cidade2 = 2;


    printf("START\n");


    printf("trajeto possivel: %d\n\n", verificaTrajeto(trajeto, cidades));


    int conexao = obtemConexaoEntreCidades(cidade1, cidade2);
    printf("conexao entre cidade %d e cidade %d: %d\n\n", cidade1, cidade2, conexao);


    printf("simetria: %d\n\n", verificaSimetria(cidades));


    printf("trajeto valido: %d\n\n", validaTrajeto(trajeto));


    printf("\nEND\n\n");
    return 0;
}
