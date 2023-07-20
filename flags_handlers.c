#include "main.h"

/**
 * set_flag - sets a flag
 * Protype: int set_flag(const char flag, flag_t *flags);
 * @flag: single character representing a printf flag
 * @flags: an intialized  
 */
void set_flag(char flag, flag_t *flags, int *is_set)
{
	if (!flags || flags->plus || flags->space)
		*is_set = 0;
	else
	{
		if (flag == '+')
			flags->plus = '+';
		if (flag == '#')
			flags->hash = '#';
		if (flag == ' ')
			flags->space = ' ';
		*is_set = 1;
		return;
	}
}

/**
 * unset_flag - unsets a flag
 * Protype: int set_flag(const char flag, flag_t *flags);
 * @flag: single character representing a printf flag
 * @flags: an intialized  
 */
int unset_flag(flag_t *flags)
{
    if (!flags)
        return (0);
    flags->plus = '\0';
    flags->hash = '\0';
    flags->space = '\0';
    return (1);
}
