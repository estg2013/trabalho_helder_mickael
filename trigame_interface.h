#ifndef TRIGAME_INTERFACE_H_INCLUDED
#define TRIGAME_INTERFACE_H_INCLUDED
#define BRANCH "TRIGAME ALPHA - BRANCH: helder_interface"



#endif // TRIGAME_INTERFACE_H_INCLUDED

typedef struct
{
    SDL_Surface *fundo;
    SDL_Surface *fundo2;
    SDL_Surface *btNovoJogo;
    SDL_Surface *btOpcoes;
    SDL_Surface *btSair;
    SDL_Surface *btNovoJogob;
    SDL_Surface *btOpcoesb;
    SDL_Surface *btSairb;
    SDL_Surface *setaCima;
    SDL_Surface *setaBaixo;
    SDL_Surface *btMais;
    SDL_Surface *frmNovoUtilizador;
    Mix_Music *musica_menu;
    TTF_Font *font;
}botoesMenu;

botoesMenu btMenu;

typedef struct{
    char texto[200];
    int x;
    int y;
} textoEcra;

//procedimento para carregar as imagens para a memoria
void carregarRecursos()
{
    //imagens do menu inicial
    btMenu.fundo = SDL_LoadBMP("img/splash.bmp");
    btMenu.fundo2 = SDL_LoadBMP("img/fundo2.bmp");
    btMenu.btNovoJogo = SDL_LoadBMP("img/novojogo.bmp");
    btMenu.btOpcoes = SDL_LoadBMP("img/opcoes.bmp");
    btMenu.btSair = SDL_LoadBMP("img/sair.bmp");
    btMenu.btNovoJogob = SDL_LoadBMP("img/novojogob.bmp");
    btMenu.btOpcoesb = SDL_LoadBMP("img/opcoesb.bmp");
    btMenu.btSairb = SDL_LoadBMP("img/sairb.bmp");
    btMenu.setaCima = SDL_LoadBMP("img/seta_cima.bmp");
    btMenu.setaBaixo = SDL_LoadBMP("img/seta_baixo.bmp");
    btMenu.btMais = SDL_LoadBMP("img/mais.bmp");
    btMenu.frmNovoUtilizador = SDL_LoadBMP("img/frmNovoUtilizador.bmp");
    //som
    btMenu.musica_menu = Mix_LoadMUS("music/botoes.wav");
    //font
    btMenu.font = TTF_OpenFont("font/font1.ttf",33);
}



/*
* menu inicial
*/
void menu(SDL_Surface* ecra)
{
    char texto[100];
    int ratoX, ratoY,but1 = 0, but2 = 0, but3 = 0;

    SDL_Event evento;
    SDL_Rect rect = {0,0,100,100};
    SDL_Surface *msg = NULL;

    SDL_Color cor1 = {0,0,0};

    msg = TTF_RenderText_Solid(btMenu.font,"Versao Alpha",cor1);

    while(1)
    {
        SDL_PollEvent(&evento);
        SDL_BlitSurface(btMenu.fundo,NULL,ecra,NULL);
        //botao novo jogo
        rect.x = 350;
        rect.y = 300;
        SDL_BlitSurface(btMenu.btNovoJogo,NULL,ecra,&rect);
        //botao opcoes
        rect.x = 350;
        rect.y = 370;
        SDL_BlitSurface(btMenu.btOpcoes,NULL,ecra,&rect);
        //botao sair
        rect.x = 350;
        rect.y = 440;
        SDL_BlitSurface(btMenu.btSair,NULL,ecra,&rect);

        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;

            //botao novo jogo
            if(ratoX > 351 && ratoX < 661 && ratoY > 302 && ratoY < 373)
            {
                //botao novo jogo preto
                    rect.x = 350;
                    rect.y = 300;
                    SDL_BlitSurface(btMenu.btNovoJogob,NULL,ecra,&rect);
                    if(but1 == 0)
                        Mix_PlayMusic(btMenu.musica_menu,1);
                        but1 = 1;
                        but2 = but3 = 0;
            }else if(ratoX > 351 && ratoX < 661 && ratoY > 374 && ratoY < 444)
            {
                //botao opcoes preto
                    rect.x = 350;
                    rect.y = 370;
                    SDL_BlitSurface(btMenu.btOpcoesb,NULL,ecra,&rect);
                    if(but2 == 0)
                        Mix_PlayMusic(btMenu.musica_menu,1);
                    but2 = 1;
                    but1 = but3 = 0;
            }else if(ratoX > 351 && ratoX < 661 && ratoY > 444 && ratoY < 515)
            {
                //botao sair preto
                    rect.x = 350;
                    rect.y = 440;
                    SDL_BlitSurface(btMenu.btSairb,NULL,ecra,&rect);
                    if(but3 == 0)
                        Mix_PlayMusic(btMenu.musica_menu,1);
                    but3 = 1;
                    but2 = but1 = 0;
            }else{
                but1 = 0;
                but2 = 0;
                but3 = 0;
            }
        }


        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;

            //clique para as opcoes
            if(ratoX > 351 && ratoX < 661 && ratoY > 374 && ratoY < 444)
                menuOpcoes(ecra,cor1);

            //clique para sair
            if(ratoX > 351 && ratoX < 661 && ratoY > 444 && ratoY < 515)
                exit(1);
        }


        if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> sair do programa
            if(evento.key.keysym.sym == SDLK_ESCAPE)
                exit(1);
        }

        //versao do programa
        rect.x = 735;
        rect.y = 713;
        SDL_BlitSurface(msg,NULL,ecra,&rect);

        SDL_Flip(ecra);
        SDL_Delay(20);
    }
}

