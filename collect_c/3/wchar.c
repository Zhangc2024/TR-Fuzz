/* c-examples by A.A.Shtanyuk */
/* wchar.c - wide char example for utf-8 codepage */
#include <wchar.h>
#include <stdio.h>
#include <locale.h>

int main()
{
   wchar_t str[]=L"Hello-Привет!\n";
   setlocale(LC_ALL, "");
   wprintf(L"%ls",str);
   return 0;
}
