/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  oExample.cpp
 *  Example implementation of a visual component
 *
 *  Bastiaan Olij
 */

#include "oExample.h"

// we only implement our constructors/destructors to get some logging going to find out if all is well...
oExample::oExample(void){
	//	addToTraceLog("Constructing oExample %li",(uint)this);
};

oExample::~oExample(void){
	//	addToTraceLog("Destructing oExample %li",(uint)this);
};

// instantiate a new object
oExample *oExample::newObject(void) {
	oExample *lvNewExample = new oExample();

	return lvNewExample;
};

// Do our drawing in here
void oExample::doPaint(EXTCompInfo *pECI) {
	// call base class to draw background
	oBaseVisComponent::doPaint(pECI);

	qstring primarydata(mPrimaryData);
	mCanvas->drawText(primarydata.cString(), mClientRect, mTextColor, jstLeft, false, false);

	// draw something to test..
	qrect lvRect;

	lvRect.left = 10;
	lvRect.top = 100;
	lvRect.right = 100;
	lvRect.bottom = 200;

	mCanvas->drawRect(lvRect, GDI_COLOR_QBLUE, GDI_COLOR_QBLUE);

	qstring exampleText(QTEXT("Hello world, this is just some sample text to see if this works."));
	mCanvas->drawText(exampleText.cString(), lvRect, mTextColor, jstCenter, false, true);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// properties
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Standard properties we should support...
ECOproperty oExampleProperties[] = {
	//	ID						ResID	Type			Flags					ExFlags	EnumStart	EnumEnd
	anumFieldname, 0, fftCharacter, EXTD_FLAG_PRIMEDATA, 0, 0, 0 // $dataname, this should be of the type of data we assign here. This is a special property not managed through setProperty and getProperty
};

// Implement our property meta data static method. Because static members aren't inherited in the normal sense
// we're implementing our static function on each (sub)class and call the parents static member.
// If you don't have properties you could call oBaseVisComponent::properties and skip implementing this but
// I think it is good practice to implement it even if it is just to say, hey I haven't got any properties.
qProperties *oExample::properties(void) {
	qProperties *lvProperties = oBaseVisComponent::properties();

	// Add the property definition for our visual component here...
	lvProperties->addElements(oExampleProperties, sizeof(oExampleProperties) / sizeof(ECOproperty));

	return lvProperties;
};

// set the value of a property
qbool oExample::setProperty(qlong pPropID, EXTfldval &pNewValue, EXTCompInfo *pECI) {
	// most anum properties are managed by Omnis but some we need to do ourselves, no idea why...

	switch (pPropID) {
			//		case YourPropertyID: {
			//			mYourValue = pNewValue.getLong();
			//			return qtrue;
			//		}; break;
		default:
			return oBaseVisComponent::setProperty(pPropID, pNewValue, pECI);
			break;
	};
};

// get the value of a property
qbool oExample::getProperty(qlong pPropID, EXTfldval &pGetValue, EXTCompInfo *pECI) {
	// most anum properties are managed by Omnis but some we need to do ourselves...

	switch (pPropID) {
			//		case YourPropertyID: {
			//			pNewValue.setLong(1234);
			//          return qtrue;
			//		}; break;
		default:
			return oBaseVisComponent::getProperty(pPropID, pGetValue, pECI);

			break;
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// methods
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This is our array of methods we support
ECOmethodEvent oExampleMethods[] = {
	//	ID				Resource	Return type		Paramcount		Params					Flags		ExFlags
	1, 8000, fftCharacter, 0, NULL, 0, 0, // $testMethod
};

// return an array of method meta data
qMethods *oExample::methods(void) {
	qMethods *lvMethods = oBaseVisComponent::methods();

	lvMethods->addElements(oExampleMethods, sizeof(oExampleMethods) / sizeof(ECOmethodEvent));

	return lvMethods;
};

// invoke a method
int oExample::invokeMethod(qlong pMethodId, EXTCompInfo *pECI) {
	switch (pMethodId) {
		case 1: {
			EXTfldval lvResult;
			str255 lvString(QTEXT("Hello world from our visual object!"));

			lvResult.setChar(lvString);

			ECOaddParam(pECI, &lvResult);
			return 1L;
		}; break;
		default: {
			return oBaseVisComponent::invokeMethod(pMethodId, pECI);
		}; break;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// events
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ECOmethodEvent oExampleEvents[] = {
	//	ID					Resource	Return type		Paramcount		Params					Flags		ExFlags
	1,
	5000,
	0,
	0,
	0,
	0,
	0,
};

// return an array of events meta data
qEvents *oExample::events(void) {
	qEvents *lvEvents = oBaseNVComponent::events();

	// Add the event definition for our visual component here...
	lvEvents->addElements(oExampleEvents, sizeof(oExampleEvents) / sizeof(ECOmethodEvent));

	return lvEvents;
};

void oExample::evClick(qpoint pAt, EXTCompInfo *pECI) {
	// need to find out if Omnis has an internal ID for its standard evClick
	ECOsendEvent(mHWnd, 1, 0, 0, EEN_EXEC_IMMEDIATE);
};
