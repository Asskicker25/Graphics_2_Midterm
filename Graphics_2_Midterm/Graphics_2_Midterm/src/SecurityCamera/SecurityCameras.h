#pragma once
#include <Graphics/EntityManager/Entity.h>
#include <Graphics/GameCamera.h>

class SecurityCameras : public Entity
{

public:
	SecurityCameras();

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;

	Camera* GetRandomCamera();

private:

	void SetupCameras();

	std::vector<GameCamera* > mListOfRenderCameras;
};

