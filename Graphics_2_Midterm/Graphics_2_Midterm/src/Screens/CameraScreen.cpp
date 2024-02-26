#include "CameraScreen.h"
#include <Graphics/MathUtils.h>

using namespace MathUtilities;

void CameraScreen::SetScreenOn()
{
	mIsCameraOn = true;

	ChangeCamera();
}

void CameraScreen::SetSecurityCamera(SecurityCameras* securityCameras)
{
	this->mSecurityCameras = securityCameras;
}

void CameraScreen::Update(float deltaTime)
{
	if (!mIsCameraOn) return;

	mCurrentTime += deltaTime;

	if (mCurrentTime > mChangeTime)
	{
		ChangeCamera();
	}
}

void CameraScreen::SetScreenOff()
{
	mIsCameraOn = false;
	BaseScreen::SetScreenOff();

}

void CameraScreen::ChangeCamera()
{
	mCurrentTime = 0;
	mChangeTime = MathUtils::GetRandomFloatNumber(3, 6);
	meshes[0]->material->AsMaterial()->diffuseTexture = mSecurityCameras->GetRandomCamera()->renderTexture;
}
