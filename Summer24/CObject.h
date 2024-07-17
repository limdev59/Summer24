#pragma once
class CObject
{
private:
	Vec2 vPos;
	Vec2 vScale;
public:
	CObject();
	~CObject();

	void SetPos(Vec2 _pos) { vPos = _pos; }
	void SetScale(Vec2 _Scale) { vScale = _Scale; }

	Vec2 GetPos() { return vPos; }
	Vec2 GetScale() { return vScale; }

	virtual void Update();
	virtual void Render(HDC hdc);
};

