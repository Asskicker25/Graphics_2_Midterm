#include "GraphicsApplication.h"
#include "Scenes/Scene_One.h"
#include "NewShaders/NewShaders.h"

void GraphicsApplication::SetUp()
{

	viewportCamera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 500.0f, 45.0f);
	viewportCamera->transform.SetPosition(glm::vec3(-2, 6, 20));
	viewportCamera->transform.SetRotation(glm::vec3(-10, 0, 0));
	viewportCamera->applyPostProcessing = true;

#pragma region Skybox

		skyBox->meshes[0]->material = new SkyBoxMaterial();
	SkyBoxMaterial* skyboxMat = skyBox->meshes[0]->material->AsSkyBoxMaterial();

	skyboxMat->skyBoxTexture->LoadTexture({
		"Assets/Textures/Skybox/Right.jpg",
		"Assets/Textures/Skybox/Left.jpg",
		"Assets/Textures/Skybox/Up.jpg",
		"Assets/Textures/Skybox/Down.jpg",
		"Assets/Textures/Skybox/Front.jpg",
		"Assets/Textures/Skybox/Back.jpg",
		});

#pragma endregion

#pragma region Shader

	NewShaders::GetInstance().Initialize();
	
#pragma endregion



	Scene_One* sceneOne = new Scene_One();

	SceneManager::GetInstance().AddScene("SceneOne", sceneOne);
	SceneManager::GetInstance().ChangeScene("SceneOne");

}

void GraphicsApplication::Update()
{
}

void GraphicsApplication::Render()
{
}

void GraphicsApplication::Shutdown()
{
}

void GraphicsApplication::ProcessInput(GLFWwindow* window)
{
}

void GraphicsApplication::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void GraphicsApplication::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}
