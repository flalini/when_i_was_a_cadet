/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:02:19 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:07:49 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>
# include "utils.hpp"

namespace ft
{
	template <typename T>
	class ListIterator
	{
		public:
			typedef T			value_type;
			typedef Node<T>*	pointer;
			typedef T&			reference;

		protected:
			pointer			 _ptr;

		public:
			ListIterator()
			{}
			ListIterator(pointer ptr) : _ptr(ptr)
			{}
			ListIterator(const ListIterator &ref)
			{
				*this = ref;
			}
			ListIterator &operator=(const ListIterator &ref)
			{
				_ptr = ref._ptr; return (*this);
			}
			~ListIterator() {}

			pointer getNode() const
			{
				return (_ptr);
			}
			
			bool operator==(const ListIterator &ref) const
			{
				return (_ptr == ref._ptr);
			}
			bool operator!=(const ListIterator &ref) const
			{
				return (_ptr != ref._ptr);
			}
			value_type &operator*()
			{
				return (_ptr->data);
			};
			value_type operator->()
			{
				return (_ptr);
			}
			ListIterator &operator++()
			{
				_ptr = _ptr->next;
				return (*this);
			}
			ListIterator operator++(int)
			{
				ListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			ListIterator &operator--()
			{
				_ptr = _ptr->prev; return (*this);
			}
			ListIterator operator--(int)
			{
				ListIterator tmp(*this);
				operator--();
				return (tmp);
			}
	};
	template <typename T>
	class ReverseListIterator
	{
		 public:
			typedef T			value_type;
			typedef Node<T>*	pointer;
			typedef T&			reference;

		protected:
			pointer			 _ptr;

		public:
			ReverseListIterator()
			{}
			ReverseListIterator(pointer ptr) : _ptr(ptr)
			{}
			ReverseListIterator(const ReverseListIterator &ref)
			{
				*this = ref;
			} 
			ReverseListIterator &operator=(const ReverseListIterator &ref)
			{
				_ptr = ref._ptr; return (*this);
			}
			~ReverseListIterator()
			{}

