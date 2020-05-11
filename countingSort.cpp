int countingSort(int str[],const int size)
{
	short int i,j,nstr[10000];
	for (i = 0; i < size-1; ++i)
	{
		if (str[i] > 9999)
		{
			return LYFFALSE;
		}
		nstr[str[i]] = 1;
	}
	for (i = 0,j = 0; i < 9999; ++i,++j)
	{
		if (nstr[i] == 1)
		{
			str[j] = nstr[i];
		}
	}
	return LYFTRUE;
}
