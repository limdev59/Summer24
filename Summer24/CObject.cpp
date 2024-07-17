#include "pch.h"
#include "CObject.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

CObject::CObject()
	: vPos{}
	, vScale{}
{
}

CObject::~CObject()
{
}

void CObject::Update()
{

}

void CObject::Render(HDC hdc)
{
	Rectangle(hdc,
		(int)(vPos.x - vScale.x / 2.f),
		(int)(vPos.y - vScale.y / 2.f),
		(int)(vPos.x + vScale.x / 2.f),
		(int)(vPos.y + vScale.y / 2.f));
}
