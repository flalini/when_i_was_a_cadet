/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:02:29 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:09:30 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{
	template<typename T, typename K = ft::List<T> >
	class Queue
	{
		public:
			typedef size_t size_type;
			typedef T value_type;
			typedef K container_type;
			typedef T* pointer;
			typedef T const * const_pointer;
			typedef T& reference;
			typedef T const & const_reference;
		protected:
			container_type container;
		public:
			Queue(container_type const &container=container_type()): container(container) {}
			Queue(Queue<T, K> const &other): container(other.container) {}
			virtual ~Queue() {}

			Queue &operator=(Queue const &other) {
				this->container = other.container;
				return (*this);
			}

			bool empty(void) const {
				return (this->container.empty());
			}
			size_t size(void) const {
				return (this->container.size());
			}

			reference front(void) {
				return (this->container.front());
			}
			const_reference front(void) const {
				return (this->container.front());
			}

			reference back(void) {
				return (this->container.back());
			}
			const_reference back(void) const {
				return (this->container.back());
			}

			void push(const_reference val) {
				this->container.push_back(val);
			}
			void pop(void) {
				this->container.pop_front();
			}

			template<typename queue_type, typename container_type>
			friend bool operator==(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container == rhs.container);
			}

			template<typename queue_type, typename container_type>
			friend bool operator!=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container != rhs.container);
			}

			template<typename queue_type, typename container_type>
			friend bool operator<(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container < rhs.container);
			}

			template<typename queue_type, typename container_type>
			friend bool operator<=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container <= rhs.container);
			}

			template<typename queue_type, typename container_type>
			friend bool operator>(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container > rhs.container);
			}

			template<typename queue_type, typename container_type>
			friend bool operator>=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
				return (lhs.container >= rhs.container);
			}
	};
}

#endif
