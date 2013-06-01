#ifndef TRIGAME_JOGO_H_INCLUDED
#define TRIGAME_JOGO_H_INCLUDED


#endif // TRIGAME_JOGO_H_INCLUDED


typedef struct
{
    SDL_Surface *n1;
    SDL_Surface *n2;
    SDL_Surface *n3;
    SDL_Surface *n1p;
    SDL_Surface *n2p;
    SDL_Surface *n3p;
    SDL_Surface *n4;
    SDL_Surface *n5;
    SDL_Surface *n6;
    SDL_Surface *n4p;
    SDL_Surface *n5p;
    SDL_Surface *n6p;
    SDL_Surface *n1c;
    SDL_Surface *n2c;
    SDL_Surface *n3c;
    SDL_Surface *n4c;
    SDL_Surface *n5c;
    SDL_Surface *n6c;
    SDL_Surface *btOpcoesb;
    SDL_Surface *fundo2;
    Mix_Music *musica_menu;
    TTF_Font *font;
}botoesMenujogo;

botoesMenujogo btgame;

void recursosjogo()
{
 btgame.n1 = SDL_LoadBMP("img/n1.bmp");
 btgame.n2 = SDL_LoadBMP("img/n2.bmp");
 btgame.n3 = SDL_LoadBMP("img/n3.bmp");
 btgame.n4 = SDL_LoadBMP("img/n4.bmp");
 btgame.n5 = SDL_LoadBMP("img/n5.bmp");
 btgame.n6 = SDL_LoadBMP("img/n6.bmp");
 btgame.n1p = SDL_LoadBMP("img/n1p.bmp");
 btgame.n2p = SDL_LoadBMP("img/n2p.bmp");
 btgame.n3p = SDL_LoadBMP("img/n3p.bmp");
 btgame.n4p = SDL_LoadBMP("img/n4p.bmp");
 btgame.n5p = SDL_LoadBMP("img/n5p.bmp");
 btgame.n6p = SDL_LoadBMP("img/n6p.bmp");
 btgame.n1c = SDL_LoadBMP("img/n1c.bmp");
 btgame.n2c = SDL_LoadBMP("img/n2c.bmp");
 btgame.n3c = SDL_LoadBMP("img/n3c.bmp");
 btgame.n4c = SDL_LoadBMP("img/n4c.bmp");
 btgame.n5c = SDL_LoadBMP("img/n5c.bmp");
 btgame.n6c = SDL_LoadBMP("img/n6c.bmp");
 btgame.fundo2 = SDL_LoadBMP("img/fundo2.bmp");
 btgame.musica_menu = Mix_LoadMUS("music/botoes.wav");
 btgame.font = TTF_OpenFont("font/font1.ttf",28);
}


