int strLen(char* str)
{
	int len = 0;
	while (str[len++] != '\0');

	return len - 1;

}


int strCpy(char* dest, char* source)
{

	int len = strLen(source) + 1;
	int i;

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

	return len;

}

int strCat(char* dest, char*source)
{
	int len = strLen(dest);
	int Slen = strLen(source) + 1;
	int i;

	for (i = 0; i < Slen; i++) dest[i + len] = source[i];

	return len + Slen;
}