/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  oExample.cpp
 *  Example implementation of a non visual component
 *
 *  Bastiaan Olij
 */

#include "oExample.h"

// instantiate a new object
oExample * oExample::newObject(void) {
	oExample *lvNewExample = new oExample();
	
	return lvNewExample;
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
		case 1:
			EXTfldval	lvResult;
			str255		lvString("Hello world!");
			
			lvResult.setChar(lvString);
			
			ECOaddParam(pECI, &lvResult);
			return 1L;				
			
			break;
		default:
			
			break;
	}
};