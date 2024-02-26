#include "TwitchScreen.h"
#include "../Material/SciFiScreenMaterial.h"
#include <Graphics/MathUtils.h>
#include <Graphics/Timer.h>

using namespace MathUtilities;

TwitchScreen::TwitchScreen(const std::string& path) : BaseScreen(path)
{

	staticTexture = new Texture("Assets/Textures/ScreenTextures/Static texture.png");

	SciFiScreenMaterial* mat = (SciFiScreenMaterial*)meshes[0]->material;
	mat->staticTexture = staticTexture;

	scifiTextures.push_back(new Texture("Assets/Textures/ScreenTextures/Sci-Fi_01.jpg"));
	scifiTextures.push_back(new Texture("Assets/Textures/ScreenTextures/Sci_Fi_02.jpg"));
	scifiTextures.push_back(new Texture("Assets/Textures/ScreenTextures/Sci_Fi_03.jpg"));
	scifiTextures.push_back(new Texture("Assets/Textures/ScreenTextures/Sci_Fi_04.jpg"));
	scifiTextures.push_back(new Texture("Assets/Textures/ScreenTextures/Sci_Fi_05.jpg"));
}

void TwitchScreen::SetScreenOn()
{
	((SciFiScreenMaterial*)meshes[0]->material)->applyEffects = true;
	isCameraOn = true;

	SwitchTexture();
}

void TwitchScreen::SetScreenOff()
{
	SciFiScreenMaterial* mat = (SciFiScreenMaterial*)meshes[0]->material;
	mat->diffuseTexture = blackTexture;
	mat->applyEffects = false;
	isCameraOn = false;
}

void TwitchScreen::Update(float deltaTime)
{
	if (!isCameraOn) return;

	mCurrentTimeStep += Timer::GetInstance().deltaTime;

	if (mCurrentTimeStep > mSwitchInterval)
	{
		SwitchTexture();
	}
}

Texture* TwitchScreen::GetRandomTexture()
{
	return scifiTextures[MathUtils::GetRandomIntNumber(0, scifiTextures.size() - 1)];
}

void TwitchScreen::SwitchTexture()
{
	mCurrentTimeStep = 0;
	mSwitchInterval = MathUtils::GetRandomFloatNumber(mSwitchIntervalRange.x, mSwitchIntervalRange.y);

	SciFiScreenMaterial* mat = (SciFiScreenMaterial*)meshes[0]->material;
	mat->diffuseTexture = GetRandomTexture();
}
