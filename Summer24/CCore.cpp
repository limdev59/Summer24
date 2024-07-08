#include "pch.h"
#include "CCore.h"

#include "TimeMgr.h"
#include "CObject.h"

CObject obj;

CCore::CCore()
	: handle(0)
	, ptResolution{}
	, hdc(0)
{

}

CCore::~CCore()
{
	ReleaseDC(handle, hdc);
}

void CCore::Update()
{
	Vec2 vPos = obj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		vPos.x -= 200.f * TimeMgr::Instance()->getfDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		vPos.x += 200.f * TimeMgr::Instance()->getfDT();
	}

	obj.SetPos(vPos);
}

void CCore::Render()
{
	Vec2 vPos = obj.GetPos();
	Vec2 vScale = obj.GetScale();
	Rectangle(hdc, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.x - vScale.y / 2)
		, (int)(vPos.x + vScale.x / 2)
		, (int)(vPos.y + vScale.y / 2)
	);
}

int CCore::Init(HWND _handle, Vec2 _pt)
{
	handle = _handle;
	ptResolution = _pt;

	RECT rt = { 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE);
	SetWindowPos(handle, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	hdc = GetDC(handle);

	obj.SetPos(Vec2{ ptResolution.x / 2, ptResolution.y / 2 });
	obj.SetScale(Vec2(100, 100));

	// Manager Init
	TimeMgr::Instance()->Init();

	return S_OK;
}

void CCore::Progress()
{
	TimeMgr::Instance()->Update();
	Update();
	Render();
}
