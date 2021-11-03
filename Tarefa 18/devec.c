/*
devec.c:42:15: missed: not vectorized: multiple exits.
devec.c:31:11: missed: not vectorized: number of iterations cannot be computed.
devec.c:20:18: missed: not vectorized: control flow in loop.
devec.c:10:19: missed: not vectorized: latch block not empty.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int a[2048], b[2048], c[2048];
    int i;

    // Ter um rand() no numero de iteracoes faz com que os acessos nao sejam sequenciais e em ordem
    for (i = 0; i < rand() % 2048; i++)
    {
        b[i] = 0;
        c[i] = 0;
    }

    for (i = 0; i < 2048; i++)
    {
        a[i] = b[i] + c[i];

        // Esse break causa um dos problemas, pois ele quebra a linearidade do loop
        if (i == rand() % 20)
            break;
    }

    i = 0;

    while (i < 2048)
    {
        a[i] = b[i] + c[i];

        // Essa atribuicao quebra a vetorização, pois é impossível para o compilador prever exatamente
        // quantas iterações vai ter no loop
        i = rand() % 2048;

        if(i == 3)
            break;
    }

    int aux = rand() % i;

    for(i = 0; i < 2048; i++)
    {
        a[i] = b[i] + c[i];

        // Essas atribuicoes interferem com o fluxo do loop e impedem a previsão do numero de iterações
        i = aux;
        aux = rand() % i;
    }
    
    return 0;
}