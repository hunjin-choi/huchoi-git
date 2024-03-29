#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char * name;
	int age;
public:
	Person(const char * myname, int myage)
	{
		int len=strlen(myname)+1;
		name=new char[len];
		strcpy(name, myname);
		age=myage;
	}
	/*Person& operator=(const Person& ref)
	//Person& Person::operator=(const Person& ref) 이렇게 쓰게되면 extra qualification on member 'operator=' 라는 에러메세지가 뜨게됨.
	{
		delete []name;

		int len=strlen(ref.name)+1;
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}*/
	void ShowPersonInfo() const
	{
		cout<<"이름: "<<name<<endl;
		cout<<"나이정보: "<<age<<endl;
	}

	~Person()
	{
		delete []name;
		cout<<"called destructor!"<<endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2=man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