/*
* menu com as opcoes
*/
void menuOpcoes(SDL_Surface* ecra, SDL_Color cor1)
{

    SDL_BlitSurface(btMenu.fundo,NULL,ecra,NULL); //aplicar o fundo

    //estruturas
    char texto[100];
    int ratoX, ratoY;

    SDL_Event evento;
    SDL_Rect rect = {0,0,100,100};
    SDL_Surface *butUtilizadores, *butPerguntas, *butVoltar;

    butUtilizadores = TTF_RenderText_Solid(btMenu.font,"Utilizadores",cor1);
    butPerguntas = TTF_RenderText_Solid(btMenu.font,"Perguntas",cor1);
    butVoltar = TTF_RenderText_Solid(btMenu.font,"< Voltar",cor1);


    rect.x = 350;
    rect.y = 300;
    SDL_BlitSurface(butUtilizadores,NULL,ecra,&rect);

    rect.x = 370;
    rect.y = 370;
    SDL_BlitSurface(butPerguntas,NULL,ecra,&rect);

    rect.x = 390;
    rect.y = 590;
    SDL_BlitSurface(butVoltar,NULL,ecra,&rect);


    while(1)
    {
        SDL_PollEvent(&evento);

        //movimento do rato
        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
        }

        //clique do rato
        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            if(ratoX > 347 && ratoX < 623 && ratoY > 297 && ratoY < 330)
            {
                //TODO: gestao de utilizadores
                gestaoUtilizadores(ecra);

            }else if(ratoX > 366 && ratoX < 588 && ratoY > 367 && ratoY < 401)
            {
                //TODO: gestao de perguntas
                gestaoPerguntas(ecra);

            }else if(ratoX > 386 && ratoX < 572 && ratoY > 587 && ratoY < 621)
            {
                menu(ecra);
            }

        }

        if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> sair do programa
            if(evento.key.keysym.sym == SDLK_ESCAPE)
                menu(ecra);
        }

        //actualizar o ecra
        SDL_Flip(ecra);
        SDL_Delay(50);
    }
}

