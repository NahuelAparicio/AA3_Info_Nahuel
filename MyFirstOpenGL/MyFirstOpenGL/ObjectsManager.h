#pragma once
#include "GameObject.h"
#include "MeshRenderer.h"

// -- Manages the Dynamic GameObjects

class ObjectsManager
{
public:
	ObjectsManager(GameObject* sun, GameObject* moon);
	void UpdateObjects();
	void RenderObjects(glm::mat4 view);
	void UpdateOrbit(GameObject* object, float elapsedTime);
private:
	GameObject* _sun;
	GameObject* _moon;
	float _angularSpeed;
};
