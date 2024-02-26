#include "SciFiScreenMaterial.h"

void SciFiScreenMaterial::UpdateMaterial(Shader* shader)
{
	shader->SetUniform3f("textureTiling", this->textureTiling.x, this->textureTiling.y, 1.0f);

	if (this->diffuseTexture != nullptr)
	{
		this->diffuseTexture->SetTextureSlot(0);
		shader->SetUniform1i("texture_diffuse", 0);
		this->diffuseTexture->Bind();
	}
}

void SciFiScreenMaterial::ResetMaterial(Shader* shader)
{
}

BaseMaterial* SciFiScreenMaterial::CloneMaterial()
{
    return nullptr;
}