/*
* menu de gestao dos utilizadores
*/
//inserir novo jogador
void inserirJogador(SDL_Surface *ecra)
{
    SDL_Event evento;
    SDL_Surface *texto = NULL;
    SDL_Color cor = {0,0,0};
    SDL_Rect rect = {0,0,100,100};
    SDL_Rect rectJanela;
    rectJanela.x = 200;
    rectJanela.y = 200;
    int inserirUsername = 1, ratoX, ratoY, tamtexto = 0,i;
    char txt[100],inp[100], inp_temp[100];
    char unic;

    sprintf(inp,"");

    SDL_BlitSurface(btMenu.frmNovoUtilizador,NULL,ecra,&rectJanela);

    rect.x = 364;
    rect.y = 234;

    while(1)
    {
        SDL_PollEvent(&evento);

        //teclado
        if(evento.type == SDL_KEYDOWN)
        {
            switch(evento.key.keysym.sym)
            {
            //enter
            case SDLK_RETURN:
                if(inserirUsername == 1)
                {
                    strcpy(inp_temp,inp);
                    sprintf(inp,"");
                    rect.y = 335;
                    inserirUsername = 0;
                }else if(inserirUsername == 0)
                {
                    FILE *fp;
                    fp = fopen("users.db","a+");
                    fprintf(fp,"\n%s,%s,%i,%i,%i",inp_temp,inp,0,0,0);
                    fclose(fp);
                    gestaoUtilizadores(ecra);
                }
                break;
            case SDLK_BACKSPACE:

                break;
            //escape
            case SDLK_ESCAPE:
                return;
                break;
            //letras
            default:
                unic = (char)evento.key.keysym.sym;
                sprintf(inp,"%s%c",inp,unic);
            }

            texto = TTF_RenderText_Solid(btMenu.font,inp,cor);
            SDL_BlitSurface(texto,NULL,ecra,&rect);
        }

        //movimento do rato
        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(txt,"%s X:%i Y:%i",BRANCH,ratoX,ratoY);
            SDL_WM_SetCaption(txt,NULL);
        }

        //clique do rato
        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            if(ratoX > 317 && ratoX < 585 && ratoY > 407 && ratoY < 477)
            {
                FILE *fp;
                fp = fopen("users.db","a+");
                fprintf(fp,"\n%s,%s,%i,%i,%i",inp_temp,inp,0,0,0);
                fclose(fp);
                gestaoUtilizadores(ecra);
            }
        }
        SDL_Delay(80);
        SDL_Flip(ecra);
    }
}


