#include "ft_printf.h"
int what_my_case(char c, int now_case)//처리의 목적을 밝히시오....
{
    if (c == '-' || c == '0')
    {
		if (now_case <= 1)
			return (1);
	}
    if(('0' <= c && c <= '9') || c == '*')
    {    if ((now_case <= 2))
			return (2);
	}
    if(('0' <= c && c <= '9') || c == '.' || c == '*')
    {
	    if (now_case <= 3)
			return (3);
	}
    if (ft_strchr("cspdiuxX%", c) != 0)
        return (5);
    return (-1);
}

int ft_printf(const char* str, ...)
{
	va_list ap;//va_list *ap is not correct
	va_start(ap, str);//just init!!
	//va_arg(ap, char *) -> (ap가 가리키는 대상 x)
	//문자열에서 str 포인터가 가리키는값을 char *로 해석참조해서 그 값을 반환한다.
	//이때, 참조만 하는거기 때문에 포인터의 변화, data의 변화등등은 없을것이다.
	//그러니까 char *parr = va_args(ap, char *) 이렇게 쓰는게 맞을것이다.
	char* arr;
	char *temp;//메모리크기 근거가 부족하다. 1로 바꿧다 이떄는 근거가 있다.
	char ch;
	int	num;
	int count;
	char **final = malloc(sizeof(char *) * 7);
	char *buf = 0;
	char two[2];
	int i = 0;
	int j;
	char the_type;
	int my_case;
	two[1] = '\0';
	temp = 0;
	while (str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			continue;
		}
		i++;
		my_case = 1;
		if (temp != 0)
			free(temp);
		temp = malloc(sizeof(char) * 1);
		*temp = '\0';
		while(ft_strchr("cspdiuxX%", str[i]) == 0)
		{
			if (my_case != what_my_case(str[i], my_case))
			{
				final[my_case] = ft_strdup(temp);
				my_case++;
				ft_memset(temp, '\0', sizeof(char)*(ft_strlen(temp) + 1));//ft_strlen(temp)해줘도 될거같긴한데.
				*temp = '\0';
				continue;
			}
			if(str[i] == '.')
			{	
				i++;//사소하지만 중요한 부분
				continue;
			}
			if (str[i] == '-' || str[i] == '0')
			{
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
				i++;
				continue;
			}
			if (str[i] != '*')
			{
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
				i++;
				continue;
			}
			else
			{
				buf = ft_itoa(va_arg(ap, int));
				temp = ft_strjoin(temp, buf);
				free(buf);
				buf = 0;
				i++;
				if (what_my_case(str[i], my_case) == my_case)//%*42.42s  이런 경우는 나오면 안되는 case.
					return (-1);
				continue;
			}
		}
		final[my_case] = ft_strdup(temp);
		my_case++;
		while (my_case < 5)
		{
			final[my_case] = ft_strdup("");
			my_case++;
		}
		ft_memset(temp, '\0', ft_strlen(temp) + 1);
		*temp = '\0';
		the_type = str[i];
		//type_to_data(&temp, va_arg(ap, ))//tpye_to_Data(char **p_temp, void data)
		if(the_type == 'c')
		{
			two[0] = (char)va_arg(ap, int);
			temp = ft_strjoin(temp, two);
		}
		if(the_type == 's')
		{
			arr = va_arg(ap, char *);
			temp = ft_strdup(arr);
		}
		else if(the_type == 'p')
		{
			printf("pointer...!!!");
		}
		else if(the_type == '%')
		{
			two[0] = '%';
			temp = ft_strjoin(temp, two);
		}
		else
		{
			temp = ft_itoa(va_arg(ap, int));//일단 가변인자쪽은 무조건 10진수 정수이다???,.,말이 이상하긴한데 암튼 그럼...
			//그래서 일단 10진수로 해석하고 그 이후에 저장해놓은 the_tyep에 맞게 변환하면 되겠다. 이 작업은 make_string에서 하겠다.
		}
		final[5] = ft_strdup(temp);
		printf("%s\n%s\n%s\n%s\n%s\n",final[1], final[2], final[3],final[4], final[5]);
		//ft_putstr_fd(make_string(the_type,temp), 1);//출력할 문자열을 멩글어 주는 함수//여기서 여러가지 분기가 일어나겠다.
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//ft_putstr_fd(make_string(the_type,temp), 1);
		//출력할 문자열을 멩글어 주는 함수//여기서 여러가지 분기가 일어나겠다.

		//temp에서 맨 뒤부터 보겠.
		i++;//사소하지만 중요한 부분
	}
	return (count);
}

int main(void)
{
	ft_printf("test%--00--*.*s",42,21,"huchoi");
	return (0);
}
