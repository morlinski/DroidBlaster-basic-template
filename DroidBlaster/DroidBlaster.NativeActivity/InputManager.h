#ifndef _PACKT_INPUTMANAGER_HPP_
#define _PACKT_INPUTMANAGER_HPP_

#include "GraphicsManager.h"
#include "InputHandler.h"
#include "Types.h"

#include "android_native_app_glue.h"

class InputManager : public InputHandler {
public:
	InputManager(android_app* pApplication, GraphicsManager& pGraphicsManager);

	float getDirectionX() { return mDirectionX; };
	float getDirectionY() { return mDirectionY; };
	void setRefPoint(Location* pRefPoint) { mRefPoint = pRefPoint; };

	void start();
	
protected:
	bool onTouchEvent(AInputEvent* pEvent);

private:
	android_app* mApplication;
	GraphicsManager& mGraphicsManager;

	//Input Values.
	float mScaleFactor;
	float mDirectionX, mDirectionY;
	//Reference point to evaluate touch distance.
	Location* mRefPoint;
};
#endif