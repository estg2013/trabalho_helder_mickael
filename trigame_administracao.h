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





