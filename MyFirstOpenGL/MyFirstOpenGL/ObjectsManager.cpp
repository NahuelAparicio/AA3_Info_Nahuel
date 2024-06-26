#include "ObjectsManager.h"
#include "Engine.h"
ObjectsManager::ObjectsManager(GameObject* sun, GameObject* moon) : _sun(sun), _moon(moon)
{
    _camera = new Camera();
    _lantern = new Lantern();
	_sun->GetComponent<Transform>()->_position = { -100, 0, 0 };
	_moon->GetComponent<Transform>()->_position = { 100, 0, 0 };
	_moon->GetComponent<Transform>()->_scale = { 0.5f, 0.5f, 0.5f };
    _angularSpeed = 2.0f * 3.14f / 40.f;
}

void ObjectsManager::UpdateObjects()
{
    float elapsedTime = Engine::GetInstance().GetTimeManager()->GetDeltaTime();

    UpdateOrbit(_sun, elapsedTime);
    UpdateOrbit(_moon, elapsedTime);

    _lantern->UpdateLantern(_camera->GetPosition(), _camera->GetVectorFront());
}

// -- Updates GameObject position doing a orbit

void ObjectsManager::UpdateOrbit(GameObject* object, float elapsedTime)
{
    glm::vec3 currentPos = object->GetComponent<Transform>()->_position;

    // Angle based on time and angular speed
    float angle = _angularSpeed * elapsedTime;

    float x = currentPos.x * cos(angle) - currentPos.y * sin(angle);
    float y = currentPos.x * sin(angle) + currentPos.y * cos(angle);

    object->GetComponent<Transform>()->_position = { x, y, 0 };
}

void ObjectsManager::RenderObjects(glm::mat4 view)
{
	_sun->GetComponent<MeshRenderer>()->Render(view);
	_moon->GetComponent<MeshRenderer>()->Render(view);
}

