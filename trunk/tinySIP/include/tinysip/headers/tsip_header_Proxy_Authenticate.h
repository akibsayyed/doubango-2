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

/**@file tsip_header_Proxy_Authenticate.h
 * @brief SIP header 'Proxy-Authenticate'.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _TSIP_HEADER_PROXY_AUTHENTICATE_H_
#define _TSIP_HEADER_PROXY_AUTHENTICATE_H_
#include "tinysip_config.h"
#include "tinysip/headers/tsip_header.h"

/**@def TSIP_HEADER_PROXY_AUTHENTICATE_CREATE
* Creates new sip 'PROXY-AUTHENTICATE' header.  You must call @ref TSIP_HEADER_PROXY_AUTHENTICATE_SAFE_FREE to free the header.
* @sa TSIP_HEADER_PROXY_AUTHENTICATE_SAFE_FREE.
*/
/**@def TSIP_HEADER_PROXY_AUTHENTICATE_SAFE_FREE
* Safely free a sip 'PROXY-AUTHENTICATE' header previously created using TSIP_HEADER_PROXY_AUTHENTICATE_CREATE.
* @sa TSIP_HEADER_PROXY_AUTHENTICATE_CREATE.
*/
#define TSIP_HEADER_PROXY_AUTHENTICATE_CREATE()				tsk_object_new(tsip_header_Proxy_Authenticate_def_t)
#define TSIP_HEADER_PROXY_AUTHENTICATE_SAFE_FREE(self)		tsk_object_unref(self), self = 0

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @struct	
///
/// @brief	SIP header 'Proxy-Authenticate'.
/// @author	Mamadou
/// @date	12/3/2009
///
/// @par ABNF = Proxy-Authenticate	= 	"Proxy-Authenticate" HCOLON challenge
///				challenge	= 	("Digest" LWS digest-cln *(COMMA digest-cln)) / other-challenge
///				other-challenge	= 	auth-scheme / auth-param *(COMMA auth-param)
///				digest-cln	= 	realm / domain / nonce / opaque / stale / algorithm / qop-options / auth-param
///				realm	= 	"realm" EQUAL realm-value
///				realm-value	= 	quoted-string
///				domain	= 	"domain" EQUAL LDQUOT URI *( 1*SP URI ) RDQUOT
///				URI	= 	absoluteURI / abs-path
///				opaque	= 	"opaque" EQUAL quoted-string
///				stale	= 	"stale" EQUAL ( "true" / "false" )
///				qop-options	= 	"qop" EQUAL LDQUOT qop-value *("," qop-value) RDQUOT
///				qop-value	= 	"auth" / "auth-int" / token
/// 	
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tsip_header_Proxy_Authenticate_s
{	
	TSIP_DECLARE_HEADER;
	
	char* scheme;
	char* realm;
	char* domain;
	char* nonce;
	char* opaque;
	unsigned stale:1;
	char* algorithm;
	char* qop;
}
tsip_header_Proxy_Authenticate_t;

tsip_header_Proxy_Authenticate_t *tsip_header_Proxy_Authenticate_parse(const char *data, size_t size);

TINYSIP_API const void *tsip_header_Proxy_Authenticate_def_t;

#endif /* _TSIP_HEADER_PROXY_AUTHENTICATE_H_ */