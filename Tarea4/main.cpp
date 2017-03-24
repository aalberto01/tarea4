
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*p1,*p2,*p3,*p4,*logo;
SDL_Rect rect_background,rect_p1,rect_p2,rect_p3,rect_p4,rect_logo;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1200/*WIDTH*/, 700/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = 1200; rect_background.h = 700;

    p1 = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(p1, NULL, NULL, &w, &h);
    rect_p1.x = 500; rect_p1.y = 500; rect_p1.w = 150; rect_p1.h = 150;

    p2 = IMG_LoadTexture(renderer, "personaje2.png");
    SDL_QueryTexture(p2, NULL, NULL, &w, &h);
    rect_p2.x = 300; rect_p2.y = 300; rect_p2.w = 150; rect_p2.h = 170;

    p3 = IMG_LoadTexture(renderer, "personaje3.png");
    SDL_QueryTexture(p3, NULL, NULL, &w, &h);
    rect_p3.x = 600; rect_p3.y = 150; rect_p3.w = 150; rect_p3.h = 170;

    p4 = IMG_LoadTexture(renderer, "personaje4.png");
    SDL_QueryTexture(p3, NULL, NULL, &w, &h);
    rect_p4.x = 800; rect_p4.y = 250; rect_p4.w = 150; rect_p4.h = 170;

    logo = IMG_LoadTexture(renderer, "logo.png");
    SDL_QueryTexture(logo, NULL, NULL, &w, &h);
    rect_logo.x = 50; rect_logo.y = 100; rect_logo.w = 500; rect_logo.h = 120;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_p1.x++;
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, p1, NULL, &rect_p1);
        SDL_RenderCopy(renderer, p2, NULL, &rect_p2);
        SDL_RenderCopy(renderer, p3, NULL, &rect_p3);
        SDL_RenderCopy(renderer, p4, NULL, &rect_p4);
        SDL_RenderCopy(renderer, logo, NULL, &rect_logo);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
