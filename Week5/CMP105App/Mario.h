#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnim;
protected:

};

