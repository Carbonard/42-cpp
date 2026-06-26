#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		int		_saved;
		Contact	_contacts[MAX_CONTACTS];
	public:
		PhoneBook();
		bool	is_empty(void) const;
		void	display_all(void) const;
		void	display_one(int n) const;
		void	add_new_contact(void);
};

#endif
