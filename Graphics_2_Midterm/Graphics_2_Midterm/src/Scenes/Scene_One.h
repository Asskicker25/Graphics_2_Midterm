#pragma once
#include <Graphics/Scene/BaseScene.h>
#include <Graphics/ApplicationWindow.h>

using namespace Scene;

class Scene_One : public BaseScene
{
	// Inherited via BaseScene
	void Start() override;
	void Update() override;
	void Render() override;
};

