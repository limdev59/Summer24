#include "pch.h"
#include "CCore.h"

#include "TimeMgr.h"

#include "CObject.h"

CObject obj;

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
	Vec2 vPos = obj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		vPos.x -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		vPos.x += 200.f * fDT;
	}

	obj.SetPos(vPos);
}

void CCore::Render()
{
	Rectangle(mdc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	Vec2 vPos = obj.GetPos();
	Vec2 vScale = obj.GetScale();

	Rectangle(mdc, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, (int)(vPos.x + vScale.x / 2)
		, (int)(vPos.y + vScale.y / 2));

	BitBlt(hdc, 0, 0, ptResolution.x, ptResolution.y,
		mdc, 0, 0, SRCCOPY);
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

	obj.SetPos(Vec2((float)(ptResolution.x / 2), (float)(ptResolution.y / 2)));
	obj.SetScale(Vec2(100, 100));

	// Manager Init
	TimeMgr::Instance()->Init();

	return S_OK;
}

void CCore::Progress()
{
	TimeMgr::Instance()->Update();
	TimeMgr::Instance()->Render();
	Update();
	Render();
}
