/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  oExample.h
 *  Example implementation of a visual component
 *
 *  Bastiaan Olij
 */

#ifndef oexampleh
#define oexampleh

#include "omnis.xcomp.framework.h"

class oExample : public oBaseVisComponent {
public:
	oExample(void);
	~oExample(void);
	
	static oExample *			newObject(void);

	virtual void				doPaint(HDC pHDC);													// Do our drawing in here

	virtual qMethods *			methods(void);														// return an array of method meta data
	virtual int					invokeMethod(qint pMethodId, EXTCompInfo* pECI);						// invoke a method

};

#endif