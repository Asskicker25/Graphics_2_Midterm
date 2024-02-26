#pragma once
#include "BaseScreen.h"

class TwitchScreen : public BaseScreen
{
public:
	TwitchScreen() = default;
	TwitchScreen(const std::string& path) : BaseScreen(path) {}

	// Inherited via BaseScreen
	void SetScreenOn() override;
};

