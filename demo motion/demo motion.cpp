#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

const string WINDOW_TITLE = "demo motion";

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum errorType
{
    IMG_Err,
    SDL_Err,
    none
};

void logSDLError(std::ostream& os, const std::string &msg, bool fatal, int type)
{
    switch (type)
    {
        case SDL_Err:
        os << msg << " Error: " << SDL_GetError() << std::endl; break;
        case IMG_Err:
        os << msg << " Error: " << IMG_GetError() << std::endl; break;
    }
    if (fatal) {
        SDL_Quit();
        IMG_Quit();
        exit(1);
    }
}

// texture with width and height
struct textureE
{
    SDL_Texture* texture;
    int width;
    int height;

    // position on screen
    int posX;
    int posY;

    textureE()
    {
        texture = NULL;
        width = 0;
        height = 0;
        posX = 0;
        posY = 0;
    }

    void loadTexture(std::string path, SDL_Renderer* renderer)
    {
        free();
        SDL_Texture* newTexture;
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL ) logSDLError(std::cout, "Unable to load image", true, IMG_Err);
        else
            {
                SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface -> format, 0xFF, 0xFF, 0xFF));
                newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
                if ( newTexture == NULL ) logSDLError(std::cout, "Unable to create texture", true, SDL_Err);
                else
                {
                    width = loadedSurface -> w;
                    height = loadedSurface -> h;
                }
                SDL_FreeSurface(loadedSurface);
            }
        texture = newTexture;
    }

    void free()
    {
        if (texture != NULL)
        {
            SDL_DestroyTexture(texture);
            width = 0;
            height = 0;
            posX = 0;
            posY = 0;
        }
    }

    // render at position with rotation and flipping
    // clip for rendering a part of the picture
    void render (SDL_Renderer* &renderer, SDL_Rect* clip = NULL,
                 double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE )
    {
        SDL_Rect renderPos = {posX, posY, width, height};
        if (clip != NULL)
        {
            renderPos.w = clip->w;
            renderPos.h = clip->h;
        }
        SDL_RenderCopyEx(renderer, texture, clip, &renderPos, angle, center, flip);
    }

    void motion(SDL_Renderer* &renderer)
    {
        if (posX < 0) posX = 0;
        if (posX + width > SCREEN_WIDTH) posX = SCREEN_WIDTH - width;
        if (posY < 0) posY = 0;
        if (posY + height > SCREEN_HEIGHT) posY = SCREEN_HEIGHT - height;
        render(renderer);
    }
};

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true, SDL_Err);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    /*window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP); */
    if (window == NULL) logSDLError(std::cout, "CreateWindow", true, SDL_Err);
    else
        {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) ) logSDLError(std::cout, "SDL_image could not initialize!", true, IMG_Err);
        }

    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == NULL) logSDLError(std::cout, "CreateRenderer", true, SDL_Err);
    else
    {
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    }

    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

void loadMedia(SDL_Renderer* &renderer, textureE &abcdefTexture, textureE &backgroundTexture)
{
    abcdefTexture.loadTexture("image/abcdef.png", renderer);
    if( abcdefTexture.texture == NULL )
    {
        logSDLError(std::cout, "Failed to load texture image!", true, SDL_Err);
    }
    backgroundTexture.loadTexture("image/background.png", renderer);
    if( backgroundTexture.texture == NULL )
    {
        logSDLError(std::cout, "Failed to load texture image!", true, SDL_Err);
    }
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    textureE abcdefTexture;
    textureE backgroundTexture;

    loadMedia(renderer, abcdefTexture, backgroundTexture);

    abcdefTexture.posX = 100;
    abcdefTexture.posY = 100;

    backgroundTexture.posX = 0;
    backgroundTexture.posY = 0;

    bool quit = false;

    SDL_Event e;

    //angle of spin
    double degrees = 0;

    //flip type
    SDL_RendererFlip flipType;
    while (!quit)
    {
        while (SDL_PollEvent( &e ) != 0)
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN )
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP: abcdefTexture.posY -= 10; break;
                    case SDLK_DOWN: abcdefTexture.posY += 10; break;
                    case SDLK_LEFT: abcdefTexture.posX -= 10; break;
                    case SDLK_RIGHT: abcdefTexture.posX += 10; break;
                }
            }
        }
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );

        backgroundTexture.render(renderer, NULL);

        abcdefTexture.motion(renderer);

        //Update screen
        SDL_RenderPresent(renderer);
    }
    abcdefTexture.free();
    backgroundTexture.free();
    //Khi thông thường chạy với môi trường bình thường ở nhà
    //SDL_RenderPresent(renderer);
    // Your drawing code here
    // use SDL_RenderPresent(renderer) to show it

    //waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
