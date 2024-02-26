#pragma once
#include "BaseScreen.h"
#include "../SecurityCamera/SecurityCameras.h"

class CameraScreen : public BaseScreen
{
public:
	CameraScreen() = default;
	CameraScreen(const std::string& path) : BaseScreen(path) {}

	// Inherited via BaseScreen
	void SetScreenOn() override;

	void SetSecurityCamera(SecurityCameras* securityCameras);
	virtual void Update(float deltaTime) override;
	virtual void SetScreenOff();

private:
	void ChangeCamera();

	SecurityCameras* mSecurityCameras = nullptr;

	bool mIsCameraOn = false;

	float mCurrentTime = 0;
	float mChangeTime = 0;

	glm::vec2 mChangeTimeRange = glm::vec2(1, 4);
};

