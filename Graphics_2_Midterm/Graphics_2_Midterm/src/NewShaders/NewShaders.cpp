#include "NewShaders.h"

NewShaders& NewShaders::GetInstance()
{
	static NewShaders instance;
	return instance;
}

void NewShaders::Initialize()
{
	windowShader = new Shader("res/Shader/WindowShader.shader");
	windowShader->blendMode = Shader::ALPHA_BLEND;
	windowShader->applyInverseModel = true;

	screenShader = new Shader("res/Shader/ScreenShader.shader");
	screenShader->blendMode = Shader::ALPHA_OPAQUE;
	screenShader->applyInverseModel = true;
}
