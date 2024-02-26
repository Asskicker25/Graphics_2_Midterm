#pragma once

#include <Graphics/EntityManager/EntityManager.h>
#include <Graphics/Model.h>


class Interior : public Entity
{
public:
	Interior();


	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;

private:
	Model* centerConsole = nullptr;
	Model* cornerConsoleLeft = nullptr;
	Model* cornerConsoleRight = nullptr;

	Model* centerConsoleScreen_1 = nullptr;
	Model* centerConsoleScreen_2 = nullptr;
	Model* centerConsoleScreen_3 = nullptr;

	Model* leftCornerConsoleScreen_1 = nullptr;
	Model* leftCornerConsoleScreen_2 = nullptr;

	Model* rightCornerConsoleScreen_1 = nullptr;
	Model* rightCornerConsoleScreen_2 = nullptr;

	glm::vec3 leftConsolePos = glm::vec3(-10.0f, 0.0f, 5.0f);
	glm::vec3 rightConsolePos = glm::vec3(5.0f, 0.0f, 5.0f);
	glm::vec4 alphaBlendColor = glm::vec4(1.0f, 1.0f, 1.0f, 0.2f);

};

