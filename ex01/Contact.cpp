#include "Contact.hpp"

// Contact::setInfo ---------------------------------------------

void	Contact::setInfo(ContactFild fild, const std::string& value) {
	info_[fild] = value;
}

// Contact::getInfo ---------------------------------------------

std::string	Contact::getInfo(ContactFild fild) {
	return (info_[fild]);
}
