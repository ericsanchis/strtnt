# Copy and Concatenation of C-Strings: the Strtnt Functions

## Description

Copy and concatenation of C-strings are particularly tricky, prone to numerous kinds of programming errors which can lead to more or less serious vulnerabilities. 

The _**strtnt**_ functions are designed to replace 
* the _strcpy()_, _strncpy()_, _strlcpy()_, _strcpy_s()_ and _strncpy_s()_ functions 
* the _strcat()_, _strncat()_, _strlcat()_, _strcat_s()_ and _strncat_s()_ functions. 

They are easier to use, more robust, more consistent, less error prone and well documented (cf. manuals).

These functions are designed to force programmers to specify what they know (e.g. the size of the destination buffer) and what they want (e.g. the number of characters of src to be copied, truncation or no truncation). 
Finally, they also integrate checking that programmers should explicitly do.


## Synopsis

The _**strt/strst**_ prefixes mean that truncation is allowed. 
The _**strnt/strsnt**_ prefixes mean that truncation is not allowed. 

#### String copy:

       int strntcpy(char *dst, size_t dstsize, const char *src);
       int strtcpy(char *dst, size_t dstsize, const char *src);
 
The **strntcpy()** and  **strtcpy()** functions copy the string pointed to by _src_, including the terminating null byte ('\0'), to the array pointed to by _dst_.  
The full size of the destination buffer _dst_ is _dstsize_.  
The **strtcpy()** function specifies that truncation is allowed. When truncation is not allowed, the **strntcpy()** function should be used.

#### Sub-string copy:

       int strsntcpy(char *dst, size_t dstsize, const char *src, size_t nb);
       int strstcpy(char *dst, size_t dstsize, const char *src, size_t nb);

The **strsntcpy()** and **strstcpy()** functions copy up to the first (not null) _nb_ characters from the source string pointed to by _src_ to the destination array pointed to by _dst_ and add a terminating null byte.  
The parameter _dstsize_ indicates the size of the destination array _dst_.  
The **strstcpy()** function specifies that truncation is allowed. When truncation is not allowed, the **strsntcpy()** function should be used.

#### String concatenation:

       int strntcat(char *dst, size_t dstsize, const char *src);
       int strtcat(char *dst, size_t dstsize, const char *src);

The **strntcat()** and **strtcat()** functions append the string pointed to by _src_ to the string pointed to by _dst_, overwriting its terminating null byte, then add a terminating null byte.  
The full size of the destination buffer _dst_ is _dstsize_.  
The strtcat() function specifies that truncation is allowed. When truncation is not allowed, the strntcat() function should be used.

#### Sub-string concatenation:

       int strsntcat(char *dst, size_t dstsize, const char *src, size_t nb);
       int strstcat(char *dst, size_t dstsize, const char *src, size_t nb);

The  **strsntcat()**  and  **strstcat()**  functions  append  up to the first (not null) _nb_ characters from the source string pointed to by _src_ to the string pointed to by _dst_, overwriting its terminating null byte. Then, a new null byte is appended to the new string.  
The full size of  the  destination  buffer _dst_ is _dstsize_.  
The **strstcat()** function specifies that truncation is allowed. When truncation is not allowed, the **strsntcat()** function should be used.


#### Advantages of the strtnt functions:

	1. They store a well-formed string (i.e. a string with a terminating null byte) into the destination buffer or leave this buffer unchanged.
    2. The sufficient number of parameters allows the programmer not to carry out the tedious and delicate tasks of checking. 
    3. The programmer never have to manage the terminating null byte.
	4. Truncations are directly controllable by the programmer.
	5. The return value informs the programmer of the quality of the obtained result.


## Portability

_**Strtnt**_ functions conform to C89 standard.  
Its a free software (_GNU Lesser General Public License_).  
Developers do not have to install complex libraries such as the _BSD_ library (for _strlcpy/strlcat_ functions) or a specific _Microsoft_ library (for _strX_s_ functions). They only have to include two files (_strtnt.c_, _strtnt.h_) in their projects.


## Examples

String copy, truncation not allowed:

			char arg1[10] ;
			int ret ;
			...
             /* Truncation is not allowed */
            if ( (ret = strntcpy(arg1,sizeof(arg1),argv[1])) < 0 )
                process_error(ret) ;

Sub-string concatenation, truncation allowed:

			char dst[10] = "Hello ";
			char *src = "Barbara";
			int ret ;
			...
             /* Concatenation of the sub-string "Barbar", truncation is allowed */
            if ( (ret = strstcat(dst,sizeof(dst),src,6)) < 0 )
                process_error(ret) ;
			
             /* dst = "Hello Bar", a truncation was done */  */
			 



