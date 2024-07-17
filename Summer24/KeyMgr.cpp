#include "pch.h"
#include "KeyMgr.h"

#include "CCore.h"

int arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	VK_MENU, // ALT,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN, // ENTER,
	VK_ESCAPE, // ESC,
	//LAST,
};

KeyMgr::KeyMgr()
{

}

KeyMgr::~KeyMgr()
{

}

void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i) {
		vecKey.emplace_back(keyInfo{ KEY_TYPE::NONE, false });
	}
}

void KeyMgr::Update()
{
	HWND hwnd = GetFocus();

	if (nullptr != hwnd) {
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			if (GetAsyncKeyState(arrVK[i]) & 0x8000) { // 현재 눌림
				if (vecKey[i].prev) { // 이전에 눌림
					vecKey[i].state = KEY_TYPE::HOLD;
				}
				else { // 이전에 안눌림
					vecKey[i].state = KEY_TYPE::TAP;
				}
				vecKey[i].prev = true;
			}
			else { // 현재 안눌림
				if (vecKey[i].prev) { // 이전에 눌림
					vecKey[i].state = KEY_TYPE::AWAY;
				}
				else { // 이전에 안눌림
					vecKey[i].state = KEY_TYPE::NONE;
				}
				vecKey[i].prev = false;
			}
		}
	}
	else {
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			vecKey[i].prev = false;
			if (KEY_TYPE::TAP == vecKey[i].state ||
				KEY_TYPE::HOLD == vecKey[i].state)
				vecKey[i].state = KEY_TYPE::NONE;
			else if (KEY_TYPE::AWAY == vecKey[i].state)
				vecKey[i].state = KEY_TYPE::NONE;

		}
	}
}
