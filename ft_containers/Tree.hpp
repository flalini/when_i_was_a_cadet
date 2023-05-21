/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:01:18 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:11:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>

template <typename T>
struct Bnode
{
	Bnode	*parent;
	Bnode	*left;
	T		data;
	Bnode	*right;
};

template <typename T>
class BST
{
	private:
		Bnode<T>*	_root;
		size_t		_size;
	protected:
		Bnode<T>*	insert_node(Bnode<T>* node, T &data)
		{
			if (node == nullptr)
			{
				node = new Bnode<T>;
				node->data = data;
				node->left = nullptr;
				node->right = nullptr;
				node->parent = nullptr;
				_size++;
			}
			else if (data < node->data)
			{
				node->left = insert_node(node->left, data);
				node->left->parent = node;
			}
			else if (data > node->data)
			{
				node->right = insert_node(node->right, data);
				node->right->parent = node;
			}
			return (node);
		}
		void		print_in_order(Bnode<T> *node)
		{
			if (node == nullptr)
				return ;
			print_in_order(node->left);
			if (node->left)
				std::cout << "(" << node->left->data._key << ",";
			else
				std::cout << "(-1,";
			std::cout << node->data._key << ",";
			if (node->right)
				std::cout << node->right->data._key << ")";
			else
				std::cout << "-1)";
			print_in_order(node->right);
		}
		template <typename K>
		Bnode<T>*	search_node(Bnode<T>* node, K& key)
		{
			if (node == nullptr)
				return (nullptr);
			else if (key == node->data._key)
				return (node);
			else if (key < node->data._key)
				return search_node(node->left, key);
			else if (key > node->data._key)
				return search_node(node->right, key);
			return (nullptr);
		}
		Bnode<T>*	search_node(Bnode<T>* node, T& data)
		{
			if (node == nullptr)
				return (nullptr);
			else if (data == node->data)
				return (node);
			else if (data < node->data)
				return search_node(node->left, data);
			else if (data > node->data)
				return search_node(node->right, data);
			return (nullptr);
		}
		Bnode<T>*	find_min_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->left == nullptr)
				return (node);
			else
				return (find_min_node(node->left));
		}
		Bnode<T>*	find_max_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->right == nullptr)
				return (node);
			else
				return find_max_node(node->right);
		}
		Bnode<T>*	successor_node(Bnode<T>* node)
		{	
			if (node->right != nullptr)
				return find_min_node(node->right);
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->right))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		Bnode<T>*	predecessor_node(Bnode<T>* node)
		{
			if (node->left != nullptr)
				return (find_max_node(node->left));
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->left))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		Bnode<T>*	remove_node(Bnode<T>* node, T& data)
		{
			if (node == nullptr)
				return (nullptr);

			if (node->data == data)
			{	
				Bnode<T>* tmp_node = node;
				if (node->left == nullptr && node->right == nullptr)
				{
					node = nullptr;
					delete tmp_node;
					_size--;
				}
				else if (node->left == nullptr && node->right != nullptr)
				{
					node->right->parent = node->parent;
					node = node->right;
					delete tmp_node;
					_size--;
				}
				else if (node->left != nullptr && node->right == nullptr)
				{
					node->left->parent = node->parent;
					node = node->left;
					delete tmp_node;
					_size--;
				}
				else
				{
					Bnode<T>*	successor = predecessor_node(node);
					node->data = successor->data;
					node->left = remove_node(node->left, successor->data);
				}
			}
			else if (node->data < data)
				node->right = remove_node(node->right, data);
			else
				node->left = remove_node(node->left, data);
			return (node);
		}
		void		delete_node(Bnode<T>* node)
		{	
			if (node)
			{
				delete_node(node->left);
				delete node;
				_size--;
				delete_node(node->right);
			}
		}
		
	public:
		BST() : _root(nullptr), _size(0) {}
		~BST()
		{
			remove_all();
		}
		size_t		get_size()	{ return (_size); }
		void		insert(T data)
		{	
			if (_root)
			{
				Bnode<T>*	end_node = find_max();
				Bnode<T>*	max_node = end_node->parent;
				max_node->right = nullptr;
				delete end_node;
			}
			_root = insert_node(_root, data);
			Bnode<T>*	max_node = find_max();
			Bnode<T>*	end_node = new Bnode<T>;
			end_node->left = nullptr;
			end_node->right = nullptr;
			end_node->parent = max_node;
			max_node->right = end_node;
		}
		void		print_in_order()
		{
			std::cout << "[ ";
			print_in_order(_root);
			std::cout << "]" << std::endl;
		}
		template <typename K>
		Bnode<T>*		search(K key)
		{
			Bnode<T>* result = search_node(_root, key);
			return (result);	
		}
		Bnode<T>*		search(T data)
		{
			Bnode<T>* result = search_node(_root, data);
			return (result);
		}
		Bnode<T>*	find_min()
		{
			return (find_min_node(_root));
		}
		Bnode<T>*	find_max()
		{
			return (find_max_node(_root));
		}
		Bnode<T>*	successor(T data)
		{
			return (successor_node(search(data)));
		}
		Bnode<T>*	predecessor(T data)
		{
			return (predecessor_node(search(data)));
		}
		void		remove(T data)
		{	
			Bnode<T>* tmp = search(data);
			Bnode<T>* end_node = find_max();
			if (tmp->data == end_node->parent->data)
			{
				end_node->parent->right = nullptr;
				end_node->parent = nullptr;
				_root = remove_node(_root, data);
				Bnode<T>* max_node = find_max();
				max_node->right = end_node;
				end_node->parent = max_node;
			}
			else
				_root = remove_node(_root, data);
		}
		void			remove_all()
		{
			if (_root)
			{
				Bnode<T>* end_node = find_max();
				if (end_node->parent)
				{
					end_node->parent->right = nullptr;
					end_node->parent = nullptr;
					delete end_node;
				}
			}
			delete_node(_root);
			_root = nullptr;
		}
		size_t		get_size() const { return (_size); }
};

namespace ft
{
	template<class K, class V>
	struct Pair
	{
		public:
			K		_key;
			V		_value;
			
			Pair() {}
			Pair(K key, V value) : _key(key), _value(value) {}
			
			bool operator<(Pair& ref) { return (_key < ref._key); }
			bool operator<=(Pair& ref) { return (_key <=ref._key); }
			bool operator>(Pair& ref) { return (_key > ref._key); }
			bool operator>=(Pair& ref) { return (_key >= ref._key); }
			bool operator==(Pair& ref) { return (_key == ref._key); }
			bool operator!=(Pair& ref) { return (_key != ref._key); }
	};
};

#endif