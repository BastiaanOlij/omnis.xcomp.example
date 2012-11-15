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

// create a copy of pCopy, this MUST be implemented in a subclass
void oNVExample::copyObject(oBaseNVComponent *pCopy) {
	// no members to copy just yet...
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// properties
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Implement our property meta data static method. Because static members aren't inherited in the normal sense
// we're implementing our static function on each (sub)class and call the parents static member.
// If you don't have properties you could call oBaseVisComponent::properties and skip implementing this but
// I think it is good practice to implement it even if it is just to say, hey I haven't got any properties.
qProperties * oNVExample::properties(void) {
	qProperties *	lvProperties = oBaseNVComponent::properties();
	
	// No properties to add just yet..
	
	return lvProperties;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// methods
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This is our array of methods we support
ECOmethodEvent oNVExampleMethods[] = {
	//	ID				Resource	Return type		Paramcount		Params					Flags		ExFlags
	1,					8100,		fftCharacter,	0,				NULL,					0,			0,			// $testMethod	
};

// return an array of method meta data
qMethods * oNVExample::methods(void) {
	qMethods * lvMethods = oBaseNVComponent::methods();
		
	lvMethods->addElements(oNVExampleMethods, sizeof(oNVExampleMethods) / sizeof(ECOmethodEvent));		

	return lvMethods;	
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// events
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// return an array of events meta data
qEvents *	oNVExample::events(void) {
	qEvents *	lvEvents = oBaseNVComponent::events();
	
	// nothing to add yet, I'm not even sure these work for non-visual components
	
	return lvEvents;
};
