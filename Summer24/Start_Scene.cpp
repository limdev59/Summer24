#include "pch.h"
#include "Start_Scene.h"

#include "CObject.h"
#include "Player.h"

Start_Scene::Start_Scene()
{
}

Start_Scene::~Start_Scene()
{
}

void Start_Scene::Enter()
{
	CObject* obj = new Player;
	obj->SetPos(Vec2(640.f, 348.f));
	obj->SetScale(Vec2(50.f, 50.f));

	AddObject(obj, GROUP_TYPE::DEFAULT);

	obj = new CObject;
	obj->SetPos(Vec2(640.f, 348.f));
	obj->SetScale(Vec2(50.f, 50.f));
	AddObject(obj, GROUP_TYPE::DEFAULT);

}

void Start_Scene::Exit()
{
}
