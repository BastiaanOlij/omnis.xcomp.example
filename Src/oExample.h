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

	virtual void				doPaint(EXTCompInfo* pECI);											// Do our drawing in here

	// properties
	static  qProperties *		properties(void);													// return an array of property data
	virtual qbool				setProperty(qlong pPropID,EXTfldval &pNewValue,EXTCompInfo* pECI);	// set the value of a property
	virtual void				getProperty(qlong pPropID,EXTfldval &pGetValue,EXTCompInfo* pECI);	// get the value of a property
	
	// methods
	static  qMethods *			methods(void);														// return array of method meta data
	virtual int					invokeMethod(qlong pMethodId, EXTCompInfo* pECI);					// invoke a method

	// events
	static	qEvents *			events(void);														// return an array of events meta data
	virtual void				evClick(qpoint pAt, EXTCompInfo* pECI);								// mouse click at this location
};

#endif