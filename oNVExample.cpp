/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  oNVExample.cpp
 *  Example implementation of a non visual component
 *
 *  Bastiaan Olij
 */


#include "oNVExample.h"

// we only implement our constructors/destructors to get some logging going to find out if all is well...
oNVExample::oNVExample(void) {
	addToTraceLog("Constructing oNVExample %li",(uint)this);
};

oNVExample::~oNVExample(void) {
	addToTraceLog("Destructing oNVExample %li",(uint)this);	
};


// instantiate a new object
oNVExample * oNVExample::newObject(void) {
	oNVExample *lvNewExample = new oNVExample();
	
	return lvNewExample;
};

// destruct our object
void oNVExample::destructObj(oNVExample *pDestruct){
	delete pDestruct;
};


// create a copy of pCopy, this MUST be implemented in a subclass
void oNVExample::copyObject(oBaseNVComponent *pCopy) {
	// no members to copy just yet...
};


ECOmethodEvent oNVExampleMethods[] = {
	//	ID				Resource	Return type		Paramcount		Params					Flags		ExFlags
	1,					8100,		fftCharacter,	0,				NULL,					0,			0,			// $testMethod	
};

// return an array of method meta data
qMethods * oNVExample::methods(void) {
	if (mMethods==NULL) {
		mMethods = oBaseNVComponent::methods();
		
		mMethods->addElements(oNVExampleMethods, sizeof(oNVExampleMethods) / sizeof(ECOmethodEvent));		
	};
	return mMethods;
	
};

// invoke a method
int	oNVExample::invokeMethod(qint pMethodId, EXTCompInfo* pECI) {
	switch (pMethodId) {
		case 1: {
			EXTfldval	lvResult;
			str255		lvString("Hello world from our non-visual object!");
			
			lvResult.setChar(lvString);
			
			ECOaddParam(pECI, &lvResult);
			return 1L;							
		}; break;
		default: {
			return oBaseNVComponent::invokeMethod(pMethodId, pECI);
		}; break;
	}
};