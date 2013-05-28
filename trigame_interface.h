#ifndef TRIGAME_INTERFACE_H_INCLUDED
#define TRIGAME_INTERFACE_H_INCLUDED



#endif // TRIGAME_INTERFACE_H_INCLUDED


/*
* menu inicial
*/
void menu(SDL_Surface* ecra)
{
    char texto[100];
    int ratoX, ratoY,but1 = 0, but2 = 0, but3 = 0;

    SDL_Event evento;
    SDL_Rect rect = {0,0,100,100};

    SDL_Surface* fundo = SDL_LoadBMP("img/splash.bmp");
    SDL_Surface* btNovoJogo = SDL_LoadBMP("img/novojogo.bmp");
    SDL_Surface* btOpcoes = SDL_LoadBMP("img/opcoes.bmp");
    SDL_Surface* btSair = SDL_LoadBMP("img/sair.bmp");
    SDL_Surface* btNovoJogob = SDL_LoadBMP("img/novojogob.bmp");
    SDL_Surface* btOpcoesb = SDL_LoadBMP("img/opcoesb.bmp");
    SDL_Surface* btSairb = SDL_LoadBMP("img/sairb.bmp");
    SDL_Surface* msg = NULL;

    //som
    Mix_Music* musica_menu = NULL;
    musica_menu = Mix_LoadMUS("music/botoes.wav");


    TTF_Font *font = NULL;
    SDL_Color cor1 = {0,0,0};
    font = TTF_OpenFont("font/font1.ttf",26);
    msg = TTF_RenderText_Solid(font,"Versao Alpha",cor1);

    while(1)
    {
        SDL_PollEvent(&evento);
        SDL_BlitSurface(fundo,NULL,ecra,NULL);
        //botao novo jogo
        rect.x = 350;
        rect.y = 300;
        SDL_BlitSurface(btNovoJogo,NULL,ecra,&rect);
        //botao opcoes
        rect.x = 350;
        rect.y = 370;
        SDL_BlitSurface(btOpcoes,NULL,ecra,&rect);
        //botao sair
        rect.x = 350;
        rect.y = 440;
        SDL_BlitSurface(btSair,NULL,ecra,&rect);

        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(texto,"X:%i Y:%i",ratoX,ratoY);
            SDL_WM_SetCaption(texto,NULL);

            //botao novo jogo
            if(ratoX > 351 && ratoX < 661 && ratoY > 302 && ratoY < 373)
            {
                //botao novo jogo preto
                    rect.x = 350;
                    rect.y = 300;
                    SDL_BlitSurface(btNovoJogob,NULL,ecra,&rect);
                    if(but1 == 0)
                        Mix_PlayMusic(musica_menu,1);
                    but1 = 1;
                    but2 = but3 = 0;
            }else if(ratoX > 351 && ratoX < 661 && ratoY > 374 && ratoY < 444)
            {
                //botao opcoes preto
                    rect.x = 350;
                    rect.y = 370;
                    SDL_BlitSurface(btOpcoesb,NULL,ecra,&rect);
                    if(but2 == 0)
                        Mix_PlayMusic(musica_menu,1);
                    but2 = 1;
                    but1 = but3 = 0;
            }else if(ratoX > 351 && ratoX < 661 && ratoY > 444 && ratoY < 515)
            {
                //botao sair preto
                    rect.x = 350;
                    rect.y = 440;
                    SDL_BlitSurface(btSairb,NULL,ecra,&rect);
                    if(but3 == 0)
                        Mix_PlayMusic(musica_menu,1);
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
        SDL_Delay(50);
    }
}
