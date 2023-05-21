/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapBase.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:42:44 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:09:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPBASE_HPP
# define MAPBASE_HPP

# include <iostream>
# include "Tree.hpp"

namespace ft
{
	template <class Key, class T>
	class MapIterator
	{
		public:
			typedef ft::Pair<Key, T>			value_type;
			typedef ft::Pair<Key, T>&			reference;
			typedef Bnode<ft::Pair<Key, T> >*	pointer;

		protected:
			pointer					_ptr;

		private:
			pointer	find_min_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->left == nullptr)
					return (node);
				else
					return (find_min_node(node->left));
			}
			pointer	find_max_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->right == nullptr)
					return (node);
				else
					return find_max_node(node->right);
			}
			pointer	successor_node(pointer node)
			{	
				if (node->right != nullptr)
					return find_min_node(node->right);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
	
					while ((parent != nullptr) && (current == parent->right))
					{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			pointer	predecessor_node(pointer node)
			{
				if (node->left != nullptr)
					return find_min_node(node->left);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
					while ((parent != nullptr) && (current == parent->left))
   	 				{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			
		public:
			MapIterator() : _ptr(nullptr) {}
			MapIterator(pointer ptr) : _ptr(ptr) {}
			MapIterator(const MapIterator &ref) { *this = ref; }
			MapIterator	&operator=(const MapIterator &ref) { _ptr = ref._ptr; return (*this); }
			~MapIterator() {}
			value_type	&operator*() { return (_ptr->data); }
			value_type	*operator->() { return (&_ptr->data); }
			MapIterator	&operator++() { _ptr = successor_node(_ptr); return (*this); }
			MapIterator	operator++(int) { MapIterator tmp(*this); operator++(); return (tmp); }
			MapIterator	&operator--() { _ptr = predecessor_node(_ptr); return (*this); }
			MapIterator	operator--(int) { MapIterator tmp(*this); operator--(); return (tmp); }
			bool		operator==(const MapIterator<Key, T> &ref) 
			{
				return (_ptr->data == ref._ptr->data);
			}
			bool		operator!=(const MapIterator<Key, T> &ref) 
			{
				return (_ptr->data != ref._ptr->data);
			}
	};
	template <class Key, class T>
	class ConstMapIterator
	{
		public:
			typedef ft::Pair<Key, T>			value_type;
			typedef ft::Pair<Key, T>&			reference;
			typedef Bnode<ft::Pair<Key, T> >*	pointer;
		
		protected:
			pointer						_ptr;

		private:
			pointer	find_min_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->left == nullptr)
					return (node);
				else
					return (find_min_node(node->left));
			}
			pointer	find_max_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->right == nullptr)
					return (node);
				else
					return find_max_node(node->right);
			}
			pointer	successor_node(pointer node)
			{	
				if (node->right != nullptr)
					return find_min_node(node->right);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
	
					while ((parent != nullptr) && (current == parent->right))
					{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			pointer	predecessor_node(pointer node)
			{
				if (node->left != nullptr)
					return find_min_node(node->left);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
					while ((parent != nullptr) && (current == parent->left))
   	 				{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			
		public:
			ConstMapIterator() : _ptr(nullptr) {}
			ConstMapIterator(pointer ptr) : _ptr(ptr) {}
			ConstMapIterator(const ConstMapIterator &ref) { *this = ref; }
			ConstMapIterator &operator=(const ConstMapIterator &ref) { _ptr = ref._ptr; return (*this); }
			~ConstMapIterator() {}
			value_type  &operator*() { return (_ptr->data); }
			value_type  *operator->() { return (&_ptr->data); }
			ConstMapIterator &operator++() { _ptr = successor_node(_ptr); return (*this); }
			ConstMapIterator operator++(int) { ConstMapIterator tmp(*this); operator++(); return (tmp); }
			ConstMapIterator &operator--() { _ptr = predecessor_node(_ptr); return (*this); }
			ConstMapIterator operator--(int) { ConstMapIterator tmp(*this); operator--(); return (tmp); }
			bool		operator==(const ConstMapIterator<Key, T> &ref) 
			{
				return (_ptr->data == ref._ptr->data);
			}
			bool		operator!=(const ConstMapIterator<Key, T> &ref) 
			{
				return (_ptr->data != ref._ptr->data);
			}
	};
	
	template <class Key, class T>
	class ReverseMapIterator
	{
		public:
			typedef ft::Pair<Key, T>		   value_type;
			typedef ft::Pair<Key, T>&		  reference;
			typedef Bnode<ft::Pair<Key, T> >*  pointer;
		
		protected:
			pointer				 _ptr;

		private:
			pointer	find_min_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->left == nullptr)
					return (node);
				else
					return (find_min_node(node->left));
			}
			pointer	find_max_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->right == nullptr)
					return (node);
				else
					return find_max_node(node->right);
			}
			pointer	successor_node(pointer node)
			{	
				if (node->right != nullptr)
					return find_min_node(node->right);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
	
					while ((parent != nullptr) && (current == parent->right))
					{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			pointer	predecessor_node(pointer node)
			{
				if (node->left != nullptr)
					return find_min_node(node->left);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
					while ((parent != nullptr) && (current == parent->left))
   	 				{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			
		public:
			ReverseMapIterator() : _ptr(nullptr) {}
			ReverseMapIterator(pointer ptr) : _ptr(ptr) {}
			ReverseMapIterator(const ReverseMapIterator &ref) { *this = ref; }
			ReverseMapIterator &operator=(const ReverseMapIterator &ref) { _ptr = ref._ptr; return (*this); }
			~ReverseMapIterator() {}
			value_type  &operator*() { return (_ptr->data); }
			value_type  *operator->() { return (&_ptr->data); }
			ReverseMapIterator &operator++() { _ptr = predecessor_node(_ptr); return (*this); }
			ReverseMapIterator operator++(int) { ReverseMapIterator tmp(*this); operator++(); return (tmp); }
			ReverseMapIterator &operator--() { _ptr = successor_node(_ptr); return (*this); }
			ReverseMapIterator operator--(int) { ReverseMapIterator tmp(*this); operator--(); return (tmp); }
			bool		operator==(const ReverseMapIterator<Key, T> &ref) 
			{
				return (_ptr->data == ref._ptr->data);
			}
			bool		operator!=(const ReverseMapIterator<Key, T> &ref) 
			{
				return (_ptr->data != ref._ptr->data);
			}
	};

	template <class Key, class T>
	class ConstReverseMapIterator
	{
		public:
			typedef ft::Pair<Key, T>		   value_type;
			typedef ft::Pair<Key, T>&		  reference;
			typedef Bnode<ft::Pair<Key, T> >*  pointer;
		
		protected:
			pointer				 _ptr;

		private:
			pointer	find_min_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->left == nullptr)
					return (node);
				else
					return (find_min_node(node->left));
			}
			pointer	find_max_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->right == nullptr)
					return (node);
				else
					return find_max_node(node->right);
			}
			pointer	successor_node(pointer node)
			{	
				if (node->right != nullptr)
					return find_min_node(node->right);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
	
					while ((parent != nullptr) && (current == parent->right))
					{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			pointer	predecessor_node(pointer node)
			{
				if (node->left != nullptr)
					return find_min_node(node->left);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
					while ((parent != nullptr) && (current == parent->left))
   	 				{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			
		public:
			ConstReverseMapIterator() : _ptr(nullptr) {}
			ConstReverseMapIterator(pointer ptr) : _ptr(ptr) {}
			ConstReverseMapIterator(const ConstReverseMapIterator &ref) { *this = ref; }
			ConstReverseMapIterator &operator=(const ConstReverseMapIterator &ref) { _ptr = ref._ptr; return (*this); }
			~ConstReverseMapIterator() {}
			value_type  &operator*() { return (_ptr->data); }
			value_type  *operator->() { return (&_ptr->data); }
			ConstReverseMapIterator &operator++() { _ptr = predecessor_node(_ptr); return (*this); }
			ConstReverseMapIterator operator++(int) { ConstReverseMapIterator tmp(*this); operator++(); return (tmp); }
			ConstReverseMapIterator &operator--() { _ptr = successor_node(_ptr); return (*this); }
			ConstReverseMapIterator operator--(int) { ConstReverseMapIterator tmp(*this); operator--(); return (tmp); }
			bool		operator==(const ConstReverseMapIterator<Key, T> &ref) 
			{
				return (_ptr->data == ref._ptr->data);
			}
			bool		operator!=(const ConstReverseMapIterator<Key, T> &ref) 
			{
				return (_ptr->data != ref._ptr->data);
			}
	};
};

#endif
