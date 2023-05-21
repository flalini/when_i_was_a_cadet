/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:07:04 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:18:40 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <string>

class Human
{
	private:
		const Brain brain;

	public:
		Human();
		~Human();

		const Brain &getBrain(void) const;
		std::string identify(void) const;
};

#endif
