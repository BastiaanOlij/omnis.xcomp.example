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
	OXFNVobject		lvNVObject;
	OXFcomponent	lvComponent;
	
	// add out object definitions here
	lvNVObject.objectID = 2100;
	lvNVObject.flags = 0;
	lvNVObject.groupResID = 0;
	lvNVObject.newObjectFunction = (void * (*)()) &(oNVExample::newObject);
	lvNVObject.destructObjectFunc = (void (*)(oBaseNVComponent*)) &(oNVExample::destructObj);
	
	mObjects.push(&lvNVObject);
	
	// add our component definitions here...
	lvComponent.componentType = cObjType_Basic;
	lvComponent.componentID = 2000;
	lvComponent.bitmapID = 1;
	lvComponent.newObjectFunction = (void * (*)()) &(oExample::newObject);
	lvComponent.destructObjectFunc = (void (*)(oBaseVisComponent*)) &(oExample::destructObj);
		
	mComponents.push(&lvComponent);
	
	return oXCompLib::ecm_connect();
};

