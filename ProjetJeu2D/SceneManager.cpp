#include "SceneManager.h"

SceneManager* SceneManager::m_instance = nullptr; // Juste pour d�montrer comment �a marche. 

SceneManager::SceneManager() {
	if (m_instance == nullptr) { // le but de ce condition est de s'assurer qu'on a le m�me singleton 
		m_instance = this;
	}
}

SceneManager* SceneManager::GetInstance() {
	if (m_instance == nullptr) { // le but de ce condition est de s'assurer qu'on a le m�me singleton 
		m_instance = new SceneManager();
	}
	return m_instance;
}

void SceneManager::ChangeScene(std::string nameScene)
{

	current = nameScene;
	mp[current]->resetscene();
	mp[current]->init();
	//reset puis init de scene
}

Scene* SceneManager::GetCurrentScene()
{
	return mp[current];
}

void SceneManager::AddScene(std::string name, Scene* scene)
{
	mp[name] = scene;
}


