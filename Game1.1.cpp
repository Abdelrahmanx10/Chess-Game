//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture K;
LTexture Q;
LTexture N;
LTexture B;
LTexture R;
LTexture P;
LTexture k;
LTexture q;
LTexture n;
LTexture b;
LTexture r;
LTexture p;
LTexture gBackgroundTexture;


LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 150, 75, 0, 255);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load Pieces textures
	if (!K.loadFromFile("blackKing.png"))
	{
		printf("Failed to load blackKing image!\n");
		success = false;
	}
	if (!Q.loadFromFile("blackQueen.png"))
	{
		printf("Failed to load blackQueen texture image!\n");
		success = false;
	}
	if (!R.loadFromFile("blackRook.png"))
	{
		printf("Failed to load blackRook texture image!\n");
		success = false;
	}
	if (!B.loadFromFile("blackBishop.png"))
	{
		printf("Failed to load blackBishop texture image!\n");
		success = false;
	}
	if (!P.loadFromFile("blackPawn.png"))
	{
		printf("Failed to load blackPawn texture image!\n");
		success = false;
	}
	if (!N.loadFromFile("blackKnight.png"))
	{
		printf("Failed to load blackPawn texture image!\n");
		success = false;
	}
	if (!k.loadFromFile("whiteKing.png"))
	{
		printf("Failed to whiteKing texture image!\n");
		success = false;
	}
	if (!q.loadFromFile("whiteQueen.png"))
	{
		printf("Failed to whiteQueen texture image!\n");
		success = false;
	}
	if (!n.loadFromFile("whiteKnight.png"))
	{
		printf("Failed to load whiteKnight texture image!\n");
		success = false;
	}
	if (!b.loadFromFile("whiteBishop.png"))
	{
		printf("Failed to load whiteBishop texture image!\n");
		success = false;
	}
	if (!r.loadFromFile("whiteRook.png"))
	{
		printf("Failed to whiteRook texture image!\n");
		success = false;
	}
	if (!p.loadFromFile("whitePawn.png"))
	{
		printf("Failed to whitePawn texture image!\n");
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded images
	K.free();
	Q.free();
    N.free();
    B.free();
	R.free();
	P.free();
	k.free();
	q.free();
	n.free();
	b.free();
	r.free();
	p.free();
	gBackgroundTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;


			//Update screen
			SDL_RenderPresent(gRenderer);
			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen


				SDL_SetRenderDrawColor(gRenderer, 150, 75, 0, 255);
				SDL_RenderClear(gRenderer);

				for (int i = 0; i < 8; i++) {
					for (int m = 7; m > -1; m--) {
						//Render red filled quad


						SDL_Rect fillRect = { (SCREEN_WIDTH * i) / 8, (SCREEN_HEIGHT * m) / 8, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
						if ((i + m) % 2 == 0)
							SDL_SetRenderDrawColor(gRenderer, 150, 75, 0, 255);
						else
							SDL_SetRenderDrawColor(gRenderer, 255, 233, 197, 255);
						SDL_RenderFillRect(gRenderer, &fillRect);
					}
				}

				//Render Pieces to the screens
				R.render(25, 25);
				N.render(125, 25);
				B.render(225, 25);
				Q.render(325, 25);
				K.render(425, 25);
				B.render(525, 25);
				N.render(625, 25);
				R.render(725, 25);
				for (int i =25; i <= 725;i += 100)
				{
					P.render(i, 125);
				}
				r.render(25, 725);
				n.render(125, 725);
				b.render(225, 725);
				q.render(325, 725);
				k.render(425, 725);
				b.render(525, 725);
				n.render(625, 725);
				r.render(725, 725);
				for (int i = 25; i <= 725;i += 100)
				{
					p.render(i, 625);
				}
				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}