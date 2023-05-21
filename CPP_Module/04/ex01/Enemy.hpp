/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:37 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:24:58 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy
{
	private:
		Enemy();

		std::string type;
		int hp;

	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &other);
		virtual ~Enemy();

		Enemy &operator=(Enemy const &other);

		std::string const &getType(void) const;
		int getHP(void) const;

		virtual void takeDamage(int damage);
};

#endif
