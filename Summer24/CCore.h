#pragma once
class CCore
{
	SINGLE(CCore);
	HWND			handle;
	Vec2			ptResolution;
	HDC				hdc;

	void			Update();
	void			Render();

public:
	int				Init(HWND _hwnd, Vec2 _pt);
	void			Progress();

	HWND			GetMainHandle() { return handle; }
};
// 싱글톤 : 하나의 인스턴스를 만들기 위해 사용