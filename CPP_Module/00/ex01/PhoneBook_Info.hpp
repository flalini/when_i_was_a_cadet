/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Info.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:36:28 by ijang             #+#    #+#             */
/*   Updated: 2021/02/24 17:13:24 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook_Info
{
	private:
		std::string	content[11];

	public:
		PhoneBook_Info();

		void			set_content(std::string str, int i);
		std::string		get_content(int i);
};

#endif
