/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:00:01 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/14 18:47:01 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static void	ft_swap(t_node *a, t_node *b)
{
	t_node	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_heap_less_timestamp(t_node a, t_node b)
{
	if (a.key != b.key)
		return (a.key < b.key);
	return (a.id_coder < b.id_coder);
}

void	ft_heap_push(t_heap *heap, int id, long long key)
{
	heap->node_coders[heap->size].id_coder = id;
	heap->node_coders[heap->size].key = key;
	heap->size++;
	if (heap->size == 2)
	{
		if (ft_heap_less_timestamp(heap->node_coders[1], heap->node_coders[0]))
		{
			ft_swap(&(heap->node_coders[0]), &(heap->node_coders[1]));
		}
	}
}

int	ft_get_head_heap(t_heap *heap)
{
	if (heap->size == 0)
		return (-1);
	return (heap->node_coders[0].id_coder);
}

void	ft_heap_remove(t_heap *heap, int id_coder)
{
	int	size;

	size = heap->size;
	if (size == 0)
		return ;
	if (size == 2)
	{
		if (heap->node_coders[0].id_coder == id_coder)
		{
			heap->size--;
			heap->node_coders[0].id_coder = heap->node_coders[1].id_coder;
			heap->node_coders[0].key = heap->node_coders[1].key;
			return ;
		}
	}
	if (heap->node_coders[size - 1].id_coder == id_coder)
		heap->size--;
}
