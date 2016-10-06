#include "InputManager.h"
#include "Log.h"

#include "android_native_app_glue.h"
#include <cmath>

InputManager::InputManager(android_app* pApplication, GraphicsManager& pGraphicsManager) :
	mApplication(pApplication), mGraphicsManager(pGraphicsManager),
	mDirectionX(0.0f), mDirectionY(0.0f),
	mRefPoint(NULL) {

}

void InputManager::start() {
	Log::info("PACKT Startin InputManager.");
	mDirectionX = 0.0f; mDirectionY = 0.0f;
	//changed page 334 top to getRenderHeight...
	mScaleFactor = float(mGraphicsManager.getRenderWidth()) / float(mGraphicsManager.getRenderHeight());
	//corrections?
	mScaleFactor = 1;
}

bool InputManager::onTouchEvent(AInputEvent* pEvent) {
	static const float TOUCH_MAX_RANGE = 65.0f; //in game units

	if (mRefPoint != NULL) {
		if (AMotionEvent_getAction(pEvent) == AMOTION_EVENT_ACTION_MOVE) {
			float x = AMotionEvent_getX(pEvent, 0) * mScaleFactor;
			//getRenderHeight change
			float y = (float(mGraphicsManager.getRenderHeight()) - AMotionEvent_getY(pEvent, 0)) * mScaleFactor;
			//Needs a conversion to proper coordinates
			//(origin at bottome/left). Only moveY needs it.
			float moveX = x - mRefPoint->x;
			float moveY = y - mRefPoint->y;
			float moveRange = 6; //sqrt((moveX * moveY) + (moveY * moveY));
			moveRange = std::sqrt((moveX * moveY) + (moveY * moveY));

			//corrections?


			if (moveRange > TOUCH_MAX_RANGE) {
				float cropFactor = TOUCH_MAX_RANGE / moveRange;
				moveX *= cropFactor; moveY *= cropFactor;
			}

			mDirectionX = moveX / TOUCH_MAX_RANGE;
			mDirectionY = moveY / TOUCH_MAX_RANGE;
		}
		else {
			mDirectionX = 0.0f; mDirectionY = 0.0f;
		}
	}
	return true;
}