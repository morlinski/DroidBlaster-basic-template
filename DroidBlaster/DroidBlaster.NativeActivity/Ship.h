#ifndef _PACKT_SHIP_HPP_
#define _PACKT_SHIP_HPP_

#include "GraphicsManager.h"

class Ship {
public:
	Ship(android_app* pApplication, GraphicsManager& pGraphicsManager);

	void registerShip(GraphicsElement* pGraphics);

	void initialize();

private:
	GraphicsManager& mGraphicsManager;
	
	GraphicsElement* mGraphics;
};
#endif