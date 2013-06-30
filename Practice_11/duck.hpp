#pragma once

#include <string>

/**
* A sweet quacking, probably yellow, duck.
* Does duck things.
*/
class Duck
{
public:
	Duck() : m_quacking("")
	{}

	Duck(const std::string& quackingPhrase) : 
		m_quacking(quackingPhrase)
	{}

	/// \brief Making some duckish sounds
	///
	void quack() const;

	const Duck& operator=( const Duck& right );

private:
	std::string m_quacking;
};