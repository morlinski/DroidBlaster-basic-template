#ifndef _PACKT_ASTEROID_HPP_
#define _PACKT_ASTEROID_HPP_

#include "GraphicsManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"
#include "Types.h"

class Asteroid {
public:
	Asteroid(android_app* pApplication,
		TimeManager& pTimeManager, GraphicsManager& pGraphicsManager, PhysicsManager& pPhysicsManager);
	void registerAsteroid(Location& pLocation, int32_t pSizeX, int32_t pSizeY);
	void initialize();
	void update();

private:
	void spawn(PhysicsBody* pBody);

	TimeManager& mTimeManager;
	GraphicsManager& mGraphicsManager;
	PhysicsManager& mPhysicsManager;

	PhysicsBody* mBodies[1024];
	int32_t mBodyCount;
	float mMinBound;
	float mUpperBound, mLowerBound;
	float mLeftBound, mRightBound;
};
#endif