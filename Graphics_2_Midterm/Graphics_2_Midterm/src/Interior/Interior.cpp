#include "Interior.h"

Interior::Interior()
{
	name = "Interior";
	InitializeEntity(this);

	centerConsole = new Model("Assets/Models/SM_Env_Consoles_01_xyz_n_rgba_uv.ply");
	centerConsole->name = "Center Console";

	cornerConsoleLeft = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleLeft->name = "Corner Console Left";
	cornerConsoleLeft->transform.SetPosition(glm::vec3(-10, 0, 5));

	cornerConsoleRight = new Model("Assets/Models/SM_Env_Consoles_Corner_01_xyz_n_rgba_uv.ply");
	cornerConsoleRight->name = "Corner Console Right";
	cornerConsoleRight->transform.SetPosition(glm::vec3(5, 0, 5));
	cornerConsoleRight->transform.SetScale(glm::vec3(-1, 1, 1));

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
