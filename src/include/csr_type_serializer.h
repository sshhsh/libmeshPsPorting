/*****************************************************************************
 *
 * Copyright [2015] Qualcomm Technologies International, Ltd.
 *
 * REVISION:      $Revision: #13 $
 *
 ****************************************************************************/

#ifndef __CSR_TYPE_SERIALIZER_H__
#define __CSR_TYPE_SERIALIZER_H__

#define WRITE_BOOL(p, v, len)  p[*len] = (v) & 0x00FF; *len = (*len)+1;
#define WRITE_uint8(p, v, len)  p[*len] = (v) & 0x00FF; *len = (*len)+1;
#ifdef   ARCH_BIG_ENDIAN
#define WRITE_uint16(p, v, len) p[*len] = ((v) & 0xFF00)>>8; p[(*len) + 1] = ((v) & 0x00FF); *len = ((*len) + 2);
#define WRITE_uint32(p, v, len) p[*len] = ((v) & 0xFF000000)>>24; p[(*len)+1] = ((v) & 0x00FF0000)>>16; \
p[(*len) +2 ] = ((v) & 0x0000FF00)>>8; p[(*len) +3 ] = ((v) & 0x000000FF); *len = *len + 4;

#define WRITE_uint64(p, v, len) p[(*len)] = ((v) & 0xFF00000000000000)>>56; p[(*len) +1 ] = ((v) & 0x00FF000000000000)>>48; \
p[(*len) +2 ] = ((v) & 0x0000FF0000000000)>>40; p[(*len) +3 ] = ((v) & 0x000000FF00000000)>>32; p[(*len) +4 ] = ((v) & 0xFF000000)>>24; \
p[(*len) +5] = ((v) & 0x00FF0000)>>16; p[(*len) +6 ] = ((v) & 0x0000FF00)>>8; p[(*len) +7 ] = ((v) & 0x000000FF); *len = (*len) + 8
#else
#define WRITE_uint16(p, v, len) p[*len] = ((v) & 0x00FF); p[(*len) + 1] = (((v) & 0xFF00)>>8); *len = ((*len) + 2);
#define WRITE_uint32(p, v, len) p[*len] = ((v) & 0x000000FF); p[(*len)+1] = ((v) & 0x0000FF00)>>8; \
p[(*len) +2 ] = ((v) & 0x00FF0000)>>16; p[(*len) +3 ] = ((v) & 0xFF000000)>>24; *len = *len + 4;

#define WRITE_uint64(p, v, len) p[(*len)] = ((v) & 0x000000FF); p[(*len) +1 ] = ((v) & 0x0000FF00)>>8; \
p[(*len) +2 ] = ((v) & 0x00FF0000)>>16; p[(*len) +3 ] = ((v) & 0xFF000000)>>24; p[(*len) +4 ] = ((v) & 0x000000FF00000000)>>32; \
p[(*len) +5] = ((v) & 0x0000FF0000000000)>>40; p[(*len) +6 ] =  ((v) & 0x00FF000000000000)>>48; p[(*len) +7 ] = ((v) & 0xFF00000000000000)>>56; *len = (*len) + 8
#endif


#define READ_BOOL(msg)   (CsrBool)(*(msg));
#define READ_uint8(msg)   (uint8_t)(*(msg));

#ifdef   ARCH_BIG_ENDIAN
#define READ_uint16(msg)   ( ((uint16_t)(*(msg)<<8)) |  *(msg+1));
#define READ_uint32(msg)   ( ((uint32_t)*(msg))<<24  | ((uint32_t)*(msg+1))<<16  | ((uint32_t)*(msg+2))<<8 |  *(msg+3));
#define READ_uint64(msg)   ( ((uint64_t)*(msg))<<56 |  ((uint64_t)*(msg+1) )<<48 | ((uint64_t)*(msg+2))<<40 | ((uint64_t)*(msg+3))<<32 | ((uint64_t)*(msg+4))<<24  \
| ((uint64_t)*(msg+5))<<16  | ((uint64_t)*(msg+6))<<8 |  *(msg+7));

#else
#define READ_uint16(msg)   ( ((uint16_t)(*(msg+1)<<8)) |  *(msg));
#define READ_uint32(msg)   ( ((uint32_t)*(msg+3))<<24  | ((uint32_t)*(msg+2))<<16  | ((uint32_t)*(msg+1))<<8 |  *(msg));
#define READ_uint64(msg)   ( ((uint64_t)*(msg+7))<<56 |  ((uint64_t)*(msg+6) )<<48 | ((uint64_t)*(msg+5))<<40 | ((uint64_t)*(msg+4))<<32 | ((uint64_t)*(msg+3))<<24  \
| ((uint64_t)*(msg+2))<<16  | ((uint64_t)*(msg+1))<<8 |  *(msg));

#endif



#define READ_int8 READ_uint8
#define READ_int16 READ_uint16
#define READ_int32 READ_uint32
#define READ_int64 READ_uint64



#define WRITE_int8 WRITE_uint8
#define WRITE_int16 WRITE_uint16
#define WRITE_int32 WRITE_uint32
#define WRITE_int64 WRITE_uint64



#define WRITE_CsrBool WRITE_BOOL
#define WRITE_CsrUint8 WRITE_uint8
#define WRITE_CsrUint16 WRITE_uint16
#define WRITE_CsrUint32 WRITE_uint32
#define WRITE_CsrUint64 WRITE_uint64



#define WRITE_CsrInt8 WRITE_int8
#define WRITE_CsrInt16 WRITE_int16
#define WRITE_CsrInt32 WRITE_int32
#define WRITE_CsrInt64 WRITE_int64


#define READ_CsrUint8 READ_uint8
#define READ_CsrUint16 READ_uint16
#define READ_CsrUint32 READ_uint32
#define READ_CsrUint64 READ_uint64


#define READ_CsrBool READ_BOOL
#define READ_CsrInt8 READ_int8
#define READ_CsrInt16 READ_int16
#define READ_CsrInt32 READ_int32
#define READ_CsrInt64 READ_int64

#define WRITE_Array_CsrUint8(p, v, len, size) \
{ \
	int ij; \
	for(ij=0;ij<size;ij++) \
	{\
		WRITE_CsrUint8(p, *(v+ij),len); \
	}\
}

#define READ_Array_CsrUint8(dest, src, size) \
{ \
 memcpy((void*)dest, (void*)src, size); \
}

#define WRITE_Array_CsrUint16(p, v, len, size) \
{ \
	int ij; \
	for(ij=0;ij<size;ij++) \
	{\
		WRITE_CsrUint16(p, *(v+ij),len); \
	}\
}

#define READ_Array_CsrUint16(dest, src, size) \
{ \
	int ij; \
	for(ij=0;ij<size;ij++) \
	{\
		*( (CsrUint16*)dest + ij)  = READ_CsrUint16 ( src+ij*sizeof(CsrUint16)) ; \
	}\
}
#endif
