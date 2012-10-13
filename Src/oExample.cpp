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
oExample::oExample(void) {
	addToTraceLog("Constructing oExample %li",(uint)this);
};

oExample::~oExample(void) {
	addToTraceLog("Destructing oExample %li",(uint)this);	
};

// instantiate a new object
oExample * oExample::newObject(void) {
	oExample *lvNewExample = new oExample();
	
	return lvNewExample;
};

// destruct our object
void oExample::destructObj(oExample *pDestruct){
	delete pDestruct;
};


// Do our drawing in here
void oExample::doPaint(HDC pHDC) {
	// call base class to draw background
	oBaseVisComponent::doPaint(pHDC);
	
	// draw something to test..
	qrect lvRect;
	
	lvRect.left = 10;
	lvRect.top = 10;
	lvRect.right = 100;
	lvRect.bottom = 100;
	
	HBRUSH lvBrush = GDIgetStockBrush( BLACK_BRUSH );
	GDIsetTextColor( pHDC, 255 );
	GDIfillRect( pHDC, &lvRect, lvBrush );	
};


ECOmethodEvent oExampleMethods[] = {
	//	ID				Resource	Return type		Paramcount		Params					Flags		ExFlags
	1,					8000,		fftCharacter,	0,				NULL,					0,			0,			// $testMethod	
};

// return an array of method meta data
qMethods * oExample::methods(void) {
	if (mMethods==NULL) {
		mMethods = oBaseVisComponent::methods();
		
		mMethods->addElements(oExampleMethods, sizeof(oExampleMethods) / sizeof(ECOmethodEvent));		
	};
	return mMethods;
	
};

// invoke a method
int	oExample::invokeMethod(qint pMethodId, EXTCompInfo* pECI) {
	switch (pMethodId) {
		case 1: {
			EXTfldval	lvResult;
			str255		lvString("Hello world from our visual object!");
			
			lvResult.setChar(lvString);
			
			ECOaddParam(pECI, &lvResult);
			return 1L;							
		}; break;
		default: {
			return oBaseVisComponent::invokeMethod(pMethodId, pECI);
		}; break;
	}
};