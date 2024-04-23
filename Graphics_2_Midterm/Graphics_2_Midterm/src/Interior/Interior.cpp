#include "Interior.h"
#include <Graphics/Renderer.h>
#include "../NewShaders/NewShaders.h"
#include <Graphics/Light.h>
#include "../Screens/TwitchScreen.h"
#include "../Screens/CameraScreen.h"
#include "../Material/SciFiScreenMaterial.h"

Interior::Interior(SecurityCameras* securtiyCameras)
{

	name = "Interior";
	InitializeEntity(this);
	InputManager::GetInstance().AddListener(this);

	this->securityCameras = securtiyCameras;

	blackTexture = new Texture("res/Textures/DefaultTextures/Specular_Default.jpg");

	LoadLights();
	LoadConsoles();
	LoadWalls();
	LoadFloors();

	SetupScreens();
	ToggleSecurityCamera();
}

void Interior::Start()
{
}

void Interior::Update(float deltaTime)
{
}

void Interior::Render()
{
}

void Interior::OnDestroy()
{
}


void Interior::LoadConsoles()
{
	centerConsole = new Model("Assets/Models/SM_Env_Consoles_01_xyz_n_rgba_uv.ply");
	centerConsole->name = "Center Console";

	cornerConsoleLeft = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleLeft->name = "Corner Console Left";
	cornerConsoleLeft->transform.SetPosition(leftConsolePos);

	cornerConsoleRight = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleRight->name = "Corner Console Right";
	cornerConsoleRight->transform.SetPosition(rightConsolePos);
	cornerConsoleRight->transform.SetScale(glm::vec3(-1, 1, 1));

	centerConsoleScreen_1 = new TwitchScreen("Assets/Models/SM_Env_Consoles_01_screen_1_xyz_n_rgba_uv.ply");
	centerConsoleScreen_1->name = "Center Console Screen 1";

	centerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_01_screen_2_xyz_n_rgba_uv.ply");
	centerConsoleScreen_2->name = "Center Console Screen 2";
	centerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/BrokenGlass.png");
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/Fingerprint_1.png");
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;

	centerConsoleScreen_3 = new TwitchScreen("Assets/Models/SM_Env_Consoles_01_screen_3_xyz_n_rgba_uv.ply");
	centerConsoleScreen_3->name = "Center Console Screen 3";


	leftCornerConsoleScreen_1 = new CameraScreen("Assets/Models/SM_Env_Consoles_Corner_01_screen_1_xyz_n_rgba_uv.ply");
	leftCornerConsoleScreen_1->name = "Left Corner Screen 1";
	leftCornerConsoleScreen_1->SetModelParent(cornerConsoleLeft);


	leftCornerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_2_xyz_n_rgba_uv.ply");
	leftCornerConsoleScreen_2->name = "Left Corner Screen 2";
	leftCornerConsoleScreen_2->SetModelParent(cornerConsoleLeft);
	leftCornerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/Fingerprint_2.png");
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/ScratchesGlass.png");
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;


	rightCornerConsoleScreen_1 = new CameraScreen("Assets/Models/SM_Env_Consoles_Corner_01_screen_1_xyz_n_rgba_uv.ply");
	rightCornerConsoleScreen_1->name = "Right Corner Screen 1";
	rightCornerConsoleScreen_1->transform.SetPosition(glm::vec3(5, 0, 0));
	rightCornerConsoleScreen_1->transform.SetScale(glm::vec3(-1, 1, -1));

	rightCornerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_2_xyz_n_rgba_uv.ply");
	rightCornerConsoleScreen_2->name = "Right Corner Screen 2";
	rightCornerConsoleScreen_2->SetModelParent(cornerConsoleRight);
	rightCornerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/Fingerprint_3.png");
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/Scratches_2.png");
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;


	mListOfScreens.push_back(centerConsoleScreen_1);
	mListOfScreens.push_back(centerConsoleScreen_3);
	mListOfScreens.push_back(leftCornerConsoleScreen_1);
	mListOfScreens.push_back(rightCornerConsoleScreen_1);

}

