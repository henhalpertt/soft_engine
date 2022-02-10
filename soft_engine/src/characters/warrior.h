#pragma once
#include "character.h"
#include "../animation/animation.h"
#include "../physics/rigid_body.h"

class Warrior : public Character
{
public:
	Warrior() {};
	Warrior(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	/*int m_Row;
	int m_Frame;
	int m_FrameCount;
	int m_AnimationSpeed; */

	Animation* m_Animation;
	RigidBody* m_RigidBody;
};