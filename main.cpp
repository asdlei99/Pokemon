#include "SDL.h"
#include <windows.h>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

#define WINDOW_WIDTH 600


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    int frameRate = 60;
    int frameDuration = 1000 / frameRate;
    int t = 0;
    while (true) {
        auto t1 = std::chrono::high_resolution_clock::now();

        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        SDL_RenderDrawPoint(renderer, t%WINDOW_WIDTH, t/WINDOW_WIDTH);
        SDL_RenderPresent(renderer);
        t++;

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        if( duration < frameDuration )
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDuration-duration));
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
