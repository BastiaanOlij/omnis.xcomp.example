/*
 *  omnis.xcomp.example
 *  ===================
 *
 *  example.h
 *  Example implementation of our library class
 *
 *  Bastiaan Olij
 */

#ifndef exampleh
#define exampleh

#include "omnis.xcomp.framework.h"
#include "oNVExample.h"
#include "oExample.h"

class mainlib : public oXCompLib {
public:
	virtual qint		ecm_connect(void);					// initialize our library

};


#endif