#include <stdio.h>
#include <stdlib.h>
#include <trigame_administracao.h>
#include <trigame_jogo.h>

void listar(filaUtilizadores f, float quantidade)
{
    if(f == NULL)
        return;

    listar(f->proximoJogador,quantidade+1);
}

int main()
{
    filaUtilizadores fU;
    fU = lerUtilizadores("users.db");
    listar(fU,0);

    return 0;
}
