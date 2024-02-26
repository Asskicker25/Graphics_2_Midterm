#pragma once
#include <Graphics/Shaders/Shader.h>

class NewShaders
{
public:
	static NewShaders& GetInstance();

	void Initialize();

	Shader* windowShader = nullptr;
	Shader* screenShader = nullptr;
	Shader* scifiShader = nullptr;
};

