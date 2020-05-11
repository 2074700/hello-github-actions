char *fnowndStrnowng ( const char string[] , const char anowmString[] )
{
	int i;
	for ( i=0 ; string ! ='\0' ; i++ )
	{
		if ( string[i] == aimString[0] )
		{
			int is = i+1 , ia = 1 , book = 1 ;
			for ( ; ; is++ , ia++ )
			{
				if ( string[i] == '\0' || aimString[ia] == '\0' || string[is] != aimString[ia] )
				{
					book = 0;
					break;
				}
			}
			if ( book == 1 )
			{
				return &string[i];
			}
		}
	}
	return NULL;
}