void menujogo(SDL_Surface* ecra)
{
    char texto[100];
    int ratoX, ratoY,but1 = 0, but2 = 0, but3 = 0,but4= 0, but5 = 0, but6 = 0, but7 = 0;
    int estadoBotao[6] = {0,0,0,0,0,0};

    SDL_Event evento;
    SDL_Rect rect = {0,0,100,100};
    SDL_Surface *msg = NULL;
    SDL_Surface *voltar = NULL;
    SDL_Surface *Jogar = NULL;


    SDL_Color cor1 = {0,0,0};SDL_Color cor2 = {0,255,0};SDL_Color cor3 = {255,0,0};

    msg = TTF_RenderText_Solid(btgame.font,"Quantos Utilizadores pretendem jogar?",cor1);
    voltar = TTF_RenderText_Solid(btgame.font,"<- Voltar ",cor2);
    Jogar = TTF_RenderText_Solid(btgame.font," Iniciar ->",cor3);

     while(1)
    {
        SDL_PollEvent(&evento);
         SDL_BlitSurface(btgame.fundo2,NULL,ecra,NULL);
        //botao n1
        rect.x = 240;
        rect.y = 210;
        if(estadoBotao[0] == 0) SDL_BlitSurface(btgame.n1,NULL,ecra,&rect);
        if(estadoBotao[0] == 1) SDL_BlitSurface(btgame.n1c,NULL,ecra,&rect);

        rect.x = 440;
        rect.y = 210;
        if(estadoBotao[1] == 0) SDL_BlitSurface(btgame.n2,NULL,ecra,&rect);
        if(estadoBotao[1] == 1) SDL_BlitSurface(btgame.n2c,NULL,ecra,&rect);

        rect.x = 640;
        rect.y = 210;
        if(estadoBotao[2] == 0) SDL_BlitSurface(btgame.n3,NULL,ecra,&rect);
        if(estadoBotao[2] == 1) SDL_BlitSurface(btgame.n3c,NULL,ecra,&rect);
        rect.x = 240;

        rect.y = 405;
        if(estadoBotao[3] == 0) SDL_BlitSurface(btgame.n4,NULL,ecra,&rect);
        if(estadoBotao[3] == 1) SDL_BlitSurface(btgame.n4c,NULL,ecra,&rect);

        rect.x = 440;
        rect.y = 405;
        if(estadoBotao[4] == 0) SDL_BlitSurface(btgame.n5,NULL,ecra,&rect);
        if(estadoBotao[4] == 1) SDL_BlitSurface(btgame.n5c,NULL,ecra,&rect);

        rect.x = 640;
        rect.y = 405;
        if(estadoBotao[5] == 0) SDL_BlitSurface(btgame.n6,NULL,ecra,&rect);
        if(estadoBotao[5] == 1) SDL_BlitSurface(btgame.n6c,NULL,ecra,&rect);

        rect.x = 105;
        rect.y = 127;
        SDL_BlitSurface(msg,NULL,ecra,&rect);

        rect.x = 30;
        rect.y = 650;
        SDL_BlitSurface(voltar,NULL,ecra,&rect);

        rect.x = 800;
        rect.y = 650;
        SDL_BlitSurface(Jogar,NULL,ecra,&rect);


         if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(texto,"X:%i Y:%i",ratoX,ratoY);
            SDL_WM_SetCaption(texto,NULL); //altera o titulo da janela
        }

        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            if(ratoX > 241 && ratoX < 385 && ratoY > 211 && ratoY < 344){

               rect.x = 240;
               rect.y = 210;
               SDL_BlitSurface(btgame.n1p,NULL,ecra,&rect);
               if(but1 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but1 = 1;
                    but6 = but2= but3= but4= but5= 0;
            }else

            if (ratoX > 441 && ratoX < 582 && ratoY > 211 && ratoY < 344)
            {
                rect.x = 440;
                rect.y = 210;
                SDL_BlitSurface(btgame.n2p,NULL,ecra,&rect);
                if(but2 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but2 = 1;
                    but1 = but6= but3= but4= but5= 0;
            }else

            if (ratoX > 641 && ratoX < 782 && ratoY > 211 && ratoY < 344)
            {
                rect.x = 640;
                rect.y = 210;
                SDL_BlitSurface(btgame.n3p,NULL,ecra,&rect);
                if(but3 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but3 = 1;
                    but1 = but2= but6= but4= but5= 0;
            }

            else

            if (ratoX > 240 && ratoX < 382 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 240;
                rect.y = 405;
                SDL_BlitSurface(btgame.n4p,NULL,ecra,&rect);
                if(but4 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but4 = 1;
                    but1 = but2= but3= but6= but5= 0;
            }
            else

            if (ratoX > 441 && ratoX < 582 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 440;
                rect.y = 405;
                SDL_BlitSurface(btgame.n5p,NULL,ecra,&rect);
                if(but5 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but5 = 1;
                    but1 = but2= but3= but4= but6= 0;
            }
            else

            if (ratoX > 641 && ratoX < 782 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 640;
                rect.y = 405;
                SDL_BlitSurface(btgame.n6p,NULL,ecra,&rect);
                 if(but6 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but6 = 1;
                    but1 = but2= but3= but4= but5= 0;
            }
        }



         if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> voltar ao principal
            if(evento.key.keysym.sym == SDLK_ESCAPE)
               exit(1);
        }

         if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            if(ratoX > 30 && ratoX < 245 && ratoY > 646 && ratoY < 680)
            {
               menu(ecra);
            }else
            if (ratoX > 17 && ratoX < 278 && ratoY > 15 && ratoY < 62)
            {
                menu(ecra);
            }

        }

                  if(evento.type == SDL_MOUSEBUTTONDOWN)
                {
                    ratoX = evento.motion.x;
                    ratoY = evento.motion.y;
                    if  (ratoX > 241 && ratoX < 385 && ratoY > 211 && ratoY < 344)
                    {
                        if(estadoBotao[0] == 0)
                        {
                            estadoBotao[0] = 1;
                            estadoBotao[1] = 0;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[0] = 0;
                        }
                    }
                     if (ratoX > 441 && ratoX < 582 && ratoY > 211 && ratoY < 344)
                    {
                         if(estadoBotao[1] == 0)
                        {
                            estadoBotao[1] = 1;
                            estadoBotao[0] = 0;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[1] = 0;
                        }
                    }
                     if (ratoX > 641 && ratoX < 782 && ratoY > 211 && ratoY < 344)
                    {
                        if(estadoBotao[2] == 0)
                        {
                            estadoBotao[2] = 1;
                            estadoBotao[1] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[2] = 0;
                        }
                    }
                     if (ratoX > 240 && ratoX < 382 && ratoY > 406 && ratoY < 540)
                    {
                        if(estadoBotao[3] == 0)
                        {
                            estadoBotao[3] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[1] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[3] = 0;
                        }
                    }

                    if (ratoX > 441 && ratoX < 582 && ratoY > 406 && ratoY < 540)
                    {
                         if(estadoBotao[4] == 0)
                        {
                            estadoBotao[4] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[1] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[4] = 0;
                        }
                    }
                    if (ratoX > 641 && ratoX < 782 && ratoY > 406 && ratoY < 540)
                    {
                        if(estadoBotao[5] == 0)
                        {
                            estadoBotao[5] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[1] = 0;
                        }else{
                            estadoBotao[5] = 0;
                        }
                    }


                }
        SDL_Flip(ecra);
        SDL_Delay(50);

    }

}
