#include "Contact.hpp"

void	Contact::setInfo(ContactFild fild, const std::string& value) {
	info[fild] = value;
}
std::string	Contact::getInfo(ContactFild fild) {
	return (info[fild]);
}
