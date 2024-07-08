#pragma once

class CCore {
	SINGLE(CCore);
private:
	HWND			handle;
	POINT			ptResolution;
	HDC				hdc;

	HBITMAP			hBit;
	HDC				mdc;

	void			Update();
	void			Render();

public:
	int				Init(HWND _handle, Vec2 _pt);
	void			Progress();

	HWND			GetMainHandle() { return handle; }
};

// 싱글톤 : 하나의 인스턴스를 만들기 위해 사용