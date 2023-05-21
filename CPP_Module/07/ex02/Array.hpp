/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:54:45 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 16:52:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array
{
	private:
		size_t length;
		T *elements;

	public:
		Array();
		Array(size_t n);
		Array(Array<T> const &other);
		virtual ~Array();

		class OutOfLimitsException: public std::exception {
			virtual const char* what() const throw();
		};

		Array &operator=(Array const &other);
		T &operator[](size_t index);
		T const &operator[](size_t index) const;

		size_t size(void) const;
};

template<typename T>
Array<T>::Array():
	length(0), elements(NULL)
{
}

template<typename T>
Array<T>::Array(size_t n):
	length(n), elements(NULL)
{
	this->elements = new T[n]();
}

template<typename T>
Array<T>::Array(Array const &other):
	length(0), elements(NULL)
{
	if (other.length > 0)
	{
		this->elements = new T[other.length]();
		for (size_t i = 0; i < other.length; i++)
			this->elements[i] = other.elements[i];
	}
	this->length = other.length;
}

template<typename T>
Array<T>::~Array()
{
	if (this->length > 0)
		delete[] this->elements;
}

template<typename T>
const char* Array<T>::OutOfLimitsException::what() const throw()
{
	return "ArrayException: index out of bounds";
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (this->length > 0)
		delete[] this->elements;
	this->elements = NULL;
	if (other.length > 0)
	{
		this->elements = new T[other.length]();
		for (size_t i = 0; i < other.length; i++)
			this->elements[i] = other.elements[i];
	}
	this->length = other.length;
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->length)
		throw Array::OutOfLimitsException();
	return (this->elements[index]);
}

template<typename T>
T const &Array<T>::operator[](size_t index) const
{
	return (operator[](index));
}

template<typename T>
size_t Array<T>::size(void) const
{
	return (this->length);
}

#endif
