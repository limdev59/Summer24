#pragma once
class CScene;
class SceneMgr
{
	SINGLE(SceneMgr)
private:
	CScene* arrScene[(UINT)SCENE_TYPE::END];
	CScene* currentScene;

public:
	void				Init();
	void				Update();
	void				Render(HDC hdc);
};

