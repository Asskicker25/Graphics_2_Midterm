#include "Scene_One.h"
#include "../AppSettings.h"
#include "../Interior/Interior.h"

void Scene_One::Start()
{
	GameCamera* mainCamera = new GameCamera();
	mainCamera->name = "MainCamera";
	mainCamera->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 100.0f, 45.0f);
	mainCamera->transform.SetPosition(glm::vec3(0, 0, 10));
	mainCamera->applyPostProcessing = true;
	mainCamera->postProcessing->bloom.isEnabled = true;
	mainCamera->postProcessing->chromaticAberration.isEnabled = true;

	Light* dirLight = new Light();
	dirLight->transform.SetScale(glm::vec3(0.1f));
	dirLight->transform.SetPosition(glm::vec3(0, 0, 3));
	dirLight->InitializeLight(Directional);

	Interior* interior = new Interior();
}

void Scene_One::Update()
{
}

void Scene_One::Render()
{
}
