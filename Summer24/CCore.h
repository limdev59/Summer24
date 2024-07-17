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

// �̱��� : �ϳ��� �ν��Ͻ��� ����� ���� ���