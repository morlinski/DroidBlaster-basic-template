#ifndef _PACKT_DROIDBLASTER_HPP_
#define _PACKT_DROIDBLASTER_HPP_

#include "ActivityHandler.h"
#include "Asteroid.h"
#include "EventLoop.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "MoveableBody.h"
#include "PhysicsManager.h"
#include "Ship.h"
#include "TimeManager.h"
#include "Types.h"

class DroidBlaster : public ActivityHandler {
public:
	DroidBlaster(android_app* pApplication);
	void run();

protected:
	status onActivate();
	void onDeactivate();
	status onStep();

	void onStart();

	void onResume();
	void onPause();
	void onStop();
	void onDestroy();

	void onSaveInstanceState(void** pData, size_t* pSize);
	void onConfigurationChanged();
	void onLowMemory();

	void onCreateWindow();
	void onDestroyWindow();
	void onGainFocus();
	void onLostFocus();

private:
	TimeManager mTimeManager;
	GraphicsManager mGraphicsManager;
	PhysicsManager mPhysicsManager;
	InputManager mInputManager;
	EventLoop mEventLoop;

	Asteroid mAsteroids;
	Ship mShip;
	MoveableBody mMoveableBody;
};
#endif