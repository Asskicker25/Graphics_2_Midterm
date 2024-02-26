#pragma once

#include <Graphics/BaseMaterial.h>
#include <Graphics/Texture/BaseTexture.h>

class SciFiScreenMaterial : public BaseMaterial
{
public:
	SciFiScreenMaterial();

	glm::vec2 textureTiling = glm::vec2(1.0f);

	BaseTexture* diffuseTexture = nullptr;

	// Inherited via BaseMaterial
	void UpdateMaterial(Shader* shader) override;
	void ResetMaterial(Shader* shader) override;
	BaseMaterial* CloneMaterial() override;

	virtual void OnPropertyDraw();

private:

	bool mCurrentlyFlicker = false;

	float mFlickerValue = 0;
	float mFlickerResetSpeed = 0.1f;
	float mFlickerTimeStep = 0;
	float mFlickerAtDuration = 3;
	
	glm::vec2 mFlickerRange = glm::vec2(0.3f, 0.7f);
	glm::vec2 mFlickerTimeRange = glm::vec2(4, 7);

	void HandleFlicker();
	void Flicker();
};

