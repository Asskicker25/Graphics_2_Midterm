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

private:

	Texture* scifi_01 = nullptr;
};

