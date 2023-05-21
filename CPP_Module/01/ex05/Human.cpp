/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:14:30 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:18:47 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

const Brain &Human::getBrain(void) const
{
	return (this->brain);
}

std::string Human::identify(void) const
{
	return (this->brain.identify());
}
