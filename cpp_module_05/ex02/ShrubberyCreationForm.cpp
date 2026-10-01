#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", 145, 137),
_target("Anyone")
{
	print_debug("ShrubberyCreationForm default constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
	print_debug("ShrubberyCreationForm target constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
AForm("ShrubberyCreationForm", 145, 137),
_target(other._target)
{
	print_debug("ShrubberyCreationForm copy constructor");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	print_debug("ShrubberyCreationForm assignment operator");
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	print_debug("ShrubberyCreationForm destructor");
}

void ShrubberyCreationForm::executeAction()
{
	std::string trees =
	"                .o00o                             .o00o                             .o00o.\n"
	"              o000000oo                         o000000oo                         o000000oo\n"
	"             00000000000o                      00000000000o                      00000000000o\n"
	"            00000000000000                    00000000000000                    00000000000000\n"
	"         oooooo  00000000  o88o            oooooo  00000000  o88o            oooooo  00000000  o88o\n"
	"      ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888\n"
	"    OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'\n"
	"   oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
	"   OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
	"    OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
	"      OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'\n"
	"        OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'\n"
	"           \\\\. \\ |  // |                     \\\\. \\ |  // |                     \\\\. \\ |  // |\n"
	"           d\\ \\\\\\|_////                      d\\ \\\\\\|_////                      d\\ \\\\\\|_////\n"
	"           qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob\n"
	"              \\  / \\  \\Op                       \\  / \\  \\Op                       \\  / \\  \\Op\n"
	"              |  | O| |                         |  | O| |                         |  | O| |\n"
	"      _       /\\. \\_/ /\\                _       /\\. \\_/ /\\                _       /\\. \\_/ /\\\n"
	"       `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __\n"
	"             `-'  `-'`-'-'                     `-'  `-'`-'-'                     `-'  `-'`-'-'\n";
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << trees;
}
