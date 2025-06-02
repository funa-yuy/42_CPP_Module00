#ifndef CONTACT_HPP
# define CONTACT_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<string>

// ------------------------------------------------
// class
// ------------------------------------------------

//連絡先
class Contact {
	public:
		std::string f_name;	// 名
		std::string l_name;	// 姓
		std::string n_name;	// ニックネーム
		std::string phone_number;	// 電話番号
		std::string darkest_secret;	// 暗闇の秘密
};

#endif
