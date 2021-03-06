/*
 * Copyright 2008-2016 Freescale Semiconductor Inc.
 * Copyright 2017-2018 NXP
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of the above-listed copyright holders nor the
 *        names of any contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**************************************************************************//**
 @File          types_ext.h

 @Description   General types Standard Definitions
*//***************************************************************************/

#ifndef __TYPES_EXT_H
#define __TYPES_EXT_H

#if defined(NCSW_LINUX)
#include "types_linux.h"

#elif defined(NCSW_LINUX_USD)
#include "types_linux_usd.h"

#elif defined(NCSW_VXWORKS)
#include "types_vxworks.h"

#elif defined(__GNUC__) && defined(__cplusplus)
#include "types_bb_gpp.h"

#elif defined(__GNUC__)
#include "types_bb_gcc.h"

#elif defined(__ghs__)
#include "types_ghs.h"

#else
#include "types_dflt.h"
#endif /* defined (__ROCOO__) */

static __inline__ void TypesChecker(void)
{
#if defined(__MWERKS__) && !defined(__GNUC__)
#pragma pack(push,1)
#endif /* defined(__MWERKS__) && ... */
     _Packed struct strct {
        __volatile__ int vi;
    } _PackedType;
#if defined(__MWERKS__) && !defined(__GNUC__)
#pragma pack(pop)
#endif /* defined(__MWERKS__) && ... */
    size_t          size = 0;
    bool            tr = TRUE, fls = FALSE;
    struct strct    *p_Struct = NULL;
    physAddress_t   addr = 0x100;

    tr          = fls;
    p_Struct    = p_Struct;
    size++;
    if (tr) size++;

    WRITE_UINT8(*((uint8_t*)((size_t)(addr))),
                 GET_UINT8(*((uint8_t*)((size_t)(addr)))));

    WRITE_UINT8(*((uint8_t*)((size_t)(UINT8_MAX))),
                 GET_UINT8(*((uint8_t*)((size_t)(UINT8_MAX)))));
    WRITE_UINT16(*((uint16_t*)((size_t)(UINT16_MAX))),
                 GET_UINT16(*((uint16_t*)((size_t)(UINT16_MAX)))));
    WRITE_UINT32(*((uint32_t*)((size_t)(UINT32_MAX))),
                 GET_UINT32(*((uint32_t*)((size_t)(UINT32_MAX)))));
    WRITE_UINT64(*((uint64_t*)((size_t)(UINT64_MAX))),
                 GET_UINT64(*((uint64_t*)((size_t)(UINT64_MAX)))));
    WRITE_UINT8(*((uint8_t*)((size_t)(INT8_MAX))),
                 GET_UINT8(*((uint8_t*)((size_t)(INT8_MIN)))));
    WRITE_UINT16(*((uint16_t*)((size_t)(INT16_MAX))),
                 GET_UINT16(*((uint16_t*)((size_t)(INT16_MIN)))));
    WRITE_UINT32(*((uint32_t*)((size_t)(INT32_MAX))),
                 GET_UINT32(*((uint32_t*)((size_t)(INT32_MIN)))));
    WRITE_UINT64(*((uint64_t*)((size_t)(INT64_MAX))),
                 GET_UINT64(*((uint64_t*)((size_t)(INT64_MIN)))));
}

#endif /* __TYPES_EXT_H */
