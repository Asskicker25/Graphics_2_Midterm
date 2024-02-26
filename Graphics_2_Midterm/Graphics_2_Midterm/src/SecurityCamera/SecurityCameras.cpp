#include "SecurityCameras.h"
#include <Graphics/MathUtils.h>;
#include "../AppSettings.h"

using namespace MathUtilities;

SecurityCameras::SecurityCameras()
{
	name = "SecurityCameras";
	InitializeEntity(this);
	SetupCameras();
}

void SecurityCameras::Start()
{
}

void SecurityCameras::Update(float deltaTime)
{
}

void SecurityCameras::Render()
{
}

void SecurityCameras::OnDestroy()
{
}

Camera* SecurityCameras::GetRandomCamera()
{
	if (mListOfRenderCameras.size() == 0) return nullptr;

	return mListOfRenderCameras[MathUtils::GetRandomIntNumber(0, mListOfRenderCameras.size() - 1)];
}

void SecurityCameras::SetupCameras()
{
	GameCamera* camera1 = new GameCamera();
	camera1->name = "RenderCamera 1";
	camera1->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	camera1->transform.SetPosition(glm::vec3(10121.17f, 1.12f, -53.13f));
	camera1->transform.SetRotation(glm::vec3(-2.00f, 91.10f, 0.0f));
	camera1->SetRenderTexture(new RenderTexture());

	GameCamera* camera2 = new GameCamera();
	camera2->name = "RenderCamera 2";
	camera2->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	camera2->transform.SetPosition(glm::vec3(10000.83f, 2.75f, 52.57f));
	camera2->transform.SetRotation(glm::vec3(0.40f, -3.90f, 0.0f));
	camera2->SetRenderTexture(new RenderTexture());

	GameCamera* camera3 = new GameCamera();
	camera3->name = "RenderCamera 3";
	camera3->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	camera3->transform.SetPosition(glm::vec3(9956.22f, -41.00f, -38.37f));
	camera3->transform.SetRotation(glm::vec3(76.30, -46.30f, 0.0f));
	camera3->SetRenderTexture(new RenderTexture());

	GameCamera* camera4 = new GameCamera();
	camera4->name = "RenderCamera 4";
	camera4->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	camera4->transform.SetPosition(glm::vec3(10036.46f, -51.13f, -21.16f));
	camera4->transform.SetRotation(glm::vec3(44.80, -61.70, 0.0f));
	camera4->SetRenderTexture(new RenderTexture());

	GameCamera* camera5 = new GameCamera();
	camera5->name = "RenderCamera 5";
	camera5->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	camera5->transform.SetPosition(glm::vec3(10035.14f, -4.51f, -62.93f));
	camera5->transform.SetRotation(glm::vec3(14.00f, -94.10f, 0.0f));
	camera5->SetRenderTexture(new RenderTexture());


	mListOfRenderCameras.push_back(camera1);
	mListOfRenderCameras.push_back(camera2);
	mListOfRenderCameras.push_back(camera3);
	mListOfRenderCameras.push_back(camera4);
	mListOfRenderCameras.push_back(camera5);
}