//menu com a lista de utilizadores carregados a partir do ficheiro
void gestaoUtilizadores(SDL_Surface *ecra)
{
    filaUtilizadores fU, fUinicial; //estrutura para a fila de utilizadores

    if(fU = lerUtilizadores("users.db")) //carregar o ficheiro de utilizadores para a fila
    {
        fUinicial = lerUtilizadores("users.db");
    }else{
        exit(1); //sair se ocorrer algum erro
    }

    SDL_Rect rect = {0,0,100,100};
    SDL_Rect nomes[10];
    SDL_Color cor = {0,0,0}; //cor para os utilizadores normais
    SDL_Color corAdmin = {0,255,50}; //cor para os admins
    SDL_Event evento;
    SDL_Surface *txtUtilizador = NULL;

    SDL_BlitSurface(btMenu.fundo2,NULL,ecra,NULL); //fundo
    rect.y = 30;
    rect.x = 500;
    txtUtilizador = TTF_RenderText_Solid(btMenu.font,"UTILIZADORES",cor);
    SDL_BlitSurface(txtUtilizador,NULL,ecra,&rect);



    int ratoX, ratoY, i = 0, posU = 0, contadorU, j; //posU -> posicao de topo na lista de utilizadores para saber se mostra ou nao a seta superior
    char texto[100], nUtilizadores[10][100];

    while(1)
    {
        SDL_PollEvent(&evento); //capturar evento

        SDL_BlitSurface(btMenu.fundo2,NULL,ecra,NULL); //fundo
        rect.y = 30;
        rect.x = 500;
        txtUtilizador = TTF_RenderText_Solid(btMenu.font,"UTILIZADORES",cor);
        SDL_BlitSurface(txtUtilizador,NULL,ecra,&rect);

        rect.x = 770;
        rect.y = 90;
        if(posU > 0) SDL_BlitSurface(btMenu.setaCima,NULL,ecra,&rect); //seta cima

        rect.y = 530;
        SDL_BlitSurface(btMenu.setaBaixo,NULL,ecra,&rect); //seta baixo

        rect.y = 350;
        rect.x = 820;
        SDL_BlitSurface(btMenu.btMais,NULL,ecra,&rect);//mais



        contadorU = 0;
        i=0;
        fU = fUinicial;
        //listar os utilizadores
        //TODO: resolver overflow da memoria por estar sempre a carregar o texto em cada ciclo para a RAM
        while(fU != NULL || i >= 10)
        {
                    if(contadorU >= posU && contadorU < (posU + 9) && i < 10)
                    {
                        nomes[i].x = 120;
                        nomes[i].y = (130)+(60*i);
                        strcpy(nUtilizadores[i],fU->jogador.username);
                        sprintf(texto,"%i - %s -> Nivel %i",(i + posU),nUtilizadores[i],fU->jogador.respostas_certas);
                        if(fU->jogador.admin == 1)
                        {
                            txtUtilizador = TTF_RenderText_Solid(btMenu.font,texto,corAdmin);
                        }else{
                            txtUtilizador = TTF_RenderText_Solid(btMenu.font,texto,cor);
                        }
                        SDL_BlitSurface(txtUtilizador,NULL,ecra,&nomes[i]);
                        i++;
                    }
                    contadorU++; //incrementa a contagem de utilizadores
                    fU = fU->proximoJogador;
        }


        //mostrar posicao do rato
        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(texto,"%s X:%i Y:%i",BRANCH,ratoX,ratoY);
        }


        //posicoes dos botoes ao clicar
        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            //verificar botao clicado
            switch(evento.button.button)
            {
            case SDL_BUTTON_LEFT: //botao esquerdo do rato
                if(ratoX > 12 && ratoX < 287 && ratoY > 10 && ratoY < 66) menuOpcoes(ecra,cor); //voltar ao menu anterior
                if(ratoX > 770 && ratoX < 992 && ratoY > 532 && ratoY < 750 && posU < (contadorU-1)) posU++; //seta para baixo
                if(ratoX > 770 && ratoX < 992 && ratoY > 94 && ratoY < 314 && posU > 0) posU--; //seta para cima
                if(ratoX > 836 && ratoX < 930 && ratoY > 362 && ratoY < 461) inserirJogador(ecra); //criar novo jogador
                //sprintf(texto,"Botao esquerdo clicado");
                if(ratoX > 120 && ratoX < 720) //limites horizontais para o clique do rato
                    {
                        for(j=0;j<9;j++)
                        {
                            //verifica qual o utilizador clicado
                            if(ratoY > nomes[j].y && ratoY < (nomes[j].y + 40))
                            {
                                //apaga o utilizador clicado
                                modificarUtilizadores(fUinicial,nUtilizadores[j],2); //altera o utilizador (2) -> alterar para admin
                                fUinicial = lerUtilizadores("users.db"); //reinicia as filas
                                posU = 0; //coloca a lista no inicio
                            }
                        }
                    }
                break;
            case SDL_BUTTON_RIGHT: //botao direito do rato
                    if(ratoX > 120 && ratoX < 720) //limites horizontais para o clique do rato
                    {
                        for(j=0;j<9;j++)
                        {
                            //verifica qual o utilizador clicado
                            if(ratoY > nomes[j].y && ratoY < (nomes[j].y + 40))
                            {
                                //apaga o utilizador clicado
                                modificarUtilizadores(fUinicial,nUtilizadores[j],1); //apaga o utilizador (1) -> apagar o utilizadador
                                fUinicial = lerUtilizadores("users.db"); //reinicia as filas
                                posU = 0; //coloca a lista no inicio
                            }
                        }
                    }

                //sprintf(texto,"Botao direito clicado");
                break;
            case SDL_BUTTON_MIDDLE: //botao do meio do rato -> definir o utilizador como admin

                break;
            case SDL_BUTTON_WHEELDOWN: //roda para baixo
                if(posU < (contadorU - 1))  posU++;
                break;
            case SDL_BUTTON_WHEELUP: //roda para cima
                if(posU > 0) posU--;
                break;
            }
        }

        //DEBUG -> altera o titulo da janela
        //SDL_WM_SetCaption(texto,NULL);

        if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> voltar para menu anterior
            if(evento.key.keysym.sym == SDLK_ESCAPE)
                 menuOpcoes(ecra,cor);
        }

        //actualizar ecra e esperar 80ms
        SDL_Flip(ecra);
        SDL_Delay(80);
    }
}



