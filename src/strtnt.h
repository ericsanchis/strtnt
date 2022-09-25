/*	@(#)	strtnt.h	*/
/*
 *      v 1.0, 2022/08 Eric Sanchis
 */

/* Copyright (C) 2022 eric.sanchis@netc.fr
   It is a free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Public License for more details:
   <http://www.gnu.org/licenses/>.  */


#ifndef _STRTNT_H

#define	_STRTNT_H


int strntcpy(char *dst, size_t dstsize, const char *src);

int strtcpy(char *dst, size_t dstsize, const char *src);

int strsntcpy(char *dst, size_t dstsize, const char *src, size_t nb);

int strstcpy(char *dst, size_t dstsize, const char *src, size_t nb);
 
int strntcat(char *dst, size_t dstsize, const char *src);

int strtcat(char *dst, size_t dstsize, const char *src);

int strsntcat(char *dst, size_t dstsize, const char *src, size_t nb);

int strstcat(char *dst, size_t dstsize, const char *src, size_t nb);



#define   ONOTRUNC  0		/* copy/concatenation performed without truncation */
#define   OTRUNC    1		/* copy/concatenation performed with truncation allowed */


#define   EDSTNUL   -1		/* Error : dst is a NULL pointer */
#define   EDSTSZ0   -2		/* Error : dstsize is equal to 0 */
#define   EDSTBF    -3		/* Error : dst is a bad-formed string */
#define   ESRCNUL   -4		/* Error : src is a NULL pointer */
#define   ETRUNC    -5		/* Error : not enough space to copy/concatenate
						and truncation not allowed */

#endif
