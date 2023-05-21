/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:03:49 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:06:29 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain():
	lifespan(1)
{
}

Brain::~Brain()
{
}

int Brain::getLifespan(void) const
{
	return (this->lifespan);
}

std::string Brain::identify(void) const
{
	std::stringstream ss;

	ss << "0x" << std::uppercase << std::hex << (unsigned long)this;
//	ss << this;
	return (ss.str());
}
