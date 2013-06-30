#include <iostream>

#include "duck.hpp"

// Making some duckish sounds
void Duck::quack() const
{
	std::cout << m_quacking << std::endl;
}

// Assignment required
const Duck& Duck::operator=( const Duck& right )
{
	m_quacking = right.m_quacking;
	return *this;
}