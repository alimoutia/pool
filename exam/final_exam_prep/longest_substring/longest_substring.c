int longuest_substring(char *str)
{
	int sub_start = 0;
	int insub_start = 0;
	int insub_end = insub_start + 1;
	int sub_end = 1;
	int str_acr = 0;
	char *str1;

	while (str[str_acr])
	{
		if (str[sub_start] == str[sub_end] && str[sub_end])
		{
			sub_start++;
			sub_end++;
		}
		while (str[sub_start] != str[sub_end] && str[sub_end])
			sub_end++;
		if (str[sub_start] == str[sub_end])
		{
			insub_start = sub_start;
			while (insub_start < sub_end - 1)
			{
				if (str[insub_start] == str[insub_end])
					insub_start = sub_end;
				insub_end = insub_start + 1;
				while (insub_end < sub_end)
				{
					if (str[insub_start] != str[insub_end])
						insub_end++;
					else 
				}
				
			}
			
		}
		
	}
}