#ifndef TRIGAME_ADMINISTRACAO_H_INCLUDED
#define TRIGAME_ADMINISTRACAO_H_INCLUDED



#endif // TRIGAME_ADMINISTRACAO_H_INCLUDED


//estrutura de dados para as perguntas e respostas
typedef struct{
    int categoria;
    char pergunta[200],resposta[4][200];
} pergunta;


//estrura de dados para os utilizadores
typedef struct{
    char username[100];
    char password[100];
    int admin;
    int respostas_certas;
    int respostas_erradas;
} utilizador;



//criar novo utilizador
utilizador criarUtilizador(char nome[], char password[], int admin)
{
    utilizador novoUtilizador;

    strcpy(novoUtilizador.username,nome);
    strcpy(novoUtilizador.password,password);
    novoUtilizador.admin = admin;

    return novoUtilizador;
}

//alterar utilizador
utilizador alterarUtilizador(utilizador utilizadorAalterar)
{
    utilizador utilizadorAlterado;

    utilizadorAlterado = utilizadorAalterar;

    switch(utilizadorAalterar.admin)
    {
        case 0:
            utilizadorAlterado.admin = 1;
        case 1:
            utilizadorAlterado.admin = 0;
    }

    return utilizadorAlterado;
}


//criar nova pergunta
pergunta criarPergunta(int categoria, char npergunta[], char respostaCerta[], char resposta1[], char resposta2[], char resposta3[])
{
    pergunta novaPergunta;

    novaPergunta.categoria = categoria;
    strcpy(novaPergunta.pergunta,npergunta);
    strcpy(novaPergunta.resposta[0],respostaCerta);
    strcpy(novaPergunta.resposta[1],resposta1);
    strcpy(novaPergunta.resposta[2],resposta2);
    strcpy(novaPergunta.resposta[3],resposta3);

    return novaPergunta;
}
