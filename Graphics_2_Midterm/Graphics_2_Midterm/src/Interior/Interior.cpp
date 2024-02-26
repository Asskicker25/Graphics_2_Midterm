#include "Interior.h"
#include <Graphics/Renderer.h>
#include "../NewShaders/NewShaders.h"

Interior::Interior()
{
	name = "Interior";
	InitializeEntity(this);

	centerConsole = new Model("Assets/Models/SM_Env_Consoles_01_xyz_n_rgba_uv.ply");
	centerConsole->name = "Center Console";

	cornerConsoleLeft = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleLeft->name = "Corner Console Left";
	cornerConsoleLeft->transform.SetPosition(leftConsolePos);

	cornerConsoleRight = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleRight->name = "Corner Console Right";
	cornerConsoleRight->transform.SetPosition(rightConsolePos);
	cornerConsoleRight->transform.SetScale(glm::vec3(-1, 1, 1));


	centerConsoleScreen_1 = new Model("Assets/Models/SM_Env_Consoles_01_screen_1_xyz_n_rgba_uv.ply");
	centerConsoleScreen_1->name = "Center Console Screen 1";
	centerConsoleScreen_1->meshes[0]->material->AsMaterial()->SetBaseColor(screenColor);


	centerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_01_screen_2_xyz_n_rgba_uv.ply");
	centerConsoleScreen_2->name = "Center Console Screen 2";
	centerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/BrokenGlass.png");
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/Fingerprint_1.png");
	centerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;

	centerConsoleScreen_3 = new Model("Assets/Models/SM_Env_Consoles_01_screen_3_xyz_n_rgba_uv.ply");
	centerConsoleScreen_3->name = "Center Console Screen 3";
	centerConsoleScreen_3->meshes[0]->material->AsMaterial()->SetBaseColor(screenColor);


	leftCornerConsoleScreen_1 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_1_xyz_n_rgba_uv.ply");
	leftCornerConsoleScreen_1->name = "Left Corner Screen 1";
	leftCornerConsoleScreen_1->SetModelParent(cornerConsoleLeft);
	leftCornerConsoleScreen_1->meshes[0]->material->AsMaterial()->SetBaseColor(screenColor);


	leftCornerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_2_xyz_n_rgba_uv.ply");
	leftCornerConsoleScreen_2->name = "Left Corner Screen 2";
	leftCornerConsoleScreen_2->SetModelParent(cornerConsoleLeft);
	leftCornerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/Fingerprint_2.png");
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/ScratchesGlass.png");
	leftCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;

	
	rightCornerConsoleScreen_1 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_1_xyz_n_rgba_uv.ply");
	rightCornerConsoleScreen_1->name = "Right Corner Screen 1";
	rightCornerConsoleScreen_1->SetModelParent(cornerConsoleRight);
	rightCornerConsoleScreen_1->meshes[0]->material->AsMaterial()->SetBaseColor(screenColor);


	rightCornerConsoleScreen_2 = new Model("Assets/Models/SM_Env_Consoles_Corner_01_screen_2_xyz_n_rgba_uv.ply");
	rightCornerConsoleScreen_2->name = "Right Corner Screen 2";
	rightCornerConsoleScreen_2->SetModelParent(cornerConsoleRight);
	rightCornerConsoleScreen_2->shader = NewShaders::GetInstance().windowShader;
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->SetBaseColor(alphaBlendColor);
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->alphaMask = new Texture("Assets/Textures/WindowTextures/Fingerprint_3.png");
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->specularTexture = new Texture("Assets/Textures/WindowTextures/Scratches_2.png");
	rightCornerConsoleScreen_2->meshes[0]->material->AsMaterial()->useMaskTexture = true;


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
