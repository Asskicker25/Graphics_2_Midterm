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

};

