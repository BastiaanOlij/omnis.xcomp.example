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

qshort mainlib::major() {
	return OMNISSDK;
};

qshort mainlib::minor() {
	return 104;
};

/* see omnis.xcomp.framework\oXCompLib.h for methods to implement here */
qint mainlib::ecm_connect(void) {
	OXFcomponent lvComponent;

	// add our component definitions here...
	lvComponent.componentType = cObjType_NVObject;
	lvComponent.componentID = 2100;
	lvComponent.bitmapID = 0;
	lvComponent.flags = 0;
	lvComponent.groupResID = 0;
	lvComponent.newObjectFunction = (void *(*)()) & (oNVExample::newObject);
	lvComponent.mProperties = oNVExample::properties();
	lvComponent.mMethods = oNVExample::methods();
	lvComponent.mEventMethodID = 0;
	lvComponent.mEvents = oNVExample::events();

	addComponent(lvComponent);

	lvComponent.componentType = cObjType_Basic;
	lvComponent.componentID = 2000;
	lvComponent.bitmapID = 1;
	lvComponent.flags = 0;
	lvComponent.groupResID = 0;
	lvComponent.newObjectFunction = (void *(*)()) & (oExample::newObject);
	lvComponent.mProperties = oExample::properties();
	lvComponent.mMethods = oExample::methods();
	lvComponent.mEventMethodID = 0;
	lvComponent.mEvents = oExample::events();

	addComponent(lvComponent);

	return oXCompLib::ecm_connect();
};

qbool mainlib::ecm_disconnect(void) {
	// nothing to do here..

	return oXCompLib::ecm_disconnect();
};

int mainlib::invokeMethod(qlong pMethodId, EXTCompInfo *pECI) {
	// nothing to do here..

	return oXCompLib::invokeMethod(pMethodId, pECI);
};
