/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:02:25 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:16:07 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include <string>

class Brain
{
	private:
		int lifespan;

	public:
		Brain();
		~Brain();

		int getLifespan(void) const;
		std::string identify(void) const;
};

#endif