			bool				operator==(const ReverseListIterator &ref) const
			{
				return (_ptr == ref._ptr);
			} 
			bool				operator!=(const ReverseListIterator &ref) const
			{
				return (_ptr != ref._ptr);
			}
			value_type		  &operator*()
			{
				return (_ptr->data);
			};
			value_type		  operator->()
			{
				return (_ptr);
			}
			ReverseListIterator &operator++()
			{
				_ptr = _ptr->prev;
				return (*this);
			}	
			ReverseListIterator operator++(int)
			{
				ReverseListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			ReverseListIterator &operator--()
			{
				_ptr = _ptr->next;
				return (*this);
			}	
			ReverseListIterator operator--(int)
			{
				ReverseListIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
	};
	template <typename T>
	class ConstListIterator
	{
		public:
			typedef T			value_type;
			typedef Node<T>*	pointer;
			typedef T&			reference;

		protected:
			pointer			 _ptr;

		public:
			ConstListIterator()
			{}
			ConstListIterator(pointer ptr) : _ptr(ptr)
			{}
			ConstListIterator(const ConstListIterator &ref)
			{
				*this = ref;
			}
			ConstListIterator &operator=(const ConstListIterator &ref)
			{
				_ptr = ref._ptr;
				return (*this);
			}
			~ConstListIterator()
			{}

			pointer getNode() const
			{
				return (_ptr);
			}
			
			bool				operator==(const ConstListIterator &ref) const
			{
				return (_ptr == ref._ptr);
			}	
			bool				operator!=(const ConstListIterator &ref) const
			{
				return (_ptr != ref._ptr);
			}		  
			const value_type	&operator*()
			{
				return (_ptr->data);
			};										
			const value_type	operator->()
			{
				return (_ptr);
			}											 
			ConstListIterator   &operator++()
			{
				_ptr = _ptr->next;
				return (*this);
			}					   
			ConstListIterator   operator++(int)
			{
				ConstListIterator tmp(*this);
				operator++();
				return (tmp);
			}   
			ConstListIterator   &operator--()
			{
				_ptr = _ptr->prev;
				return (*this);
			}					  
			ConstListIterator   operator--(int)
			{
				ConstListIterator tmp(*this);
				operator--();
				return (tmp);
			}   
	};
	template <typename T>
	class ConstReverseListIterator
	{
		public:
			typedef T			value_type;
			typedef Node<T>*	pointer;
			typedef T&			reference;

		protected:
			pointer			 _ptr;

		public:
			ConstReverseListIterator()
			{}
			ConstReverseListIterator(pointer ptr) : _ptr(ptr)
			{}
			ConstReverseListIterator(const ConstReverseListIterator &ref)
			{
				*this = ref;
			}
			ConstReverseListIterator &operator=(const ConstReverseListIterator &ref)
			{
				_ptr = ref._ptr;
				return (*this);
			}
			~ConstReverseListIterator()
			{}

			pointer getNode() const
			{
				return (_ptr);
			}	  
			
			bool				operator==(const ConstReverseListIterator &ref) const
			{
				return (_ptr == ref._ptr);
			}	
			bool				operator!=(const ConstReverseListIterator &ref) const
			{
				return (_ptr != ref._ptr);
			}		  
			const value_type	&operator*()
			{
				return (_ptr->data); 
			}										
			const value_type	operator->()
			{
				return (_ptr);
			}											 
			ConstReverseListIterator   &operator++()
			{
				_ptr = _ptr->prev;
				return (*this);
			}					   
			ConstReverseListIterator   operator++(int)
			{
				ConstReverseListIterator tmp(*this);
				operator++();
				return (tmp);
			}   
			ConstReverseListIterator   &operator--()
			{
				_ptr = _ptr->next;
				return (*this);
			}
			ConstReverseListIterator   operator--(int)
			{
				ConstReverseListIterator tmp(*this);
				operator--();
				return (tmp);
			}   
	};

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef T*								pointer;
			typedef const T*						const_pointer;
			typedef ft::ListIterator<T>				iterator;
			typedef ft::ConstListIterator<T>		const_iterator;
			typedef ft::ReverseListIterator<T>		reverse_iterator;
			typedef ft::ConstReverseListIterator<T>	const_reverse_iterator;
			typedef size_t							size_type;
		
		private:
			Node<T>*			_first;
			Node<T>*			_last;
			allocator_type		_allocator;
			size_type			_length;
			Node<T>*			_make_new_node(Node<T> *prev, value_type value, Node<T> *next)
			{
				Node<T>* node = new Node<T>;
				node->prev = prev;
				node->data = value;
				node->next = next;
				return (node);
			}
			void				_init_list()
			{
				_first = _make_new_node(nullptr, value_type(), nullptr);
				_last = _make_new_node(_first, value_type(), nullptr);
				_first->next = _last;
			}
			void				_set_first_last_node()
			{
				if (_length == 0)
				{
					 _first->data = value_type();
					_last->data = value_type();
				}
				else if (_length == 1)
				{   
					_last->data = 1;
					_first->data = _last->data;
				}
				else
				{
					_last->data = _last->prev->data;
					_first->data = _last->data;
				}
			}
			template <typename N>
			bool				_eqaul(const N& a, const N& b)
			{
				return (a == b);
			}
			
		public:
			explicit List(const allocator_type& alloc = allocator_type())
				: _length(0)
			{
				(void)alloc;
				_init_list();
			}
			explicit List(size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
				: _length(0)
			{
				(void)alloc;
				_init_list();
				assign(n, val);
			}
			template <class InputIterator>
			List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				: _length(0)
			{
				(void)alloc;
				_init_list();
				assign(first, last);
			}
			List (const List& x)
				: _length(0)
			{
				_init_list();
				assign(x.begin(), x.end());
				_length = x._length;
			}
			~List()
			{
				clear();
				delete _first;
				delete _last;
			}
			List &operator=(const List &x)
			{
				clear();
				assign(x.begin(), x.end());
				_length = x._length;
				return (*this);
			}
			iterator				begin()
			{
				return (iterator(_first->next));
			}
			const_iterator			begin() const
			{
				return (const_iterator(_first->next));
			}
			iterator				end()
			{
				return (iterator(_last));
			}
			const_iterator			end() const
			{
				return (const_iterator(_last));
			}
			reverse_iterator		rbegin()
			{
				return (reverse_iterator(_last->prev));
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(_last->prev));
			}
			reverse_iterator		rend()
			{
				return (reverse_iterator(_first));
			}
			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(_first));
			}
			bool					empty() const
			{
				return (_length == 0);
			}
			size_type				size() const
			{
				return (_length);
			}
			size_type				max_size() const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
			}
			reference				front()
			{
				return (_first->next->data);
			}
			const_reference			front() const
			{
				return (_first->next->data);
			}
			reference				back()
			{
				return (_last->prev->data);
			}
			const_reference			back() const
			{
				return (_last->prev->data);
			}

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			void	assign(size_type n, const value_type& val)
			{
				clear();
				while (n--)
					push_back(val);
			}
			void	push_front(const value_type& val)
			{
				Node<T>* new_node = _make_new_node(_first, val, _first->next);
				_first->next->prev = new_node;
				_first->next = new_node;
				_length++;
				_set_first_last_node();
			}
			void	pop_front()
			{
				Node<T>* after = _first->next->next;
				delete _first->next;
				after->prev = _first;
				_first->next = after;
				_length--;
				 _set_first_last_node();
			}
			void	push_back(const value_type& val)
			{
				Node<T>* new_node = _make_new_node(_last->prev, val, _last);
				_last->prev->next = new_node;
				_last->prev = new_node;
				_length++;
				_set_first_last_node();
			}
			void	pop_back()
			{
				Node<T>* before = _last->prev->prev;
				delete _last->prev;
				before->next = _last;
				_last->prev = before;
				_length--;
				_set_first_last_node();
			}
			iterator	insert(iterator position, const value_type& val)
			{
				if (position == begin())
				{
					push_front(val);
					return (begin());
				}
				else if (position == end())
				{
					push_back(val);
					return (end());
				}
				Node<T>* after = position.getNode();
				Node<T>* before = after->prev;
				Node<T>* inserted_node = _make_new_node(before, val, after);
				before->next = inserted_node;
				after->prev = inserted_node;
				_length++;
				return (iterator(inserted_node));
			}
			void		insert(iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(position, val);
			}
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first);
					first++;
					if (position != end())
						++position;
				}
			}
			iterator	erase(iterator position)
			{
				if (position == begin())
				{
					pop_front();
					return (begin());
				}
				else if (position == end())
				{
					pop_back();
					return (end());
				}
				Node<T>* before = position.getNode()->prev;
				Node<T>* after = position.getNode()->next;
				delete position.getNode();
				before->next = after;
				after->prev = before;
				_length--;
				_set_first_last_node();
				return (iterator(after));
			}
			iterator	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				return (first);
			}
			void		swap(List &x)
			{
				ft::swap(x._length, _length);
				ft::swap(x._first, _first);
				ft::swap(x._last, _last);
			}
			void		resize(size_type n, value_type val = value_type())
			{
				while (_length > n)
					pop_back();
				while (_length < n)
					push_back(val);
			}
			void		clear()
			{
				Node<T>* node = _first->next;
				while (node != _last)
				{
					Node<T>* next = node->next;
					delete node;
					node = next;
				}
				_first->next = _last;
				_last->prev = _first;
				_length = 0;
				_set_first_last_node();
			}

			void		splice(iterator position, List& x)
			{
				splice(position, x, x.begin(), x.end());
			}
			void		splice(iterator position, List& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}
			void		splice(iterator position, List& x, iterator first, iterator last)
			{
				insert(position, first, last);
				x.erase(first, last);
			}
			void remove(const value_type& val)
			{
				iterator iter = begin();
				while (iter != end())
				{
					if (*iter == val)
						iter = erase(iter);
					else
						iter++;
				}
			}
			template <class Predicate>
			void		remove_if(Predicate pred)
			{
				iterator iter = begin();
				while (iter != end())
				{
					if (pred(*iter))
						iter = erase(iter);
					else 
						iter++;
				}
			}
			void		unique()
			{
				unique(this->_eqaul);
			}
			template <class BinaryPredicate>
			void		unique(BinaryPredicate binary_pred)
			{
				iterator iter = begin();
				iterator next_iter = ++begin();
				while (iter != --end())
				{
					if (binary_pred(*iter, *next_iter))
						next_iter = erase(next_iter);
					else
					{
						iter = next_iter;
						next_iter++;
					}
				}
			}
			void		merge(List& x)
			{
				if (&x == this)
					return ;
				insert(begin(), x.begin(), x.end());
				x.clear();
				sort();
			}
			template <class Compare>
			void		merge(List& x, Compare comp)
			{
				if (&x == this)
					return ;
				insert(end(), x.begin(), x.end());
				x.clear();
				for (iterator it = begin(); it != --end(); it++)
				{
					for (iterator next_it = it; next_it != end(); next_it++)
					{
						if (comp(*it, *next_it))
							ft::swap(*it, *next_it);
					}
				}
			}
			void		sort()
			{
				for (iterator it = begin(); it != --end(); it++)
				{
					for (iterator next_it = it; next_it != end(); next_it++)
					{
						if (*it > *next_it)
							ft::swap(*it, *next_it);
					}
				}
			}
			template <class Compare>
			void		sort(Compare comp)
			{
				for (iterator it = begin(); it != --end(); it++)
				{
					for (iterator next_it = it; next_it != end(); next_it++)
					{
						if (!comp(*it, *next_it))
							ft::swap(*it, *next_it);
					}
				}
			}
			void		reverse()
			{
				size_type i = 0;
				iterator first = begin();
				iterator last = --end();
				while (i != _length / 2)
				{
					ft::swap(*first, *last);
					first++;
					last--;
					i++;
				}
			}
	};
	template <typename T>
	bool operator==(List<T>& lhs, List<T>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename List<T>::iterator l_iter = lhs.begin();
		typename List<T>::iterator r_iter = rhs.begin();
		while (l_iter != lhs.end())
		{
			if (*l_iter != *r_iter)
				return (false);
			l_iter++;
			r_iter++;
		}
		return (true);
	};
	template <typename T>
	bool operator!=(List<T>& lhs, List<T>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <typename T>
	bool operator<(List<T>& lhs, List<T>& rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		typename List<T>::iterator l_iter = lhs.begin();
		typename List<T>::iterator r_iter = rhs.begin();
		while (l_iter != lhs.end())
		{
			if (*l_iter != *r_iter)
				return (*l_iter < *r_iter);
			l_iter++;
			r_iter++;
		}
		return (false);
	}
	template <typename T>
	bool operator<=(List<T> &lhs, List<T> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <typename T>
	bool operator>(List<T> &lhs, List<T> &rhs)
	{
		return (rhs < lhs);
	}
	template <typename T>
	bool operator>=(List<T> &lhs, List<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	template <typename T>
	void swap(List<T> &x, List<T> &y)
	{
		x.swap(y);
	}	
};

#endif