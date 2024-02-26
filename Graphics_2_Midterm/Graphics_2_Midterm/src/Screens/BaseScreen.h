#pragma once
#include <Graphics/Model.h>

class BaseScreen : public Model
{
public:
	BaseScreen() = default;
	BaseScreen(const std::string& path) : Model(path) {}
	
	virtual void SetScreenOn() = 0;
	virtual void SetScreenOff();

	virtual void Update(float deltaTime) override {};

	Texture* blackTexture = nullptr;

};

