/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
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
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_Privacy.h
 * @brief SIP header 'Privacy'.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _TSIP_HEADER_PRIVACY_H_
#define _TSIP_HEADER_PRIVACY_H_
#include "tinysip_config.h"
#include "tinysip/headers/tsip_header.h"

/**@def TSIP_HEADER_PRIVACY_CREATE
* Creates new sip 'Privacy' header.  You must call @ref TSIP_HEADER_PRIVACY_SAFE_FREE to free the header.
* @sa TSIP_HEADER_PRIVACY_SAFE_FREE.
*/
/**@def TSIP_HEADER_PRIVACY_SAFE_FREE
* Safely free a sip 'Privacy' header previously created using TSIP_HEADER_PRIVACY_CREATE.
* @sa TSIP_HEADER_PRIVACY_CREATE.
*/
#define TSIP_HEADER_PRIVACY_CREATE()		tsk_object_new(tsip_header_Privacy_def_t)
#define TSIP_HEADER_PRIVACY_SAFE_FREE(self)	tsk_object_unref(self), self = 0

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @struct	
///
/// @brief	SIP header 'Privacy' as per RFC 3323.
/// @author	Mamadou
/// @date	12/3/2009
///
/// @par ABNF: Privacy = Privacy-hdr
/// Privacy-hdr	= 	"Privacy" HCOLON priv-value *(";" priv-value)
/// priv-value	= 	"header" / "session" / "user" / "none" / "critical" / "id" / "history" / token
/// 	
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tsip_header_Privacy_s
{	
	TSIP_DECLARE_HEADER;

	tsk_strings_L_t *values;
}
tsip_header_Privacy_t;

tsip_header_Privacy_t *tsip_header_Privacy_parse(const char *data, size_t size);

TINYSIP_API const void *tsip_header_Privacy_def_t;

#endif /* _TSIP_HEADER_PRIVACY_H_ */