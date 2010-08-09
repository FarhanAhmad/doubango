/*
* Copyright (C) 2009-2010 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
#ifndef TINYWRAP_MSRP_H
#define TINYWRAP_MSRP_H

#include "tinymsrp.h"

class MsrpMessage
{
public:
	MsrpMessage();
#if !defined(SWIG)
	MsrpMessage(tmsrp_message_t *message);
#endif
	virtual ~MsrpMessage();

private:
	tmsrp_message_t *message;
};

class MsrpEvent
{
public:
#if !defined(SWIG)
	MsrpEvent(const tmsrp_event_t *_event);
#endif
	virtual ~MsrpEvent();

	unsigned getSipSessionId();
	const MsrpMessage* getMessage() const;

protected:
	const tmsrp_event_t *_event;
	MsrpMessage* message;
};

class MsrpCallback
{
public:
	MsrpCallback() {  }
	virtual ~MsrpCallback() {}
	virtual int OnEvent(const MsrpEvent* e) { return -1; }
};


#if !defined(SWIG)
int twrap_msrp_cb(const tmsrp_event_t* _event);
#endif

#endif /* TINYWRAP_MSRP_H */