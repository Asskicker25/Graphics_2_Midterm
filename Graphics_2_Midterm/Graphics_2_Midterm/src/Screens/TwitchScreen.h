#pragma once
#include "BaseScreen.h"

class TwitchScreen : public BaseScreen
{
public:
	TwitchScreen() = default;
	TwitchScreen(const std::string& path); 

	// Inherited via BaseScreen
	void SetScreenOn() override;
	virtual void SetScreenOff();
	virtual void Update(float deltaTime) override;


private:
	bool isCameraOn = false;

	float mCurrentTimeStep = 0;
	float mSwitchInterval = 0;

	glm::vec2 mSwitchIntervalRange = glm::vec2(2, 5);

	Texture* staticTexture = nullptr;
	std::vector<Texture*> scifiTextures;


	Texture* GetRandomTexture();
	void SwitchTexture();
};

