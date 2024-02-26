#include "BaseScreen.h"

void BaseScreen::SetScreenOff()
{
	meshes[0]->material->AsMaterial()->diffuseTexture = blackTexture;
}
