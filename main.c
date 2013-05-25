#include <stdio.h>
#include <stdlib.h>
#include <trigame_administracao.h>
#include <trigame_jogo.h>

void listar(filaUtilizadores f)
{
    if(f == NULL)
        return;
    printf("username: %s\npassword: %s",f->jogador.username,f->jogador.password);
    listar(f->proximoJogador);
}

int main()
{
    filaUtilizadores fU;
    fU = lerUtilizadores("users.db");
    listar(fU);

    return 0;
}
