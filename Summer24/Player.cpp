#include "pch.h"
#include "Player.h"

#include "KeyMgr.h"
#include "TimeMgr.h"


void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_TYPE::HOLD) {
		vPos.y -= 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_TYPE::HOLD) {
		vPos.x -= 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_TYPE::HOLD) {
		vPos.y += 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_TYPE::HOLD) {
		vPos.x += 200.f * DT;
	}
	SetPos(vPos);

}
