#include "NGameApplication.h"
#include "NAppSceneGraph.h"

#include <functional>
#include <iostream>
#include <UPCFramework\NEnumWindowFlags.h>

NGameApplication::NGameApplication()
{

}

void NGameApplication::InitializeApplication() {
	// Creamos el framework
	mFramework.Initialize("UPC - Desarrollo de Juegos", 
		NGameApplication::WIDTH, NGameApplication::HEIGHT,
		NEnumWindowFlags::Windowed);
	mFramework.OnInput(std::bind(&NGameApplication::OnInput, this, std::placeholders::_1));

	mFramework.SetCustomSceneGraph(new NAppSceneGraph());
	mFramework.GetSceneGraph()->GotoScene(EnumAppScenes::MainMenu);
}

void NGameApplication::Start() {
	// Inicializar nuesto juego
	InitializeApplication();

	//mFramework.AddCallback(std::bind(&NGameApplication::Test, this));
	mFramework.DoGameLoop(std::bind(&NGameApplication::Update, this, std::placeholders::_1),
		std::bind(&NGameApplication::Draw, this, std::placeholders::_1));
}

void NGameApplication::OnInput(SDL_Event evnt) {
	//std::cout << std::to_string(evnt.type);

	/*switch (evnt.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		std::cout << std::to_string(evnt.button.x) << " " +
			std::to_string(evnt.button.y) << std::endl;
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	default:
		break;
	} */
}

void NGameApplication::Update(float dt) {
	//std::cout << "update: " << std::to_string(dt) << std::endl;
}

void NGameApplication::Draw(float dt) {
	//std::cout << "Draw: " << std::to_string(dt) << std::endl;
	/*mSprite->Draw(dt);
	mQuad->Draw(dt);
	mCircle->Draw(dt);*/
}

NGameApplication::~NGameApplication()
{
}
