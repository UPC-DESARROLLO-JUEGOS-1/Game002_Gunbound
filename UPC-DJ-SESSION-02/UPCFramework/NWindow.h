#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <functional>

class NWindow
{
public:
	NWindow();
	~NWindow();

	int GetScreenWidth() { mScreenWidth; }
	int GetScreenHeight() { mScreenHeight; }

	void Update(float dt);
	void Present();
	void AddInputListener(std::function<void(SDL_Event)> callback) { mOnInputCallback = callback; }

	int Create(const std::string windowName, int screenWidth, int screenHeight, 
		unsigned int windowFlags);

private:
	int mScreenWidth;
	int mScreenHeight;

	SDL_Window* mSDL_Window;
	std::function<void(SDL_Event)> mOnInputCallback = NULL;

	void ProcessInputs();
};
