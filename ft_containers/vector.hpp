/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:02:37 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:11:47 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <limits>
# include "utils.hpp"

namespace ft
{
	template<typename T>
	class VectorIterator
	{
		public:
			typedef T	value_type;
			typedef T&	references;
			typedef T*	pointer;

		protected:
			pointer		_ptr;

		public:
			VectorIterator()
			{}
			VectorIterator(pointer ptr) : _ptr(ptr)
			{}
			VectorIterator(const VectorIterator &ref)
			{
				*this = ref;
			}
			VectorIterator& operator=(const VectorIterator &ref)
			{
				_ptr = ref._ptr;
				return (*this);
			}
			~VectorIterator()
			{}

			VectorIterator 	&operator++()
			{
				_ptr++;
				return (*this);
			}
			VectorIterator 	operator++(int)
			{
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			}
			bool 			operator==(const VectorIterator &ref) const
			{
				return (_ptr == ref._ptr);
			}
			bool 			operator!=(const VectorIterator &ref) const
			{
				return (_ptr != ref._ptr);
			}
			value_type 		&operator*()
			{
				return (*_ptr);
			}
			value_type 		*operator->()
			{
				return (_ptr);
			}
			VectorIterator 	&operator--()
			{
				_ptr--;
				return (*this);
			}
			VectorIterator 	operator--(int)
			{
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			VectorIterator 	operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			VectorIterator 	operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}
			bool 			operator<(const VectorIterator &ref) const
			{
				return (_ptr < ref._ptr);
			}
			bool 			operator>(const VectorIterator &ref) const
			{
				return (_ptr > ref._ptr);
			}
			bool 			operator<=(const VectorIterator &ref) const 
			{
				return (_ptr <= ref._ptr);
			}
			bool 			operator>=(const VectorIterator &ref) const
			{
				return (_ptr >= ref._ptr);
			}
			VectorIterator	&operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}
			VectorIterator 	&operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}
			value_type 		&operator[] (int n)
			{
				return (*(*this + n));
			}
	};
	template<typename T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	references;
			typedef T*	pointer;

			ReverseVectorIterator()
			{}
			ReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}
			ReverseVectorIterator(const ReverseVectorIterator &ref)
			{
				*this = ref;
			}
			ReverseVectorIterator &operator=(const ReverseVectorIterator &ref)
			{
				this->_ptr = ref._ptr;
				return (*this);
			}
			~ReverseVectorIterator()
			{}

			ReverseVectorIterator	&operator++(void)
			{
				this->_ptr--;
				return (*this);
			}
			ReverseVectorIterator	operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			}
			ReverseVectorIterator	operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}
			ReverseVectorIterator	operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			ReverseVectorIterator	&operator--(void)
			{
				this->_ptr++;
				return (*this);
			}
			ReverseVectorIterator	operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr++;
				return (tmp);
			}
			ReverseVectorIterator	&operator+=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}
			ReverseVectorIterator	&operator-=(int n)
			{
				this->_ptr += n;
				return (*this);
			}
			bool 					operator<(const ReverseVectorIterator &ref) const
			{
				return (this->_ptr > ref._ptr);
			}
			bool 					operator>(const ReverseVectorIterator &ref) const
			{
				return (this->_ptr < ref._ptr);
			}
			bool 					operator<=(const ReverseVectorIterator &ref) const
			{
				return (this->_ptr >= ref._ptr);
			}
			bool 					operator>=(const ReverseVectorIterator &ref) const
			{
				return (this->_ptr <= ref._ptr);
			}
			value_type 				&operator[](int n) const
			{
				return (*(*this + n));
			}
	};
	template<typename T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T 	value_type;
			typedef T& 	reference;
			typedef T*	pointer;

			ConstVectorIterator()
			{}
			ConstVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}
			ConstVectorIterator(const ConstVectorIterator &ref)
			{
				*this = ref;
			}
			ConstVectorIterator &operator=(const ConstVectorIterator &ref)
			{
				this->_ptr = ref._ptr;
				return (*this);
			}
			~ConstVectorIterator()
			{}

			const value_type &operator*()
			{
				return (*this->_ptr);
			}
			const value_type &operator[](int n) const
			{
				return (*(*this + n));
			}
	};
	template<typename T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstReverseVectorIterator()
			{}
			ConstReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}
			ConstReverseVectorIterator(const ConstReverseVectorIterator &ref)
			{
				*this = ref;
			}
			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &ref)
			{
				this->_ptr = ref._ptr;
				return (*this);
			}
			~ConstReverseVectorIterator()
			{}

			const value_type &operator*(void)
			{
				return (*this->_ptr);
			}
			const value_type &operator[](int n) const
			{
				return (*(*this - n));
			}
	};

	template<typename T, typename A = std::allocator<T> >
	class Vector
	{
		public:
			typedef T									value_type;
			typedef A									allocator_type;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef ft::VectorIterator<T>				iterator;
			typedef ft::ReverseVectorIterator<T> 		reverse_iterator;
			typedef ft::ConstVectorIterator<T>			const_iterator;
			typedef ft::ConstReverseVectorIterator<T>	const_reverse_iterator;
			typedef size_t								size_type;

		private:
			pointer							_arr;
			size_type						_length;
			size_type						_capacity;
			allocator_type					_allocator;

		public:
			explicit Vector(const allocator_type &allocator = allocator_type())
				: _arr(nullptr), _length(0), _capacity(0), _allocator(allocator)
			{
				_arr = _allocator.allocate(0);
			}
			explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _arr(nullptr), _length(0), _capacity(0), _allocator(alloc)
			{
				_arr = _allocator.allocate(0);
				assign(n, val);
			}
			template <class InputIterator>
         	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				: _arr(nullptr), _length(0), _capacity(0), _allocator(alloc)
			{
				_arr = _allocator.allocate(0);
				assign(first, last);
			}
			Vector (const Vector& x)
				: _arr(nullptr), _length(0), _capacity(0), _allocator(x._allocator)
			{
				*this = x;		
			}
			~Vector()
			{
				_allocator.deallocate(_arr, _capacity);
			}
			Vector& operator= (const Vector& x)
			{
				if (_arr != nullptr)
					_allocator.deallocate(_arr, _capacity);
				_allocator = x._allocator;
				_length = x._length;
				_capacity = x._capacity;
				_arr = _allocator.allocate(0);
				assign(x.begin(), x.end());
				return (*this);
			}

			iterator 				begin()
			{
				return (iterator(_arr));
			}
			const_iterator 			begin() const 
			{
				return (const_iterator (_arr));
			}
			iterator 				end()
			{
				return (iterator(_arr + _length));
			}
			const_iterator			end() const
			{
				return (const_iterator(_arr + _length));
			}
			reverse_iterator 		rbegin()
			{
				return (reverse_iterator(_arr + _length - 1));
			}
			const_reverse_iterator 	rbegin() const
			{
				return (const_reverse_iterator(_arr + _length - 1));
			}
			reverse_iterator		rend()
			{
				return (reverse_iterator(_arr - 1));
			}
			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(_arr - 1));
			}

			size_type 				size() const
			{
				return (_length);
			}
			size_type 				max_size() const
			{
				return (std::numeric_limits<size_t>::max() / sizeof(value_type));
			}
			void 					resize(size_type n, value_type val = value_type())
			{
				while (n > _length)
					push_back(val);
				while (n < _length)
					pop_back();
			}
			size_type 				capacity() const
			{
				return (_capacity);
			}
			bool 					empty() const
			{
				return (_length == 0);
			}
			void 					reserve(size_type n)
			{
				if (_capacity < n)
				{
					pointer	tmp = _allocator.allocate(n);	// 새로운 사이즈 메모리를 할당
					_capacity = n;
					for (size_type i = 0; i < _length; i++)
						tmp[i] = _arr[i];
					_allocator.deallocate(_arr, _capacity);
					_arr = tmp;
				}
			}

			reference				operator[](size_type n)
			{
				return _arr[n];
			}
			const_reference 		operator[](size_type n) const
			{
				return _arr[n];
			}
			reference 				at(size_type n)
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}
			const_reference 		at(size_type n) const
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}
			reference 				front()
			{
				return (_arr[0]);
			}
			const_reference 		front() const
			{
				return (_arr[0]);
			}
			reference 				back()
			{
				return (_arr[_length - 1]);
			}
			const_reference 		back() const
			{
				return (_arr[_length - 1]);
			}

			template <class InputIterator>
			void					assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}
			void					assign(size_type n, const value_type& val)
			{
				clear();
				insert(begin(), n, val);
			}
			void 					push_back(const value_type &val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_length >= _capacity)
					reserve(_capacity * 2);
				_arr[_length] = val;
				_length++;
			}
			void 					pop_back()
			{
				if (_length != 0)
					_length--;
			}
			iterator				insert(iterator position, const value_type& val)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _length)
					i++;
				if (_capacity == 0)
					reserve(1);
				else if (_length >= _capacity)
					reserve(_capacity * 2);
				size_type j = _capacity - 1;
				while (j > i)
				{
					_arr[j] = _arr[j - 1];
					j--;
				}
				_arr[i] = val;
				_length++;
				return (iterator(&_arr[i]));
			}
			void					insert(iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(position, val);
			}
			template<class InputIterator>
			void					insert(iterator position, InputIterator begin, InputIterator end)
			{
				while (begin != end)
				{
					position = insert(position, *begin) + 1;
					begin++;
				}
			}
			iterator				erase(iterator position)
			{
				iterator iter = position;
				while (iter + 1 != end())
				{
					*iter = *(iter + 1);
					iter++;
				}
				_length--;
				return (iterator(position));
			}
			iterator				erase(iterator begin, iterator end)
			{
				while (begin != end)
				{
					erase(begin);
					end--;
				}
				return (iterator(begin));
			}
			void					swap(Vector &ref)
			{
				ft::swap(_arr, ref._arr);
				ft::swap(_length, ref._length);
				ft::swap(_capacity, ref._capacity);
			}
			void					clear()
			{
				erase(begin(), end());
			}
	};
	template <class T, class Alloc>
	bool operator==(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template <class T, class Alloc>
	bool operator!=(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		return (!(a == b));
	}
	template <class T, class Alloc>
	bool operator<(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		size_t			n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		for (size_t i = 0; i < n; i++)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
		}
		return (a.size() < b.size());
	};
	template <class T, class Alloc>
	bool operator<=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (a < b || a == b);
	};
	template <class T, class Alloc>
	bool operator>(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}
	template <class T, class Alloc>
	bool operator>=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b));
	};
	template <class T, class Alloc>
	void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
	{
		x.swap(y);
	};
};

#endif
