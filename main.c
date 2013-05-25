#include <stdio.h>
#include <stdlib.h>
#include <trigame_administracao.h>
#include <trigame_jogo.h>



int main()
{
    //filas
    filaUtilizadores fU;
    filaPerguntas fP;

    //preencher filas
    if(fU = lerUtilizadores("users.db")) printf("Utilizadores - OK\n");
    if(fP = lerPergunta("perguntas.db")) printf("Perguntas - OK\n");

    return 0;
}
