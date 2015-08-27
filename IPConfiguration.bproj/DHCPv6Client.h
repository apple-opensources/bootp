/*
 * Copyright (c) 2009-2010 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 * DHCPv6Client.h
 * - API's to instantiate and interact with DHCPv6Client
 */

/* 
 * Modification History
 *
 * September 22, 2009		Dieter Siegmund (dieter@apple.com)
 * - created
 */

#ifndef _S_DHCPV6CLIENT_H
#define _S_DHCPV6CLIENT_H

#include <stdint.h>
#include <stdbool.h>

#include "DHCPDUID.h"
#include "interfaces.h"
#include "ipconfigd_threads.h"

typedef struct DHCPv6Client * DHCPv6ClientRef;

typedef void (*DHCPv6ClientNotificationCallBack)(void * callback_arg,
						 DHCPv6ClientRef client);
void
DHCPv6ClientSetRequestedOptions(uint16_t * requested_options,
				int requested_options_count);
bool
DHCPv6ClientOptionIsOK(int option);

DHCPv6ClientRef
DHCPv6ClientCreate(interface_t * if_p);

void
DHCPv6ClientStart(DHCPv6ClientRef client, bool allocate_address);

void
DHCPv6ClientStop(DHCPv6ClientRef client, bool discard_information);

void
DHCPv6ClientRelease(DHCPv6ClientRef * client_p);

bool
DHCPv6ClientGetInfo(DHCPv6ClientRef client, dhcpv6_info_t * info_p);

void
DHCPv6ClientCopyAddresses(DHCPv6ClientRef client, 
			  inet6_addrlist_t * addr_list_p);

void
DHCPv6ClientAddressChanged(DHCPv6ClientRef client, 
			   inet6_addrlist_t * addr_list_p);

void
DHCPv6ClientSetNotificationCallBack(DHCPv6ClientRef client, 
				    DHCPv6ClientNotificationCallBack callback,
				    void * callback_arg);

#endif /* _S_DHCPV6CLIENT_H */
