/*	@(#)	strtnt.c	*/
/* 
 *	v 1.0, 2022/08 Eric Sanchis 
 */
 
/* Copyright (C) 2022,  eric.sanchis@netc.fr
   It is a free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Public License for more details:
   <http://www.gnu.org/licenses/>.  */

#include	<string.h>

#include	"strtnt.h"



#define   TRUNC      0          /* truncation allowed */
#define   NOTRUNC    1          /* truncation not allowed */



/* = = = = = = = =  COPY  = = = = = = = = */

static
int str5cpy( char * dst,
             size_t dstsize,
             const char * src,
             size_t nb,
             size_t mode )
{
	size_t srclen ;
	
if ( dst == NULL )
   return EDSTNUL ;
if ( dstsize == 0 )
   return EDSTSZ0 ;
if ( src == NULL )
   return ESRCNUL ;

if ( nb == 0 )
   return ONOTRUNC ;	/* do nothing */

   /* find the nul byte of src within the first dstsize characters */
for (srclen=0 ; srclen < dstsize && src[srclen] != '\0' ; srclen++)
     ;

if ( srclen == 0 )
{
  dst[0] = '\0' ;   
  return ONOTRUNC ;
}

nb = nb > srclen ? srclen : nb ;   

if ( dstsize <= nb )    /* dst: not enough space */
{
   if ( mode == TRUNC )    /* truncation allowed */
   {
     memcpy(dst,src,dstsize-1) ;
     dst[dstsize-1] = '\0' ;
     return OTRUNC ;
   }
   else  /*  mode == NOTRUNC */
     return ETRUNC ; 
}

/* dst: enough space */
memcpy(dst, src, nb) ;   
dst[nb] = '\0' ;
return ONOTRUNC ;
}


int strntcpy(char *dst, size_t dstsize, const char *src)
{
  return str5cpy(dst,dstsize,src,dstsize,NOTRUNC);
}


int strtcpy(char *dst, size_t dstsize, const char *src)
{
  return str5cpy(dst,dstsize,src,dstsize,TRUNC);
}


int strsntcpy( char *dst, size_t dstsize, const char *src, size_t nb)
{
  return str5cpy(dst,dstsize,src,nb,NOTRUNC);
}


int strstcpy( char *dst, size_t dstsize, const char *src, size_t nb)
{
  return str5cpy(dst,dstsize,src,nb,TRUNC);
}
 

/* = = = = = = = =  CONCATENATION  = = = = = = = = */


static
int str5cat( char * dst,
             size_t dstsize,
             const char * src,
             size_t nb,
             size_t mode )
{
	size_t srclen ;
	size_t dstlen ;
	size_t remain ;
	size_t i ;
	char * p ;
	
if ( dst == NULL )
   return EDSTNUL ;
if ( dstsize == 0 )
   return EDSTSZ0 ;
if ( src == NULL )
   return ESRCNUL ;

   
/* find the nul byte of dst */
for (i=0 ; i < dstsize && dst[i] != '\0' ; i++)
     ;
if ( i == dstsize )	 /* no nul byte found into the buffer pointed to by dst */
   return EDSTBF ;		/*  dst is a bad-formed string  */
dstlen = i ;

if ( nb == 0 )
   return  ONOTRUNC ;	/* nothing to do */

remain = dstsize - dstlen ;

for (srclen=0 ; srclen < remain && src[srclen] != '\0' ; srclen++)
     ;
if ( srclen == 0 )
   return ONOTRUNC ;	/* nothing to do */

p = dst + dstlen ;		/* concatenation starting point  */
   
/* How many bytes to copy? */
nb = nb > srclen ? srclen : nb ;   

if ( remain <= nb )    /* dst: not enough space */
{
   if ( mode == TRUNC )    /* truncation allowed */
   {
     memcpy(p, src, remain-1) ;
     dst[dstsize-1] = '\0' ;
     return OTRUNC ;
   }
   else  /*  mode == NOTRUNC */
     return ETRUNC ; 
}
   
/* dst: enough space */
memcpy(p, src, nb) ;   
*(p + nb) = '\0' ;
return ONOTRUNC ;
}
  


int strntcat(char *dst, size_t dstsize, const char *src)
{
  return str5cat(dst,dstsize,src,dstsize,NOTRUNC);
}


int strtcat(char *dst, size_t dstsize, const char *src)
{
  return str5cat(dst,dstsize,src,dstsize,TRUNC);
}


int strsntcat(char *dst, size_t dstsize, const char *src, size_t nb)
{
  return str5cat(dst,dstsize,src,nb,NOTRUNC);
}


int strstcat(char *dst, size_t dstsize, const char *src, size_t nb)
{
  return str5cat(dst,dstsize,src,nb,TRUNC);
}



