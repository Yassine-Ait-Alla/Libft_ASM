
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libfts.h"

void	error(int er)
{
	printf("ERROR = %c\n", er);
	exit(0);
}

void	display_test(char *str, int er)
{
	char statut[3];

	if (er >= 1)
	{
		printf("%s", "\e[31m");
		strcpy(statut, "KO");
	}
	else
	{
		printf("%s", "\e[32m");
		strcpy(statut, "OK");
	}
	printf("[%s] = [%s] \n", str, statut);
	printf("%s", "\033[0m");
}

void	test_bzero(void)
{
	char	str[50] = "SISILAMIFBIENOU QUOI     0   0 ";
	char	str2[50] = "SISILAMIFBIENOU QUOI     0   0 ";
	int		er = 0;

	ft_bzero(str2, 10);
	bzero(str, 10);
	if (memcmp(str, str2, 50) != 0)
		er++;
	strcpy(str, "SISILAMIF");
	strcpy(str2, "SISILAMIF");

	ft_bzero(str2, 2);
	bzero(str, 2);
	if (memcmp(str, str2, 50) != 0)
		er++;

	ft_bzero(str2, 5);
	bzero(str, 5);
	if (memcmp(str, str2, 50) != 0)
		er++;

	ft_bzero(str2, 0);
	bzero(str, 0);
	if (memcmp(str, str2, 50) != 0)
		er++;

	display_test("ft_bzero", er);

}

void	test_strcat(void)
{
	char str[10] = {0};
	int er = 0;

	ft_strcat(str, "B");
	if (strcmp(str, "B") != 0)
		er++;
	ft_strcat(str, "on");
	if (strcmp(str, "Bon") != 0)
		er++;
	ft_strcat(str, "B");
	if (strcmp(str, "BonB") != 0)
		er++;
	ft_strcat(str, "our");
	if (strcmp(str, "BonBour") != 0)
		er++;
	ft_strcat(str, "Bo");
	if (strcmp(str, "BonBourBo") != 0)
		er++;
	display_test("ft_strcat", er);

}

void	test_isx(void)
{
	int c = -255;
	int er = 0;

	while (c < 255)
	{
		if (ft_isalpha(c) != isalpha(c))
			er++;
		if (ft_isdigit(c) != isdigit(c))
			er++;
		if (ft_isalnum(c) != isalnum(c))
			er++;
		if (ft_isascii(c) != isascii(c))
			er++;
		if (ft_isprint(c) != isprint(c))
			er++;
		if (ft_islower(c) != islower(c))
			er++;
		if (ft_isupper(c) != isupper(c))
			er++;
		c++;
	}
	display_test("ft_is_ToutCeQueTuVeux", er);
}
/*
	printf("ft = %d, r = %d\n", ft_isalpha(c), isalpha(c));
	printf("ft = %d, r = %d\n", ft_isdigit(c), isdigit(c));
	printf("ft = %d, r = %d\n", ft_isalnum(c), isalnum(c));
	printf("ft = %d, r = %d\n", ft_isascii(c), isascii(c));
	printf("ft = %d, r = %d\n", ft_isprint(c), isprint(c));
	printf("ft = %d, r = %d\n", ft_islower(c), islower(c));
	printf("ft = %d, r = %d\n", ft_isupper(c), isupper(c));
*/

void	test_tox(void)
{
	int c = -255;
	int er = 0;

	while (c < 255)
	{
		if (toupper(c) != ft_toupper(c))
		{
			er++;
		}
		if (tolower(c) != ft_tolower(c))
		{
			printf("%d\n", c );
			er++;
		}
		c++;
	}
	display_test("ft_toupper", er);
	display_test("ft_tolower", er);
}

void	test_puts(void)
{
	char *str = "ft_puts_ \t";
	int er = 0;

	if (puts(str) != ft_puts(str))
		er++;
	puts(NULL);
	ft_puts(NULL);
	display_test("ft_puts", er);
}

void	test_strlen(void)
{
	int	er = 0;

 	if(ft_strlen("wesh kheyou") != strlen("wesh kheyou"))
 		er++;
 	if(ft_strlen("") != strlen(""))
 		er++;
 	if(ft_strlen("b") != strlen("b"))
 		er++;
 	if(ft_strlen("00q0\0") != strlen("00q0\0"))
 		er++;
	display_test("ft_strlen", er);
}

void	test_memset(void)
{
	char str[10];
	char *ret;
	int er = 0;

	ret = ft_memset(str, 'c', 7);
	if (strcmp(str, "ccccccc") != 0)
		er++;
	bzero(str, 7);
	if (ret != memset(str, 'c', 7))
		er++;
	ft_memset(str, 'c', 0);
	if (strcmp(str, "ccccccc") != 0)
		er++;
	display_test("ft_memset", er);
}

void	test_memcpy(void)
{
	char dst[10];
	char dst2[10];
	char src[]="depsos";
	int er = 0;

	ft_memcpy(dst, src, 7);
	memcpy(dst2, src, 7);
	if (memcmp(dst, dst2, 7) != 0)
		er++;
	ft_memcpy(dst, src, 0);
	if (memcmp(dst, dst2, 7) != 0)
		er++;
	if (ft_memcpy(dst, src, 0) != memcpy(dst, src, 0))
		er++;
	display_test("ft_memcpy", er);
}

void	test_strdup(void)
{
	char *str = "wesh gadjo";
	int er = 0;

	if (strcmp(str, ft_strdup(str)) != 0)
		er++;
	if (strcmp("", ft_strdup("")) != 0)
		er++;
	display_test("ft_strdup", er);
}

void	test_strequ(void)
{
	int	er = 0;

	if (ft_strequ("Bonjour", "Bonjour") != 1)
		er++;
	if (ft_strequ("Bonjour", "Bon") != 0)
		er++;
	if (ft_strequ("Bo", "Bon") != 0)
		er++;
	if (ft_strequ("Bonjour", "Bonjou") != 0)
		er++;
	display_test("ft_strequ", er);
}

void	test_strchr(void)
{
	char *str="Bonjour";
	int	er = 0;

	if (ft_strchr(str, 'j') != strchr(str, 'j'))
		er++;
	if (ft_strchr(str, 0) != strchr(str, 0))
		er++;
	if (ft_strchr(str, 'B') != strchr(str, 'B'))
		er++;
	if (ft_strchr(str, 'W') != strchr(str, 'W'))
		er++;
	display_test("ft_strchr", er);
}

void	test_strrchr(void)
{
	char *str="Bonjour";
	int	er = 0;

	if (ft_strrchr(str, 'j') != strrchr(str, 'j'))
		er++;
	if (ft_strrchr(str, 'o') != strrchr(str, 'o'))
		er++;
	if (ft_strrchr(str, 0) != strrchr(str, 0))
		er++;
	if (ft_strrchr(str, 'B') != strrchr(str, 'B'))
		er++;
	if (ft_strrchr(str, 'W') != strrchr(str, 'W'))
		er++;
	display_test("ft_strcpy", er);
	display_test("ft_strrchr", er);
}

void	test_cat(int ac, char **av)
{
	ft_cat(0);
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(open(av[0], O_RDONLY));
	ft_cat(-42);
	(void)ac;
}

int main(int ac, char **av)
{
			test_bzero();
			test_strcat();
			test_isx();
			test_tox();
			test_puts();
			test_strlen();
			test_memset();
			test_memcpy();
			test_strdup();
			test_strequ();
			test_strchr();
			test_strrchr();
			test_cat(ac, av);

 	return (0);
}
