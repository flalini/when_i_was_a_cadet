/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:14:47 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 13:24:37 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRT_HPP
# define IRT_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void);

void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif
