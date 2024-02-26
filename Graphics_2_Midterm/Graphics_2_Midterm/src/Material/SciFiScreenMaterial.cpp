#include "SciFiScreenMaterial.h"
#include <Graphics/Timer.h>
#include <Graphics/MathUtils.h>
#include <Graphics/Panels/ImguiDrawUtils.h>

using namespace MathUtilities;

SciFiScreenMaterial::SciFiScreenMaterial()
{
	mFlickerAtDuration = MathUtils::GetRandomFloatNumber(mFlickerTimeRange.x, mFlickerTimeRange.y);
	mStaticInterval = MathUtils::GetRandomFloatNumber(mStaticIntervalRange.x, mStaticIntervalRange.y);
}

void SciFiScreenMaterial::UpdateMaterial(Shader* shader)
{
	shader->SetUniform3f("textureTiling", this->textureTiling.x, this->textureTiling.y, 1.0f);
	shader->SetUniform1f("flickerValue", mFlickerValue);
	shader->SetUniform1f("iTime", Timer::GetInstance().elapsedTime);
	shader->SetUniform1i("staticApply", mApplyStatic);

	if (this->diffuseTexture != nullptr)
	{
		this->diffuseTexture->SetTextureSlot(0);
		shader->SetUniform1i("texture_diffuse", 0);
		this->diffuseTexture->Bind();
	}

	/*if (this->staticTexture != nullptr)
	{
		this->staticTexture->SetTextureSlot(1);
		shader->SetUniform1i("static_texture", 1);
		this->staticTexture->Bind();
	}*/

	if (!applyEffects) return;

	HandleFlicker();
	HandleStatic();
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

void SciFiScreenMaterial::HandleStatic()
{
	if (mApplyStatic)
	{
		mStaticTimeStep += Timer::GetInstance().deltaTime * mFlickerResetSpeed;

		if (mStaticTimeStep > mStaticDuration)
		{
			mStaticTimeStep = 0;
			mApplyStatic = false;
		}
	}
	else
	{
		mStaticTimeStep += Timer::GetInstance().deltaTime * mFlickerResetSpeed;

		if (mStaticTimeStep > mStaticInterval)
		{
			ApplyStatic();
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

void SciFiScreenMaterial::ApplyStatic()
{
	mApplyStatic = true;

	mStaticTimeStep = 0;
	mStaticInterval = MathUtils::GetRandomFloatNumber(mStaticIntervalRange.x, mStaticIntervalRange.y);
	mStaticDuration = MathUtils::GetRandomFloatNumber(mStaticDurationRange.x, mStaticDurationRange.y);
}

void SciFiScreenMaterial::OnPropertyDraw()
{
	ImGuiUtils::DrawFloat("FlickerTimeStep", mFlickerTimeStep);
	ImGuiUtils::DrawFloat("FlickerValue", mFlickerValue);
}

