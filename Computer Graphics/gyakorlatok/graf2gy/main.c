#include <SDL2/SDL.h>
#include <stdio.h>

#define MAX_LINE_COUNT 5

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

typedef struct Line {
    int x1, y1, x2, y2;
    Color color;

} Line;

int main(int argc, char* argv[]) {

    Line line1 = {320, 200, 300, 240, {255, 0, 0}};
    Line line2 = {300, 240, 340, 240, {0, 255, 0}};
    Line line3 = {340, 240, 320, 200, {0, 0, 255}};
    int mouseCounter = 0;
    int lineCount = 0;
    Line mouseLine;
    SDL_Event events;


    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            // Loop that keeps the window and renderer open, using the flag "done"
            while (!done) {
                SDL_Event event;

                // Draw the triangle in the middle of the screen
                SDL_SetRenderDrawColor(renderer, line1.color.r, line1.color.g, line1.color.b, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, line1.x1, line1.y1, line1.x2, line1.y2);
                SDL_SetRenderDrawColor(renderer, line2.color.r, line2.color.g, line2.color.b, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, line2.x1, line2.y1, line2.x2, line2.y2);
                SDL_SetRenderDrawColor(renderer, line3.color.r, line3.color.g, line3.color.b, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, line3.x1, line3.y1, line3.x2, line3.y2);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&events)) {
                    switch (events.type) {
                        case SDL_MOUSEMOTION:
                            printf("Current mouse position is: (%d, %d)\n", events.motion.x, events.motion.y);
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            printf("Mouse button %d pressed at (%d, %d)\n", events.button.button, events.button.x, events.button.y);

                            if (mouseCounter == 0) {
                                mouseLine.x1 = events.button.x;
                                mouseLine.y1 = events.button.y;
                                mouseCounter++;
                            } else if (mouseCounter == 1) {
                                mouseCounter = 0;
                                mouseLine.x2 = events.button.x;
                                mouseLine.y2 = events.button.y;
                                mouseLine.color.r = rand() % 255;
                                mouseLine.color.g = rand() % 255;
                                mouseLine.color.b = rand() % 255;
                                SDL_SetRenderDrawColor(renderer, mouseLine.color.r, mouseLine.color.g,
                                                       mouseLine.color.b, SDL_ALPHA_OPAQUE);
                                SDL_RenderDrawLine(renderer, mouseLine.x1, mouseLine.y1, mouseLine.x2, mouseLine.y2);
                                printf("Line created: (%d, %d) to (%d, %d)\n", mouseLine.x1, mouseLine.y1, mouseLine.x2,
                                       mouseLine.y2);
                                lineCount++;
                            }
                            break;
                        case SDL_KEYDOWN:
                            //If escape is pressed, end the program
                            if(SDL_SCANCODE_ESCAPE == events.key.keysym.scancode) {
                                done = SDL_TRUE;
                            }
                        default:
                            break;
                    }
                }

                if (lineCount == MAX_LINE_COUNT) {
                    printf("Max line count reached. Clearing lines created by the mouse.\n");
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);
                    lineCount = 0;
                }
            }

            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);

        } else {
            printf("Could not create window and renderer: %s\n", SDL_GetError());
            return -1;
        }
        SDL_Quit();
        return 0;

    } else {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }
}