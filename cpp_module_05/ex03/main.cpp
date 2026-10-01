#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	
	Intern noName;
	int nbForms = 4;
	AForm *forms[nbForms];

	forms[0] = noName.makeForm("shrubbery creation", "target_1");
	forms[1] = noName.makeForm("robotomy request", "target_2");
	forms[2] = noName.makeForm("presidential pardon", "target_3");
	forms[3] = noName.makeForm("asdfghjkl", "target_4");

	for (int i = 0; i < nbForms; i++)
		delete forms[i];
}

/*
	DUDAS:
	- igualar forms (originales y ahora para llamar a aquella)
	- Default constructors?
*/