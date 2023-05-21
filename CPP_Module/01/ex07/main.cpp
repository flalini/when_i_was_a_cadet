/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:24:41 by ijang             #+#    #+#             */
/*   Updated: 2021/04/11 15:31:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void	argCheck(int argc, char **argv)
{
	if (argc != 4)
		throw "Three argument (filename and two strings) are required.";
	else if (std::string(argv[1]).length() == 0)
		throw "Filename is empty.";
	else if (std::string(argv[2]).length() == 0)
		throw "Search string is empty.";
	else if (std::string(argv[3]).length() == 0)
		throw "Replace string is empty.";
}

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	input(filename);

	if (!input.is_open())
		throw (filename + ": couldn't be opened.");

	input.seekg(0, std::ios::end);
	if (input.tellg() == -1)
	{
		input.close();
		throw (filename + ": stream error");
	}
	std::string::size_type	len = input.tellg();
	std::string				content;
	content.resize(len);
	input.seekg(0, std::ios::beg);
	input.read(&content[0], len);

	len = 0;
	while ((len = content.find(s1, len)) != std::string::npos)
	{
		content.replace(len, s1.length(), s2);
		len += s2.length();
	}
	
	std::ofstream	output(filename + ".replace", std::ios_base::trunc);
	
	if (!output.is_open())
	{
		input.close();
		throw (filename + ".replace: couldn't be opened.");
	}

	output << content;
	input.close();
	output.close();
}

int		main(int argc, char **argv)
{
	try
	{
		argCheck(argc, argv);
	}
	catch (char const *e)
	{
		std::cerr << argv[0] << ": error: " << e << std::endl;
		return (1);
	}
	try
	{
		replace(argv[1], argv[2], argv[3]);
	}
	catch (std::string e)
	{
		std::cerr << argv[0] << ": error: " << e << std::endl;
		return (2);
	}
	return (0);
}