void Interior::LoadWalls()
{
	Model* wall = new Model("Assets/Models/SM_Env_Wall_02_xyz_n_rgba_uv.ply");
	wall->name = "Wall 1";
	//wall->transform.SetPosition(glm::vec3(-10, 0, 5));
	wall->SetModelParent(cornerConsoleLeft);
	wall->transform.SetRotation(glm::vec3(0, 90, 0));


	Model* wall2 = new Model();
	wall2->name = "Wall 2";
	wall2->CopyFromModel(*wall, true);
	wall2->SetModelParent(cornerConsoleRight);
	wall2->transform.SetPosition(glm::vec3(0, 0, 5));
	wall2->transform.SetRotation(glm::vec3(0, -90, 0));
}

void Interior::LoadFloors()
{
	Model* floor_1 = new Model("Assets/Models/SM_Env_Floor_01_xyz_n_rgba_uv.ply");
	floor_1->name = "FLoor 1";
	floor_1->transform.SetPosition(glm::vec3(-2.5, 0, 0));
	floor_1->transform.SetScale(glm::vec3(0.8f, 1, 1));

	Model* floor_2 = new Model();
	floor_2->name = "FLoor 2 ";
	floor_2->CopyFromModel(*floor_1, true);
	floor_2->transform.SetPosition(glm::vec3(2, 0, 0));
	floor_2->transform.SetScale(glm::vec3(0.9, 1, 1));


	glm::vec3 pos = glm::vec3(-5, 0, 5);

	for (int i = 0; i < 3; i++)
	{
		Model* floor1 = new Model();
		floor1->CopyFromModel(*floor_1, true);
		floor1->name = "Floor " + std::to_string(i + 3);
		floor1->transform.SetPosition(glm::vec3(pos.x + (i * 5), pos.y, pos.z));
		floor1->transform.SetScale(glm::vec3(1));
	}
}

void Interior::LoadLights()
{
	Light* pointLight = new Light();
	pointLight->transform.SetScale(glm::vec3(0.1f));
	pointLight->transform.SetPosition(glm::vec3(-1.9f, 4, 5.9f));
	pointLight->InitializeLight(Point);
	pointLight->intensity = 0.9f;
	pointLight->attenuation = glm::vec4(1, 0.5, 0.01, 0.02);
}

void Interior::ChangeTexture(Model* model, BaseTexture* texture)
{
	model->meshes[0]->material->AsMaterial()->diffuseTexture = texture;
}

void Interior::SetupScreens()
{
	mListOfScreens[0]->meshes[0]->material = new SciFiScreenMaterial();
	mListOfScreens[0]->shader = NewShaders::GetInstance().scifiShader;

	mListOfScreens[1]->meshes[0]->material = new SciFiScreenMaterial();
	mListOfScreens[1]->shader = NewShaders::GetInstance().scifiShader;

	mListOfScreens[2]->shader = NewShaders::GetInstance().screenShader;
	mListOfScreens[3]->shader = NewShaders::GetInstance().screenShader;

	((CameraScreen*)mListOfScreens[2])->SetSecurityCamera(securityCameras);
	((CameraScreen*)mListOfScreens[3])->SetSecurityCamera(securityCameras);

	for (BaseScreen* model : mListOfScreens)
	{
		model->blackTexture = blackTexture;
	}

}

void Interior::ToggleSecurityCamera()
{
	isCameraOn = !isCameraOn;

	for (BaseScreen* screen : mListOfScreens)
	{
		if (!isCameraOn)
		{
			screen->SetScreenOff();

		}
		else
		{
			screen->SetScreenOn();
		}
	}

}

void Interior::OnKeyPressed(const int& key)
{
	if (key == GLFW_KEY_2)
	{
		ToggleSecurityCamera();
	}
}

void Interior::OnKeyReleased(const int& key)
{
}

void Interior::OnKeyHeld(const int& key)
{
}
