/*PLOVER: BUFF.OVER*/

/* Description: An ad hoc gets without bounds checkes allows a stack buffer to be overrun.
Keywords: Size0 Complex1 BufferOverflow Stack AdHoc Unbounded ValidStream: "a"*30 InvalidStream: "a"*200 */

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40
void test( void )
{
  char buf[MAXSIZE], * p, ch;

  p = buf;
  while ( ( ch = getc( stdin ) ) != EOF && ch != '\n' )
    * p++ = ch;
  /* BAD */
  * p++ = 0;
  printf( "result: %s\n", buf );

}

int main( int argc, char * * argv )
{
  test();
  return 0;
}

