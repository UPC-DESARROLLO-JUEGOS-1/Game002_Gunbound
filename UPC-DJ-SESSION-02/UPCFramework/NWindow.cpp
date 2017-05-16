#include "NWindow.h"
#include "NEnumWindowFlags.h"
#include "FatalError.h"

NWindow::NWindow() : 
	mScreenWidth(0), 
	mScreenHeight(0)
{
}

NWindow::~NWindow()
{
}

void NWindow::Present()
{
	// Swap buffers
	SDL_GL_SwapWindow(mSDL_Window);
}

int NWindow::Create(const std::string windowName, int screenWidth, int screenHeight, unsigned int windowFlags)
{
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;

	Uint32 flags = SDL_WINDOW_OPENGL;

	if (windowFlags & NEnumWindowFlags::Invisible) { flags |= SDL_WINDOW_HIDDEN; }
	if (windowFlags & NEnumWindowFlags::Fullscreen) { flags |= SDL_WINDOW_FULLSCREEN_DESKTOP; }
	if (windowFlags & NEnumWindowFlags::Borderless) { flags |= SDL_WINDOW_BORDERLESS; }

	// Create Window with SDL
	mSDL_Window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, flags);

	if (mSDL_Window == nullptr) {
		FatalError("SDL Window could not be created!");
	}

	// Create GL Context
	SDL_GLContext glContext = SDL_GL_CreateContext(mSDL_Window);

	if (glContext == nullptr) {
		FatalError("SDL_GL Context could not be created!");
	}

	// Initialize GLEW
	GLenum error = glewInit();

	if (error != GLEW_OK) {
		FatalError("Could not initialize GLEW!");
	}

	// Now clear the screen
	glClearColor(0, 0, 1.0f, 1.0f);

	// Check the OpenGL Version
	std::printf("*** OpenGL Version: %s ***\n", glGetString(GL_VERSION));

	// Set V-Sync
	SDL_GL_SetSwapInterval(1);
	
	return 0;
}

void NWindow::ProcessInputs() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		if (mOnInputCallback != NULL) {
			mOnInputCallback(evnt);
		}
	}
}

void NWindow::Update(float dt) {
	ProcessInputs();
}