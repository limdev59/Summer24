#pragma once

class CObject;
class CScene
{
private:
	vector<CObject*>			arrObj[(UINT)GROUP_TYPE::END];
	wstring						strName;
public:
	CScene();
	virtual ~CScene();

	void Update();
	void Render(HDC hdc);

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void SetName(const wstring& _strName) {
		strName = _strName;

	}
	const wstring& GetName() { return strName; }

protected:
	void AddObject(CObject* obj, GROUP_TYPE type) {
		arrObj[(UINT)type].push_back(obj);
	}
};