/*
*
*   gestao de perguntas
*
*/
void gestaoPerguntas(SDL_Surface *ecra)
{
    SDL_Event evento;
    SDL_Color cor = {0,0,0};

    SDL_Surface *texto;
    SDL_Rect rect;
    int i, posP = 0, posPerguntas[12];
    int ratoX, ratoY;
    int contadorP = 0;
    char perguntas[12][200];

    filaPerguntas fP, fPinicial; //apontadores para as filas

    fPinicial = lerPergunta("perguntas.db"); //carrega a fila das perguntas
    fP = fPinicial;

    //ciclo principal
    while(1)
    {
        SDL_BlitSurface(btMenu.fundo2,NULL,ecra,NULL); //fundo
        rect.y = 30;
        rect.x = 500;
        texto = TTF_RenderText_Solid(btMenu.font,"PERGUNTAS",cor); //titulo
        SDL_BlitSurface(texto,NULL,ecra,&rect);


        fP = fPinicial; //reiniciar a fila temporaria
        SDL_PollEvent(&evento); //obter evento

        rect.x = 770;
        rect.y = 90;
        if(posP > 0) SDL_BlitSurface(btMenu.setaCima,NULL,ecra,&rect); //seta cima

        rect.y = 530;
        SDL_BlitSurface(btMenu.setaBaixo,NULL,ecra,&rect); //seta baixo

        rect.y = 350;
        rect.x = 820;
        SDL_BlitSurface(btMenu.btMais,NULL,ecra,&rect);//mais


        rect.x = 25;
        rect.y = 25;
        i = 0;
        contadorP = 0;

       while(fP != NULL && i < 12) //correr a fila e escrever as perguntas
        {
            if(contadorP >= posP && contadorP < (posP+12))
                {
                    rect.y = rect.y + 50; //incrementa a posicao vertical do texto a mostrar
                    posPerguntas[i] = rect.y;
                    strcpy(perguntas[i],fP->perg.pergunta);
                    texto = TTF_RenderText_Solid(btMenu.font,perguntas[i],cor);
                    SDL_BlitSurface(texto,NULL,ecra,&rect);
                    i++;
                }
            fP = fP->proximaPergunta; //avanca a fila
            contadorP++;
        }


        //movimento do rato
        if(evento.type == SDL_MOUSEMOTION) //obter as coordenadas do rato
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
        }

        if(evento.type == SDL_MOUSEBUTTONDOWN) //clique do rato
        {
            switch(evento.button.button)
            {
            case SDL_BUTTON_LEFT: //botao esquerdo do rato
                if(ratoX > 12 && ratoX < 287 && ratoY > 10 && ratoY < 66) menuOpcoes(ecra,cor); //voltar ao menu anterior
                if(ratoX > 770 && ratoX < 992 && ratoY > 532 && ratoY < 750 && posP < (contadorP-1)) posP++; //seta para baixo
                if(ratoX > 770 && ratoX < 992 && ratoY > 94 && ratoY < 314 && posP > 0) posP--; //seta para cima
                if(ratoX > 836 && ratoX < 930 && ratoY > 362 && ratoY < 461) inserirPergunta(ecra); //criar nova pegunta
                break;
            case SDL_BUTTON_RIGHT: //botao direito do rato
                //apagar pergunta
                if(ratoX > 25 && ratoX < 750) //verificar qual a pergunta clicada
                {
                    for(i=0;i<12;i++)
                    {
                        if(ratoY > posPerguntas[i] && ratoY < (posPerguntas[i] + 40))
                        {
                            modificarPerguntas(fPinicial,perguntas[i],1); //apagar a pergunta no ficheiro
                            fPinicial = lerPergunta("perguntas.db"); //carregar novamente o ficheiro de perguntas
                        }
                    }
                }
                break;
            default:
                break;
            }
        }

        if(evento.type == SDL_KEYDOWN) //tecla para voltar ao menu inicial
        {
            menu(ecra);
        }
        SDL_Flip(ecra);
        SDL_Delay(80);
    }

    //volta ao menu inicial
    menu(ecra);
}

