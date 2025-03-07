#include "pch.h"
#include "SceneMgr.h"

#include "Start_Scene.h"
SceneMgr::SceneMgr() 
	: arrScene{}
	, currentScene(nullptr)
{
}
SceneMgr::~SceneMgr() 
{
}

void SceneMgr::Init()
{
	// Scene 생성
	arrScene[(UINT)SCENE_TYPE::START] = new Start_Scene;
	arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	
	// 현재 씬 생성
	currentScene = arrScene[(UINT)SCENE_TYPE::START];
	currentScene->Enter();

}

void SceneMgr::Update()
{
	currentScene->Update();
}

void SceneMgr::Render(HDC hdc)
{
	currentScene->Render(hdc);
}
