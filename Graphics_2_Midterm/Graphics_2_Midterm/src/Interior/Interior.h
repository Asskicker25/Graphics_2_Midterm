#pragma once

#include <Graphics/EntityManager/EntityManager.h>
#include <Graphics/Model.h>
#include <Graphics/InputManager/InputManager.h>
#include "../SecurityCamera/SecurityCameras.h"
#include "../Screens/BaseScreen.h"

class Interior : public Entity, public iInputListener
{
public:

	Interior(SecurityCameras* securtiyCameras);


	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;


private:
	void LoadConsoles();
	void LoadWalls();
	void LoadFloors();
	void LoadLights();
	
	void ChangeTexture(Model* model, BaseTexture* texture);
	
	void SetupScreens();
	void ToggleSecurityCamera();

	bool isCameraOn = true;

	SecurityCameras* securityCameras = nullptr;

	Texture* blackTexture = nullptr;

	Model* centerConsole = nullptr;
	Model* cornerConsoleLeft = nullptr;
	Model* cornerConsoleRight = nullptr;

	BaseScreen* centerConsoleScreen_1 = nullptr;
	Model* centerConsoleScreen_2 = nullptr;
	BaseScreen* centerConsoleScreen_3 = nullptr;

	BaseScreen* leftCornerConsoleScreen_1 = nullptr;
	Model* leftCornerConsoleScreen_2 = nullptr;

	BaseScreen* rightCornerConsoleScreen_1 = nullptr;
	Model* rightCornerConsoleScreen_2 = nullptr;

	glm::vec3 leftConsolePos = glm::vec3(-10.0f, 0.0f, 5.0f);
	glm::vec3 rightConsolePos = glm::vec3(5.0f, 0.0f, 5.0f);
	glm::vec4 alphaBlendColor = glm::vec4(1.0f, 1.0f, 1.0f, 0.2f);
	//glm::vec4 screenColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);


	std::vector<BaseScreen*> mListOfScreens;


	// Inherited via iInputListener
	void OnKeyPressed(const int& key) override;
	void OnKeyReleased(const int& key) override;
	void OnKeyHeld(const int& key) override;

};

