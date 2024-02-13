#pragma once
#include "IScene.h"
#include <memory>

    class StageScene : public IScene {
private:
	
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};