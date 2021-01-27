#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
//va_strat
//va_arg
//va_copy
//va_end
int ft_printf(const char* str, ...)
{
	va_list ap;//va_list *ap is not correct
	va_start(ap, str);//just init!!
	//va_arg(ap, char *) -> (ap가 가리키는 대상 x)
	//문자열에서 str 포인터가 가리키는값을 char *로 해석참조해서 그 값을 반환한다.
	//이때, 참조만 하는거기 때문에 포인터의 변화, data의 변화등등은 없을것이다.
	//그러니까 char *parr = va_args(ap, char *) 이렇게 쓰는게 맞을것이다.
	char* arr;
	char *temp = ft_calloc(999999);//메모리크기 근거가 부족하다. 1로 바꿧다 이떄는 근거가 있다.
	char ch;
	int	num;
	int count;
	char **final = malloc(sizeof(char *) * 6);
	char *buf = 0;
	char *two = ft_calloc(2);
	int i = 0;
	int j;
	while(str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1);
		}	continue;
		i++;
		j = 0;
		//temp 의 모든 요소가0으로 초기화된상태...? 그건 보장안함.
		//buf는 항상 0인 상태로 루프 진입한다
		int case;
		case = what_case(str[i]);
		while(ft_strcmp(str[i], "cspdiuxX%") == 0)
		{
			if (case != what_case(str[i]))
			{}
				arr[case] = ft_strdup(temp);
				case = what_case(str[i]);
				memset(temp, 0, ft_strlen(temp + 1));//ft_strlen(temp)해줘도 될거같긴한데.
			}
			if(case == 3)
				i++;//사소하지만 중요한 부분
			if (str[i] != '*')
			{	
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
			}
			else
			{
				buf = ft_itoa(va_arg(ap, int));
				ft_strjoin(temp, buf)
				free(buf);
				buf = 0;
			}
		}
		arr[case] = ft_strdup(temp);
		memset(temp, 0, ft_strlen(temp));

		the_type = str[i];
		//type_to_data(&temp, va_arg(ap, ))//tpye_to_Data(char **p_temp, void data)
		if(the_type == 'c')
		{
			two[0] = (char)va_arg(ap, int);
			ft_strjoin(temp, two);
		}
		if(the_type == 's')
		{
			ft_strjoin(temp, va_arg(ap, char *));
		}
		if(the_type == 'p')
		{
			printf("pointer...!!!")
		}
		if(the_type == '%')
		{
			two[0] = '%';
			ft_strjoin(temp, two);
		}
		else
		{
			arr[5] = ft_itoa(va_arg(ap, int));//일단 가변인자쪽은 무조건 10진수 정수이다???,.,말이 이상하긴한데 암튼 그럼...
			//그래서 일단 10진수로 해석하고 그 이후에 저장해놓은 the_tyep에 맞게 변환하면 되겠다. 이 작업은 make_string에서 하겠다.
		}
		ft_putstr_fd(make_string(the_type,temp), 1)//출력할 문자열을 멩글어 주는 함수//여기서 여러가지 분기가 일어나겠다.
		temp에서 맨 뒤부터 보겠.
		i++;//사소하지만 중요한 부분
	}
	return (count);
}