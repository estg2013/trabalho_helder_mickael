#ifndef TRIGAME_INTERFACE_H_INCLUDED
#define TRIGAME_INTERFACE_H_INCLUDED



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
    Mix_Music *musica_menu;
    TTF_Font *font;
}botoesMenu;

botoesMenu btMenu;

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
    SDL_Color cor = {0,0,0};
    SDL_Event evento;
    SDL_Surface *txtUtilizador = NULL;

    SDL_BlitSurface(btMenu.fundo2,NULL,ecra,NULL); //fundo
    rect.y = 30;
    rect.x = 500;
    txtUtilizador = TTF_RenderText_Solid(btMenu.font,"UTILIZADORES",cor);
    SDL_BlitSurface(txtUtilizador,NULL,ecra,&rect);



    int ratoX, ratoY, i = 0, posU = 0, contadorU; //posU -> posicao de topo na lista de utilizadores para saber se mostra ou nao a seta superior
    char texto[100];

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



        contadorU = 0;
        i=0;
        fU = fUinicial;
        //listar os utilizadores
        while(fU != NULL || i >= 10)
        {
                    if(contadorU >= posU && contadorU < (posU + 9) && i < 10)
                    {
                        nomes[i].x = 150;
                        nomes[i].y = (130)+(60*i);
                        txtUtilizador = TTF_RenderText_Solid(btMenu.font,fU->jogador.username,cor);
                        SDL_BlitSurface(txtUtilizador,NULL,ecra,&nomes[i]);
                        i++;
                    }
                    contadorU++; //incrementa a contagem de utilizadores
                    fU = fU->proximoJogador;
        }



        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(texto,"X:%i Y:%i",ratoX,ratoY);
            SDL_WM_SetCaption(texto,NULL);
        }


        if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            if(ratoX > 12 && ratoX < 287 && ratoY > 10 && ratoY < 66) menuOpcoes(ecra,cor); //voltar ao menu anterior
            if(ratoX > 770 && ratoX < 992 && ratoY > 532 && ratoY < 750) posU++;
            if(ratoX > 770 && ratoX < 992 && ratoY > 94 && ratoY < 314 && posU > 0) posU--;
        }


        if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> voltar para menu anterior
            if(evento.key.keysym.sym == SDLK_ESCAPE)
                 menuOpcoes(ecra,cor);
        }

        //actualizar ecra e esperar 50ms
        SDL_Flip(ecra);
        SDL_Delay(80);
    }
}
