#include "Form.hpp"

void Form::beSigned(Bureaucrat &src)
{
	if (this->sign_bound >= src.getGrade() && this->sign == false)
		this->sign = true;
	else if (this->sign_bound < src.getGrade())
		throw Form::GradeTooLowException();
	else
		throw std::exception();
}

void Form::check_boundary(Bureaucrat const &src) const
{
	if (this->sign == false)
		throw std::exception();
	else if (this->exec_bound < src.getGrade())
		throw Form::GradeTooLowException();
}

Form::Form(const char *name, int sign_bound, int exec_bound, std::string target) :name(name), sign_bound(sign_bound), exec_bound(exec_bound), sign(false), target(target)
{
	if (sign_bound < 1)
		throw GradeTooHighException();
	if (sign_bound >150)
		throw GradeTooLowException();
	if (exec_bound < 1)
		throw GradeTooHighException();
	if (exec_bound >150)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
{
	*this = src;
}

const Form & Form::operator=(const Form &src)
{
	this->name = src.getName();
	this->sign_bound = src.getSignGrade();
	this->exec_bound = src.getExecGrade();
	this->sign = src.getSign();
	return (*this);
}

Form::~Form()
{

}

const char * Form::GradeTooHighException::what() const _NOEXCEPT
{
	return "TOO HIGH  BOUND";
}


const char * Form::GradeTooLowException::what() const _NOEXCEPT
{
	return "TOO LOW  BOUND";
}

const std::string &Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int Form::getSignGrade() const
{
	return this->sign_bound;
}

int Form::getExecGrade() const
{
	return this->exec_bound;
}

std::string Form::getTarget() const
{
	return this->target;
}

void				Form::setName(std::string src)
{
	this->name = src;
}

void				Form::setSign(bool src)
{
	this->sign = src;
}

void				Form::setSignGrade(int src)
{
	this->sign_bound = src;
}

void				Form::setExecGrade(int src)
{
	this->exec_bound = src;
}

void	Form::setTarget(std::string src)
{
	this->target = src;
}

std::ostream& operator<<(std::ostream &ost, const Form &src)
{
	ost << "name: "<<src.getName()<<"  signed? "<<src.getSign()<<"  sign bound: "<<src.getSignGrade()<<"  exec bound: "<<src.getExecGrade();
	ost.flush();
	return ost;
}
