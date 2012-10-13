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
		
	static oNVExample *			newObject(void);
	
	virtual void				copyObject(oBaseNVComponent *pCopy);								// create a copy of pCopy, this MUST be implemented in a subclass

	virtual qMethods *			methods(void);														// return an array of method meta data
	virtual int					invokeMethod(qint pMethodId, EXTCompInfo* pECI);					// invoke a method
	
};

#endif