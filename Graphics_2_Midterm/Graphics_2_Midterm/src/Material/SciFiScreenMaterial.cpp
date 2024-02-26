#include "SciFiScreenMaterial.h"
#include <Graphics/Timer.h>
#include <Graphics/MathUtils.h>
#include <Graphics/Panels/ImguiDrawUtils.h>

using namespace MathUtilities;

SciFiScreenMaterial::SciFiScreenMaterial()
{
	mFlickerAtDuration = MathUtils::GetRandomFloatNumber(mFlickerTimeRange.x, mFlickerTimeRange.y);
}

void SciFiScreenMaterial::UpdateMaterial(Shader* shader)
{
	shader->SetUniform3f("textureTiling", this->textureTiling.x, this->textureTiling.y, 1.0f);
	shader->SetUniform1f("flickerValue", mFlickerValue);

	if (this->diffuseTexture != nullptr)
	{
		this->diffuseTexture->SetTextureSlot(0);
		shader->SetUniform1i("texture_diffuse", 0);
		this->diffuseTexture->Bind();
	}

	HandleFlicker();

}

void SciFiScreenMaterial::ResetMaterial(Shader* shader)
{
}

BaseMaterial* SciFiScreenMaterial::CloneMaterial()
{
	return nullptr;
}


void SciFiScreenMaterial::HandleFlicker()
{
	if (mCurrentlyFlicker)
	{
		mFlickerValue -= Timer::GetInstance().deltaTime * mFlickerResetSpeed;

		if (mFlickerValue <= 0)
		{
			mFlickerValue = 0;
			mCurrentlyFlicker = false;
		}
	}
	else
	{
		mFlickerTimeStep += Timer::GetInstance().deltaTime * mFlickerResetSpeed;

		if (mFlickerTimeStep > mFlickerAtDuration)
		{
			Flicker();
		}
	}
}

void SciFiScreenMaterial::Flicker()
{
	mFlickerValue = MathUtils::GetRandomFloatNumber(mFlickerRange.x, mFlickerRange.y);
	mFlickerAtDuration = MathUtils::GetRandomFloatNumber(mFlickerTimeRange.x, mFlickerTimeRange.y);
	mCurrentlyFlicker = true;
	mFlickerTimeStep = 0;
}

void SciFiScreenMaterial::OnPropertyDraw()
{
	ImGuiUtils::DrawFloat("FlickerTimeStep", mFlickerTimeStep);
	ImGuiUtils::DrawFloat("FlickerValue", mFlickerValue);
}

