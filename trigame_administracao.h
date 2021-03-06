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
    int seleccionado;
    int jogoCertas;
    int jogoErradas;
} utilizador;

typedef struct{
    int x;
    int y;
    int pos;
}posicoes;



/************************** UTILIZADORES *******************************/

//fila de jogadores
typedef struct lUtilizadores
{
    utilizador jogador;
    posicoes pos;
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

    //verifica se a linha esta em condicoes de ser lida
    if(c != 4)
    {
        printf("ERRO - Ficheiro de utilizadores corrompido!\n");
        exit(1);
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

//inicializar ficheiro com os utilizadores
void inicializarUtilizadores(char ficheiro[])
{
    int i;
    FILE *fp;

    fp = fopen(ficheiro,"w");
        for(i=0;i<1;i++)
        {
            if(i>0) fprintf(fp,"\n");
            fprintf(fp,"admin,admin,%i,%i,%i",1,0,0); //cria o admin se nao existir
        }
    fclose(fp);
}

/*
* um morcego
*
*                      _..-'(                       )`-.._
                   ./'. '||\\.       (\_/)       .//||` .`\.
                ./'.|'.'||||\\|..    )O O(    ..|//||||`.`|.`\.
             ./'..|'.|| |||||\`````` '`"'` ''''''/||||| ||.`|..`\.
           ./'.||'.|||| ||||||||||||.     .|||||||||||| |||||.`||.`\.
          /'|||'.|||||| ||||||||||||{     }|||||||||||| ||||||.`|||`\
         '.|||'.||||||| ||||||||||||{     }|||||||||||| |||||||.`|||.`
        '.||| ||||||||| |/'   ``\||``     ''||/''   `\| ||||||||| |||.`
        |/' \./'     `\./         \!|\   /|!/         \./'     `\./ `\|
        V    V         V          }' `\ /' `{          V         V    V
        `    `         `               V               '         '    '

*/

//ler os utilizadores para a fila de utilizadores
filaUtilizadores lerUtilizadores(char ficheiro[])
{
    char linha[200];
    int i = 0;
    filaUtilizadores l,c, cInvertida, cL;
    utilizador fUtilizador; //utilizador para ler a linha do ficheiro

    l = NULL;
    cL = NULL;

    FILE *fp; //apontador para o ficheiro
    fp = fopen(ficheiro,"r"); //abrir o ficheiro em de leitura texto

    if(!fp) //se o ficheiro de utilizadores existir
    {
        fclose(fp); //TODO: verificar se e necessario fechar o ficheiro
        inicializarUtilizadores(ficheiro);
    }

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


    //FIX: inverter o que � lido do ficheiro
    while(c != NULL)
    {
        cInvertida = malloc(sizeof(listaUtilizadores));
        cInvertida->jogador = c->jogador;
        cInvertida->proximoJogador = cL;
        cL = cInvertida;
        c = c->proximoJogador;
    }

    return cInvertida;
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


//apagar utilizador
/*
* Operacoes: 1 -> Apaga o jogador, 2 -> Altera a flag de administrador
*
*
*/
void modificarUtilizadores(filaUtilizadores fU, char nUtilizador[], int operacao)
{
    FILE *fp;
    char linha[300];
    int contadorU = 0, admin;

    fp = fopen("users.db","w"); //ficheiro de utilizadores para escrita

    //gravar os utilizadores excepto o utilizador a apagar
    while(fU != NULL)
    {
        //verifica se e o jogador a apagar
        if(strcmp(fU->jogador.username,nUtilizador) == 0)
        {
            //TODO: backup jogador apagado
            switch(operacao)
            {
            case 1:
                    //apaga o jogador
                break;
            case 2:
                    //alterar para admin
                    if(contadorU > 0) fprintf(fp,"\n");
                    if(fU->jogador.admin == 0)
                    {
                        admin = 1;
                    }else{
                        admin = 0;
                    }
                    fprintf(fp,"%s,%s,%i,%i,%i",fU->jogador.username,fU->jogador.password,admin,fU->jogador.respostas_certas,fU->jogador.respostas_erradas);
                    contadorU++;
                break;
            }
        }else{
            //guarda o jogador novamente no ficheiro
            if(contadorU > 0) fprintf(fp,"\n");
            fprintf(fp,"%s,%s,%i,%i,%i",fU->jogador.username,fU->jogador.password,fU->jogador.admin,fU->jogador.respostas_certas,fU->jogador.respostas_erradas);
            contadorU++;
        }
        fU = fU->proximoJogador;
    }
    fclose(fp);
}








/********************************* PERGUNTAS *******************************/
//struct fila perguntas
typedef struct lPerguntas{
    pergunta perg;
    struct lPerguntas *proximaPergunta;
} listaPerguntas;

typedef listaPerguntas* filaPerguntas;

//parse da linha com a pergunta
pergunta parsePergunta(char linha[], char separador)
{
    pergunta p;
    int i, j, c = 0, separadores[5], tamanhoLinha, posicaoRespostas;

    tamanhoLinha = strlen(linha);

    for(i=0;i<tamanhoLinha;i++) //conta o numero de separadores na linha
    {
        if(linha[i]==separador)
        {
            separadores[c] = i;
            c++;
        }
    }

    if(c != 5) //ficheiro de perguntas corrompido
    {
        printf("ERRO - Ficheiro de perguntas e respostas corrompido!\n");
        exit(1);
    }

    //categoria da pergunta
    for(i=0;i<separadores[0];i++)
    {
        p.categoria = linha[i] - '0';
    }

    //pergunta
    c = 0;
    for(i=separadores[0]+1;i<separadores[1];i++)
    {
        p.pergunta[c] = linha[i];
        c++;
    }
    p.pergunta[c] = '\0';


    //respostas
    for(j=0;j<4;j++)
    {
        c = 0;

        //ulima posicao
        if(j == 3)
        {
            posicaoRespostas = tamanhoLinha-1;
        }else{
            posicaoRespostas = separadores[2 + j]-1;
        }

        for(i=separadores[1+j];i<posicaoRespostas;i++)
        {
            p.resposta[0+j][c] = linha[i+1];
            c++;
        }
        p.resposta[0+j][c] = '\0';
    }

    return p;
}

//funcao para ler as perguntas de um ficheiro e coloca-las numa fila
filaPerguntas lerPergunta(char ficheiroPerguntas[])
{
    FILE *fp;
    filaPerguntas l,c, cInvertida, cL;
    char linha[300];

    pergunta fPergunta;


    //inicializar apontador para o inicio da fila
    l = NULL;

    //abrir o ficheiro de perguntas e cria-lo se nao existir
    fp = fopen(ficheiroPerguntas,"r");

    if(!fp) //se o ficheiro nao existir cria um novo
    {
        fclose(fp);
        fp = fopen(ficheiroPerguntas,"w");
        fprintf(fp,"1;Quem foi o primeiro rei de Portugal?;D. Afonso Henriques;Helder Postiga;Pinto da Costa;Barack Obama"); //escrever uma pergunta no ficheiro
        fprintf(fp,"\n2;Simbolo quimico do Oxigenio?;O;Ni;K;Po"); //escrever uma pergunta no ficheiro
        fclose(fp);
    }

    fp = fopen(ficheiroPerguntas,"r");

    while(fgets(linha,300,fp)) //ler o ficheiro linha a linha ate ao fim
    {
        if(strlen(linha) > 2)
            {
                fPergunta = parsePergunta(linha,';'); //dividir a linha numa estrutura para perguntas
                c = malloc(sizeof(listaPerguntas));
                c->perg = fPergunta;
                c->proximaPergunta = l;
                l = c;
            }
    }

    fclose(fp);

    //FIX -> inverter a fila
    cL = NULL;

    while(c != NULL)
    {
        cInvertida = malloc(sizeof(listaPerguntas));
        cInvertida->perg = c->perg;
        cInvertida->proximaPergunta = cL;
        cL = cInvertida;
        c = c->proximaPergunta;
    }

    return cInvertida;
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


//modificar perguntas
/*
*   1 - apaga pergunta
*
*
*/

void modificarPerguntas(filaPerguntas fP, char pergunta[], int operacao)
{
    FILE *fp;
    fp = fopen("perguntas.db","w");
    int contP = 0;

    while(fP != NULL)
        {
            switch(operacao)
            {
            case 1:
                if(strcmp(pergunta,fP->perg.pergunta) == 0) //compara a pergunta
                {
                    //apaga a pergunta
                }else{
                    //escreve a pergunta para o ficheiro
                    if(contP > 0) fprintf(fp,"\n");
                    fprintf(fp,"%i;%s;%s;%s;%s;%s",fP->perg.categoria,fP->perg.pergunta,fP->perg.resposta[0],fP->perg.resposta[1],fP->perg.resposta[2],fP->perg.resposta[3]);
                    contP++;
                }
                break;
            default:

                break;
            }
            fP = fP->proximaPergunta;
        }
    fclose(fp);
}
