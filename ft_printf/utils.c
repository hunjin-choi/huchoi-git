#include "./includes/ft_printf.h"

char * intger_value_is_zero(unsigned int num)
{
	char *arr;

	if ( 0== (arr = malloc(sizeof(char) * 2)))
		return (0);
	if (num != 0)
		return (0);
	arr[0] = '0';
	arr[1] = '\0';
	return (arr);
}

char *ten_small_hex(unsigned int num)
{
	char *hex;
	char temp[15];
	char *ret;
	int i;
	int j;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	if (0 == (hex = malloc(sizeof(char) *17)))
		return (0);
	ft_strlcpy(hex, "0123456789abcdef",17);
	while(num > 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i-- + 1))))
		return (0);
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char *ten_big_hex(unsigned int num)
{//%p할떄랑은 다른 방식을 취해야하는게 맞다..
	char *hex;
	char temp[15];
	char *ret;
	int i;
	int j;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	if (0 == (hex = malloc(sizeof(char) *17)))
		return (0);
	ft_strlcpy(hex, "0123456789ABCDEF",17);
	while(num > 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i-- + 1))))
		return (0);
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char *ten_unsigned(unsigned int num)
{
	char arr[16];
	char *ret;
	int i;
	int j;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	while (num > 0)
	{
		arr[i++] = (num % 10) + '0';
		num = num / 10;
	}
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	i--;
	while (i >= 0)
		ret[j++] = arr[i--];
	ret[j] = '\0';
	return (ret);
}

char *precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	char save;

	i = 0;
	if ( 0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
	ft_memset(ret, ' ', lenth);
	ret[lenth] = '\0';
	if (ft_strchr(line[1], '-') != 0)
	{
		while (i < plus)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
		if (i + size != lenth)
			ret[i + size] = ' ';
	}
	else
	{
		i = lenth - size - plus;
		while (i < lenth - size)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
	}
	return (minus_manage(line, &ret));
}

char *minus_manage(char **line, char **p_ret)
{
	if (ft_atoi(line[5]) < 0)
	{
		if (ft_strchr(*p_ret, '0') != 0)
		{
			*(ft_strchr(*p_ret, '0')) = '-';
			*(ft_strrchr(*p_ret, '-')) = '0';
			return (*p_ret);
		}
	}
	return (*p_ret);
}

char *precision_unsigned(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	char save;
	i = 0;

	ret = malloc(sizeof(char) * (lenth + 1));
	ft_memset(ret, ' ', lenth);
	ret[lenth] = '\0';
	if (ft_strchr(line[1], '-') != 0)
	{
		while (i < plus)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
		if (i + size != lenth)
			ret[i + size] = ' ';
	}
	else
	{
		i = lenth - size - plus;
		while (i < lenth - size)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
	}
	return (ret);
}

char *no_precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	unsigned int num;
	char two[2];

	i = 0;
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
	ret[lenth] = '\0';
	if (ft_strchr(line[1], '0') != 0)
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if(ft_strchr(line[1], '-') != 0)
	{
		ft_strlcpy(ret, line[5], size + 1);
		if (size != lenth)
			ft_memset(&ret[size], ' ', lenth - size);
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	two[1] = '\0';
	char *arr;
	if (ft_atoi(line[5]) < 0)
	{
		if(ft_strchr(ret, '0') != 0)
		{
			*(ft_strchr(ret, '0')) = '-';
			*(ft_strrchr(ret, '-')) = '0';
		}
	}
	return (ret);
}

char *no_precision_unsigned(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	unsigned int num;
	char two[2];

	i = 0;
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
	ret[lenth] = '\0';
	if (ft_strchr(line[1], '0') != 0)
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if(ft_strchr(line[1], '-') != 0)
	{
		ft_strlcpy(ret, line[5], size + 1);
		if (size != lenth)
			ft_memset(&ret[size], ' ', lenth - size);
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	return (ret);
}

int check_zero(char **line, int *p1, int *p2, int *p3)
{
	if (ft_atoi(line[5]) == 0 && ft_atoi(line[3]) == 0)
	{
		*p1 = 0;
		*p2 = 0;
		*p3 = 0;
		return (1);
	}
	else
		return (0);
}

int atoi_positive(char *str)
{
	int num;

	if (ft_strchr(str, '-'))
		*(ft_strchr(str, '-')) = '0';
	num = ft_atoi(str);
	return (num);
}

char *trim_the_zero(char **line)
{
	char *temp;
	char *ret;
	char *save;
	int size;

	if (ft_strlen(line[5]) == 3 && line[5][2] == '0')
		return (ft_strdup("0x0"));
	save = ft_strchr(line[5], 'x');
	save++;
	while (*save == '0')
		save++;
	size = ft_strlen(save) + 2;
	ret = malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	ret[0] = '0';
	ret[1] = 'x';
	ft_strlcpy(&ret[2], save, size - 1);
	return (ret);
}