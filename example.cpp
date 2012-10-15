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
	OXFcomponent	lvComponent;
	
	// add our component definitions here...
	lvComponent.componentType		= cObjType_NVObject;
	lvComponent.componentID			= 2100;
	lvComponent.bitmapID			= 0;
	lvComponent.flags				= 0;
	lvComponent.groupResID			= 0;
	lvComponent.newObjectFunction	= (void * (*)()) &(oNVExample::newObject);
	lvComponent.mProperties			= oNVExample::properties();
	lvComponent.mMethods			= oNVExample::methods();
	
	addComponent(lvComponent);
		
	lvComponent.componentType		= cObjType_Basic;
	lvComponent.componentID			= 2000;
	lvComponent.bitmapID			= 1;
	lvComponent.flags				= 0;
	lvComponent.groupResID			= 0;
	lvComponent.newObjectFunction	= (void * (*)()) &(oExample::newObject);
	lvComponent.mProperties			= oExample::properties();
	lvComponent.mMethods			= oExample::methods();
		
	addComponent(lvComponent);
	
	return oXCompLib::ecm_connect();
};

