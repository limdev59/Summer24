#pragma once

enum class KEY_TYPE {
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,
	ALT,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};

struct keyInfo {
	KEY_TYPE	state;
	bool		prev;
};

class KeyMgr {
	SINGLE(KeyMgr);
private:
	vector<keyInfo> vecKey;

public:
	void Init();
	void Update();

public:
	KEY_TYPE GetKeyState(KEY key) { return vecKey[(int)key].state; }
};

