#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string _darkest_secret;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
	public:
		Contact();
		void ask_for_input(void);
		void display(void) const;
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
};

#endif
