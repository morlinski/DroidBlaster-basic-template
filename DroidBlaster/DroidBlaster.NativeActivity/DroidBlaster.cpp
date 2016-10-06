#include "DroidBlaster.h"
#include "Log.h"

#include <unistd.h>

static const int32_t SHIP_SIZE = 64;
static const int32_t ASTEROID_COUNT = 8;
static const int32_t ASTEROID_SIZE = 32;

DroidBlaster::DroidBlaster(android_app* pApplication) :
	mTimeManager(),
	mGraphicsManager(pApplication),
	mPhysicsManager(mTimeManager, mGraphicsManager),
	mInputManager(pApplication, mGraphicsManager),
	mEventLoop(pApplication, *this, mInputManager), 
	mAsteroids(pApplication, mTimeManager, mGraphicsManager, mPhysicsManager),
	mShip(pApplication, mGraphicsManager),
	mMoveableBody(pApplication, mInputManager, mPhysicsManager)
{
	Log::info("PACKT creating DroidBlaster");

	GraphicsElement* shipGraphics = mGraphicsManager.registerElement(SHIP_SIZE, SHIP_SIZE);

	mMoveableBody.registerMoveableBody(shipGraphics->location, SHIP_SIZE, SHIP_SIZE);

	mShip.registerShip(shipGraphics);

	for (int32_t i = 0; i < ASTEROID_COUNT; ++i) {
		GraphicsElement* asteroidGraphics = mGraphicsManager.registerElement(ASTEROID_SIZE, ASTEROID_SIZE);
		mAsteroids.registerAsteroid(
			asteroidGraphics->location, ASTEROID_SIZE, ASTEROID_SIZE);
	}
}

void DroidBlaster::run() {
	mEventLoop.run();
}

status DroidBlaster::onActivate() {
	Log::info("PACKT activating DroidBlaster");

	if (mGraphicsManager.start() != STATUS_OK) return STATUS_KO;
	mInputManager.start();

	mAsteroids.initialize();
	mShip.initialize();
	mMoveableBody.initialize();

	mTimeManager.reset();
	return STATUS_OK;
}

void DroidBlaster::onDeactivate() {
	Log::info("PACKT deactivating DroidBlaster");
}

status DroidBlaster::onStep() {
	Log::info("PACKT starting step");
	/*usleep(300000);*/

	mTimeManager.update();
	mPhysicsManager.update();

	mAsteroids.update();
	mMoveableBody.update();

	return mGraphicsManager.update();
	Log::info("PACKT stepping done");
	/*return STATUS_OK;*/
}

void DroidBlaster::onStart() {
	Log::info("PACKT onStart()");
}

//following are base on onStart()

void DroidBlaster::onResume() {
	Log::info("PACKT onStart()onResume()");
}
void DroidBlaster::onPause() {
	Log::info("PACKT onStart()onPause()");
}
void DroidBlaster::onStop() {
	Log::info("PACKT onStart()onStop()");
}
void DroidBlaster::onDestroy() {
	Log::info("PACKT onStart()onDestroy()");
}

void DroidBlaster::onSaveInstanceState(void** pData, size_t* pSize) {
	Log::info("PACKT onStart()onSaveInstanceState(void** pData, size_t* pSize)");
}
void DroidBlaster::onConfigurationChanged() {
	Log::info("PACKT onStart():onConfigurationChanged()");
}
void DroidBlaster::onLowMemory() {
	Log::info("PACKT onStart()onLowMemory()");
}

void DroidBlaster::onCreateWindow() {
	Log::info("PACKT onStart()onCreateWindow()");
}
void DroidBlaster::onDestroyWindow() {
	Log::info("PACKT onStart()onDestroyWindow()");
}
void DroidBlaster::onGainFocus() {
	Log::info("PACKT onStart()onGainFocus()");
}
void DroidBlaster::onLostFocus() {
	Log::info("PACKT onStart()onLostFocus()");
}