/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  example.cpp
 *  Example implementation of our library class
 *
 *  Bastiaan Olij
 */

#include "example.h"

qint mainlib::ecm_connect(void) {
	qlong			lvFlags = oXCompLib::ecm_connect();
	OXFcomponent	lvComponent;
	
	// add our component definitions here...
	lvComponent.componentType = cObjType_Basic;
	lvComponent.componentID = 2000;
	lvComponent.bitmapID = 1;
	lvComponent.newObjectFunction = (void * (*)()) &(oExample::newObject);
		
	mComponents.push(&lvComponent);
	
	return lvFlags; // also return EXT_FLAG_NVOBJECTS if we have non-visual objects
};

