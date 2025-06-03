#ifndef CONTACT_HPP
# define CONTACT_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<string>

// ------------------------------------------------
// class
// ------------------------------------------------

class Contact {
	public:
		enum ContactFild {
			F_name,
			L_name,
			N_name,
			Phone_number,
			Darkest_secret,
		};
		void	setInfo(ContactFild fild, const std::string& value);
		std::string	getInfo(ContactFild fild);

	private:
		std::string	info_[5];
};

#endif
