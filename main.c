#include <stdio.h>
#include <stdlib.h>
//TRIGAME
#include <trigame_administracao.h>
#include <trigame_jogo.h>
#include <trigame_interface.h>
//SDL
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_Mixer.h>

#define RAND_MAX = 255;




int main(int argc, char* args[])
{
    //SDL
    SDL_Surface* fundo = NULL;
    SDL_Surface* screen = NULL;
    SDL_Surface* mensagem = NULL;
    SDL_Rect rect = {50,50,100,50};

    SDL_Event event;

    Mix_Music *music = NULL;

    TTF_Font *font = NULL;

    SDL_Color textColor = {255,255,255};

    char texto[100];


    screen = SDL_SetVideoMode(1024,768,32,SDL_SWSURFACE);

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);


    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    fundo = SDL_LoadBMP("img/splash.bmp");

    music = Mix_LoadMUS("music/title.mp3");

    font = TTF_OpenFont("font/font1.ttf",28);

    Mix_PlayMusic(music,-1);

    mensagem = TTF_RenderText_Solid(font,"Versao Alpha",textColor);

    SDL_BlitSurface(fundo,NULL,screen,NULL);

    SDL_BlitSurface(mensagem,NULL,screen,&rect);

    SDL_WM_SetCaption("TriGame 2013",NULL);







    /**** **********************************************/

    //filas
    filaUtilizadores fU;
    filaPerguntas fP;

    //preencher filas
    if(fU = lerUtilizadores("users.db")) printf("Utilizadores - OK\n");
    if(fP = lerPergunta("perguntas.db")) printf("Perguntas - OK\n");

    /********************   *******************************/


    while(1)
    {

        textColor =(SDL_Color) {rand(),rand(),rand()};
        SDL_PollEvent(&event);
        //eventos do teclado
        if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit(1);
                break;
            }
        }

        //eventos do rato
        if(event.type == SDL_MOUSEMOTION)
        {
            rect =(SDL_Rect) {event.motion.x,event.motion.y,100,100};
            sprintf(texto,".");
        }

        //clique do rato
       if(event.type == SDL_MOUSEBUTTONUP)
        {
            rect =(SDL_Rect) {event.motion.x,event.motion.y,100,100};
            sprintf(texto,event.button.type);
        }

        mensagem = TTF_RenderText_Solid(font,texto,textColor);
        SDL_BlitSurface(mensagem,NULL,screen,&rect);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(fundo);
    Mix_CloseAudio();
    SDL_QUIT;
    return 0;
}
