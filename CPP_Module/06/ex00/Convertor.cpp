/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 02:25:48 by ijang             #+#    #+#             */
/*   Updated: 2021/04/22 12:46:01 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

Convertor::Convertor(std::string input)
	: input(input)
{
}

Convertor::Convertor(const Convertor &ref)
{
	this->input = ref.input;
}

Convertor& Convertor::operator=(const Convertor &ref)
{
	this->input = ref.input;
	return (*this);
}

Convertor::~Convertor()
{
}

void Convertor::printToChar() const
{
	std::cout << "char: ";
	int ret;

	try
	{
		ret = stoi(this->input);
		if (ret < -128 || ret > 127)
			throw std::out_of_range("");
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (ret > 32 && ret < 127)
		std::cout << "'" << static_cast<char>(ret) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void Convertor::printToInt() const
{
	std::cout << "int: ";
	int ret;

	try
	{
		ret = stoi(this->input);
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << ret << std::endl;
}

void Convertor::printToFloat() const
{
	std::cout << "float: ";
	float ret;

	try
	{
		ret = stof(this->input);
	}
	catch(const std::out_of_range& e)
	{
		if (this->input[0] == '-')
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
		return ;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (ret <= static_cast<float>(INT64_MIN) && ret >= static_cast<float>(INT64_MIN))
	{
		if (ret - static_cast<long long int>(ret) == 0)
			std::cout << ret << ".0f" << std::endl;
		else
			std::cout << ret << "f" << std::endl;
	}
	std::stringstream ss;

	ss.precision(100);
	ss << std::fixed;
	ss << ret;
	std::string str = ss.str();
	str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		std::cout << str << "0f" << std::endl;
	else
		std::cout << str << "f" << std::endl;
}

void Convertor::printToDouble() const
{
	std::cout << "double: ";
	double ret;

	try
	{
		ret = stod(this->input);
	}
	catch(const std::out_of_range& e)
	{
		if (this->input[0] == '-')
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
		return ;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (ret <= static_cast<double>(INT64_MIN) && ret >= static_cast<double>(INT64_MIN))
	{
		if (ret - static_cast<long long int>(ret) == 0)
			std::cout << ret << ".0f" << std::endl;
		else
			std::cout << ret << "f" << std::endl;
	}
	std::stringstream ss;

	ss.precision(1000);
	ss << std::fixed;
	ss << ret;
	std::string str = ss.str();
	str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		std::cout << str << "0" << std::endl;
	else
		std::cout << str << std::endl;
}
