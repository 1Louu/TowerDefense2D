#ifndef SCENEMANAGER_H__
#define SCENEMANAGER_H__
#include <map>
#include <string>
#include "Scene.h"

class SceneManager {
	std::map<std::string, Scene*> mp;
	std::string current;
	static SceneManager* m_instance;
public:
	SceneManager();
	static SceneManager* GetInstance();
	void ChangeScene(std::string nameScene);
	Scene* GetCurrentScene();
	void AddScene(std::string name, Scene* scene);
};

#endif

