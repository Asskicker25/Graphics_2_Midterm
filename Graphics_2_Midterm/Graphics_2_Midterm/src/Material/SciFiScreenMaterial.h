#pragma once

#include <Graphics/BaseMaterial.h>
#include <Graphics/Texture/BaseTexture.h>

class SciFiScreenMaterial : public BaseMaterial
{
public:

	glm::vec2 textureTiling = glm::vec2(1.0f);

	BaseTexture* diffuseTexture = nullptr;

	// Inherited via BaseMaterial
	void UpdateMaterial(Shader* shader) override;
	void ResetMaterial(Shader* shader) override;
	BaseMaterial* CloneMaterial() override;

};

