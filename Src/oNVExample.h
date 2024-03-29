/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  oNVExample.h
 *  Example implementation of a non visual component
 *
 *  Bastiaan Olij
 */

#ifndef onvexampleh
#define onvexampleh

#include "omnis.xcomp.framework.h"

class oNVExample : public oBaseNVComponent {
public:
	oNVExample(void);
	~oNVExample(void);

	static oNVExample *newObject(void);

	virtual void copyObject(oBaseNVComponent *pCopy); // create a copy of pCopy, this MUST be implemented in a subclass

	// properties
	static qProperties *properties(void); // return an array of property data

	// methods
	static qMethods *methods(void); // return array of method meta data
	virtual int invokeMethod(qlong pMethodId, EXTCompInfo *pECI); // invoke a method

	// events
	static qEvents *events(void); // return an array of events meta data
};

#endif