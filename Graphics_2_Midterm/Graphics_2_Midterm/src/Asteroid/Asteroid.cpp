#include "Asteroid.h"

Asteroid::Asteroid()
{
	name = "Asteroid";
	LoadModel("Assets/Models/42IsisMiningComplex/asteroid_main_xyz_n_rgba_uv.ply");
	transform.SetPosition(glm::vec3(10000, 0, 0));
	transform.SetScale(glm::vec3(0.1f));

	Model* industrial = new Model("Assets/Models/42IsisMiningComplex/asteroid_industrial_xyz_n_rgba_uv.ply");
	industrial->SetModelParent(this);
	industrial->name = "Asteroid_Industrial";

	Model* other = new Model("Assets/Models/42IsisMiningComplex/asteroid_other_xyz_n_rgba_uv.ply");
	other->SetModelParent(this);
	other->name = "Asteroid_Other";

	Model* stufff = new Model("Assets/Models/42IsisMiningComplex/stuff_main_asteroid_xyz_n_rgba_uv.ply");
	stufff->SetModelParent(this);
	stufff->name = "Asteroid_Stuff";


}
