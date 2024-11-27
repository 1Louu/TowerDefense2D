#include "Scene.h"

void Scene::update(float dt) {
	for (int i = 0; i < VisualEntityList.size(); i++) {
		VisualEntityList[i]->update(dt);
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < VisualEntityList.size(); i++) {
		target.draw(*(VisualEntityList[i]));

	}
}

void Scene::resetscene()
{
	for (int i = 0; i < VisualEntityList.size(); i++) {
		delete VisualEntityList[i];
	}
	VisualEntityList.clear();
}
