#ifndef TRIGAME_ADMINISTRACAO_H_INCLUDED
#define TRIGAME_ADMINISTRACAO_H_INCLUDED



#endif // TRIGAME_ADMINISTRACAO_H_INCLUDED


//estrutura de dados para as perguntas e respostas
typedef struct
{
    int categoria;
    char pergunta[200],resposta[4][200];
} pergunta;


//estrura de dados para os utilizadores
typedef struct
{
    char username[100];
    char password[100];
    int admin;
    int respostas_certas;
    int respostas_erradas;
} utilizador;


/************************** UTILIZADORES *******************************/

//fila de jogadores
typedef struct lUtilizadores
{
    utilizador jogador;
    struct lUtilizadores *proximoJogador;
} listaUtilizadores;

typedef listaUtilizadores* filaUtilizadores;


//parse da linha lida do ficheiro de utilizadores
//WIP
utilizador parseUtilizador(char utili[], char separador)
{
    utilizador u;
    int tamanhoString,separadores[4];
    int i,c=0;
    char charTemp[5];

    tamanhoString = strlen(utili);

    for(i=0; i<tamanhoString; i++) //obter posicao dos separadores na string
    {
        if(utili[i] == separador)
        {
            separadores[c] = i;
            c++;
        }
    }

    //username
    for(i=0; i<separadores[0]; i++)
    {
        u.username[i] = utili[i];
    }
    u.username[i]='\0';

    //password
    c=0;
    for(i=(separadores[0]+1); i<separadores[1]; i++)
    {
        u.password[c] = utili[i];
        c++;
    }
    u.password[c] = '\0';

    //admin
    u.admin =utili[separadores[1]+1] - '0';

    //jogos ganhos
    c=0;
    for(i=(separadores[2]+1); i<separadores[3]; i++)
    {
        charTemp[c] = utili[i];
        c++;
    }
    u.respostas_certas = atoi(charTemp); //converter string de respostas certas para inteiro

    //jogos perdidos
    c = 0;
    for(i=(separadores[3]+1); i<tamanhoString; i++)
    {
        charTemp[c] = utili[i];
        c++;
    }
    u.respostas_erradas = atoi(charTemp); //converter as respostas erradas para inteiro

    return u;
}





//ler os utilizadores para a fila de utilizadores
filaUtilizadores lerUtilizadores(char ficheiro[])
{
    char linha[200];
    int i = 0;
    filaUtilizadores l,c;
    utilizador fUtilizador; //utilizador para ler a linha do ficheiro

    l = NULL;

    FILE *fp; //apontador para o ficheiro
    fp = fopen(ficheiro,"r"); //abrir o ficheiro em de leitura texto

    if(!fp) //se o ficheiro de utilizadores existir
    {
        fp = fopen(ficheiro,"w");
        for(i=0;i<100;i++)
        {
            if(i>0) fprintf(fp,"\n");
            fprintf(fp,"utilizador-%i,admin,%i,%i,%i",rand(),(rand()%2),rand(),rand()); //cria o admin se nao existir
        }
    }
    fclose(fp);

    fp = fopen(ficheiro,"r"); //abrir o ficheiro em de leitura texto

    while(fgets(linha,200,fp)) //le ate ao fim do ficheiro
    {
        if(strlen(linha) > 0)
        {
            fUtilizador = parseUtilizador(linha,',');

            c = malloc(sizeof(listaUtilizadores));
            c->jogador = fUtilizador;
            c->proximoJogador = l;
            l = c;
        }
    }

    fclose(fp);

    return c;
}

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

    if(utilizadorAalterar.admin == 1)
    {
        utilizadorAlterado.admin = 0;
    }
    else
    {
        utilizadorAlterado.admin = 1;
    }

    return utilizadorAlterado;
}

/********************************* PERGUNTAS *******************************/
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
