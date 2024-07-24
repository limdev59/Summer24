#include "pch.h"
#include "CScene.h"
#include "CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
		for (size_t j = 0; j < arrObj[i].size(); ++j)
			delete arrObj[i][j];
	//arrObj[i]�׷� ������ j��ü ����
}

void CScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
		for (size_t j = 0; j < arrObj[i].size(); ++j)
			arrObj[i][j]->Update();
}

void CScene::Render(HDC hdc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
		for (size_t j = 0; j < arrObj[i].size(); ++j)
			arrObj[i][j]->Render(hdc);
}

void CScene::Enter()
{
}

void CScene::Exit	()
{
}
