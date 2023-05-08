
export module person;

import <string>;

export class person {
	public:
		person(std::string first, std::string last) : m_firstName(std::move(first)), m_lastName(std::move(last)) { };
		const std::string & getFirstName() const  { return m_firstName; };
		const std::string & getLastName() const  { return m_lastName; };

	private:
		std::string m_firstName;
		std::string m_lastName;
};
