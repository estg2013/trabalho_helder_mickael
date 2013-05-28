#ifndef TRIGAME_INTERFACE_H_INCLUDED
#define TRIGAME_INTERFACE_H_INCLUDED



#endif // TRIGAME_INTERFACE_H_INCLUDED

/*
* funcao para desenhar uma imagem no ecra nas coordenadas escolhidas
*/
void imagem(SDL_Surface* ecra, char imagem[], int x, int y)
{
    SDL_Rect rect = {x,y,100,100};
    SDL_Surface* splash = NULL;
    splash = SDL_LoadBMP(imagem);
    SDL_BlitSurface(splash,NULL,ecra,&rect);
    SDL_Flip(ecra);
}


/*
* menu inicial
*/
void menu(SDL_Surface* ecra)
{
    char texto[100];
    SDL_Event evento;
    imagem(ecra,"img/splash.bmp",0,0); //fundo
    imagem(ecra,"img/novojogo.bmp",350,300); //botao 1
    imagem(ecra,"img/opcoes.bmp",350,370); //botao 1
    imagem(ecra,"img/sair.bmp",350,440); //botao 1

    while(1)
    {
        SDL_PollEvent(&evento);

        if(evento.type == SDL_MOUSEMOTION)
        {
            sprintf(texto,"X:%i Y:%i",evento.motion.x,evento.motion.y);
            SDL_WM_SetCaption(texto,NULL);
        }

        if(evento.type == SDL_KEYDOWN)
        {
            if(evento.key.keysym.sym == SDLK_ESCAPE)
                exit(1);
        }


        SDL_Delay(10);
        SDL_Flip(ecra);
    }
}
