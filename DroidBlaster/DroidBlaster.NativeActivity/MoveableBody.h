#ifndef _PACKT_MOVEABLEBODY_HPP_
#define _PACKT_MOVEABLEBODY_HPP_

#include "InputManager.h"
#include "PhysicsManager.h"
#include "Types.h"

class MoveableBody {
public:
	MoveableBody(android_app* pApplication,
		InputManager& pInputManager, PhysicsManager& pPhysicsManager);

	PhysicsBody* registerMoveableBody(Location& pLocation,
		int32_t pSizeX, int32_t pSizeY);

	void initialize();
	void update();

private:
	PhysicsManager& mPhysicsManager;
	InputManager& mInputManager;

	PhysicsBody* mBody;
};
#endif