#include "pch.h"
#include "CCore.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

#include "CObject.h"



CCore::CCore()
	: handle(0)
	, ptResolution{}
	, hdc(0)
	, mdc(0)
	, hBit(0)
{

}

CCore::~CCore()
{
	ReleaseDC(handle, hdc);

	DeleteDC(mdc);
	DeleteObject(hBit);
}

void CCore::Update()
{
	TimeMgr::Instance()->Update();
	KeyMgr::Instance()->Update();
	SceneMgr::Instance()->Update();
}

void CCore::Render()
{
	Rectangle(mdc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	SceneMgr::Instance()->Render(mdc);
	
	BitBlt(hdc, 0, 0, ptResolution.x, ptResolution.y,
		mdc, 0, 0, SRCCOPY);

	TimeMgr::Instance()->Render();
}

int CCore::Init(HWND _handle, Vec2 _pt)
{
	handle = _handle;
	ptResolution.x = _pt.x;
	ptResolution.y = _pt.y;

	RECT rt = { 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(handle, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	hdc = GetDC(handle);

	hBit = CreateCompatibleBitmap(hdc, ptResolution.x, ptResolution.y);
	mdc = CreateCompatibleDC(hdc);

	HBITMAP oldBit = (HBITMAP)SelectObject(mdc, hBit);
	DeleteObject(oldBit);

	// Manager Init
	TimeMgr::Instance()->Init();
	KeyMgr::Instance()->Init();
	SceneMgr::Instance()->Init();

	return S_OK;
}

void CCore::Progress()
{
	Update();
	Render();
}
