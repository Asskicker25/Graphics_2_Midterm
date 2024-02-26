#include "TwitchScreen.h"
#include "../Material/SciFiScreenMaterial.h"

TwitchScreen::TwitchScreen(const std::string& path) : BaseScreen(path)
{
	scifi_01 = new Texture("Assets/Textures/ScreenTextures/Sci-Fi_01.jpg");

}

void TwitchScreen::SetScreenOn()
{
	SciFiScreenMaterial* mat = (SciFiScreenMaterial*)meshes[0]->material;
	mat->diffuseTexture = scifi_01;
}

void TwitchScreen::SetScreenOff()
{
	SciFiScreenMaterial* mat = (SciFiScreenMaterial*)meshes[0]->material;
	mat->diffuseTexture = blackTexture;
}