void inserirPergunta(SDL_Surface *ecra)
{
    char perg[200], respostas[4][200];
    int unic;
    int i;
    int pos = 1;
    int ratoX, ratoY;
    pergunta Pergunta;

    //inicializar estrutura
    Pergunta.categoria = 0;
    strcpy(Pergunta.pergunta,"");
    for(i=0;i<4;i++)
    {
        strcpy(Pergunta.resposta[i],"");
    }


    SDL_Color cor = {0,0,0};

    textoEcra txt[6];
    SDL_Surface *texto[6],*textoDinamico;
    SDL_Color cor1 = {0,0,0};
    SDL_Rect rect;
    SDL_Event evento;

    //definir textos e posicoes
    strcpy(txt[0].texto,"CATEGORIA:");
    txt[0].x = 25;
    txt[0].y = 125;
    texto[0] = TTF_RenderText_Solid(btMenu.font,txt[0].texto,cor1);

    strcpy(txt[1].texto,"PERGUNTA:");
    txt[1].x = 25;
    txt[1].y = 225;
    texto[1] = TTF_RenderText_Solid(btMenu.font,txt[1].texto,cor1);

    strcpy(txt[2].texto,"RESP CORRECTA:");
    txt[2].x = 25;
    txt[2].y = 295;
    texto[2] = TTF_RenderText_Solid(btMenu.font,txt[2].texto,cor1);

    strcpy(txt[3].texto,"RESP ERRADA 1:");
    txt[3].x = 25;
    txt[3].y = 365;
    texto[3] = TTF_RenderText_Solid(btMenu.font,txt[3].texto,cor1);

    strcpy(txt[4].texto,"RESP ERRADA 2:");
    txt[4].x = 25;
    txt[4].y = 435;
    texto[4] = TTF_RenderText_Solid(btMenu.font,txt[4].texto,cor1);

    strcpy(txt[5].texto,"RESP ERRADA 3:");
    txt[5].x = 25;
    txt[5].y = 505;
    texto[5] = TTF_RenderText_Solid(btMenu.font,txt[5].texto,cor1);

    SDL_BlitSurface(btMenu.fundo2,NULL,ecra,NULL);

    //ciclo
    while(pos != 6 || Pergunta.categoria == 0)
    {
        //fundo


        //capturar evento
        SDL_PollEvent(&evento);

        //mostrar texto no ecra
        for(i=0;i<6;i++)
        {
            rect.x = txt[i].x;
            rect.y = txt[i].y;
            SDL_BlitSurface(texto[i],NULL,ecra,&rect);
        }

        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
        }


        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            switch(evento.button.button == SDL_BUTTON_LEFT)
            {
                default:
                    if(ratoX > 12 && ratoX < 287 && ratoY > 10 && ratoY < 66) menuOpcoes(ecra,cor); //voltar ao menu anterior
                break;
            }
        }


        if(evento.type == SDL_KEYDOWN)
        {
            unic = (char)evento.key.keysym.sym; //input do teclado
            switch(evento.key.keysym.sym)
            {

            case SDLK_RETURN:
                    pos++;
                break;

            default:
                switch(pos)
                {
                    case 1: //pergunta
                        sprintf(Pergunta.pergunta,"%s%c",Pergunta.pergunta,unic);
                        rect.x = txt[pos].x + 215;
                        rect.y = txt[pos].y;
                        textoDinamico = TTF_RenderText_Solid(btMenu.font,Pergunta.pergunta,cor);
                        SDL_BlitSurface(textoDinamico,NULL,ecra,&rect);
                        break;
                    case 2: //resposta certa
                        sprintf(Pergunta.resposta[0],"%s%c",Pergunta.resposta[0],unic);
                        rect.x = txt[pos].x + 305;
                        rect.y = txt[pos].y;
                        textoDinamico = TTF_RenderText_Solid(btMenu.font,Pergunta.resposta[0],cor);
                        SDL_BlitSurface(textoDinamico,NULL,ecra,&rect);
                        break;
                    case 3: //resposta errada 1
                        sprintf(Pergunta.resposta[1],"%s%c",Pergunta.resposta[1],unic);
                        rect.x = txt[pos].x + 285;
                        rect.y = txt[pos].y;
                        textoDinamico = TTF_RenderText_Solid(btMenu.font,Pergunta.resposta[1],cor);
                        SDL_BlitSurface(textoDinamico,NULL,ecra,&rect);
                        break;
                    case 4: //resposta errada 2
                        sprintf(Pergunta.resposta[2],"%s%c",Pergunta.resposta[2],unic);
                        rect.x = txt[pos].x + 285;
                        rect.y = txt[pos].y;
                        textoDinamico = TTF_RenderText_Solid(btMenu.font,Pergunta.resposta[2],cor);
                        SDL_BlitSurface(textoDinamico,NULL,ecra,&rect);
                        break;
                    case 5: //resposta errada 3
                        sprintf(Pergunta.resposta[3],"%s%c",Pergunta.resposta[3],unic);
                        rect.x = txt[pos].x + 285;
                        rect.y = txt[pos].y;
                        textoDinamico = TTF_RenderText_Solid(btMenu.font,Pergunta.resposta[3],cor);
                        SDL_BlitSurface(textoDinamico,NULL,ecra,&rect);
                        break;
                    default:
                        break;
                }
            break;
            }
        }



        //actualizar ecra
        SDL_Flip(ecra);
        SDL_Delay(80);
    }

    //TODO -> gravar pergunta
}
