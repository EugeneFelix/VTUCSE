def a_star(start, stop):
	open_set, closed_set = {start}, set()
	g, parents = {start: 0}, {start: start}

	while open_set:
		current = min(open_set, key=lambda node: g[node] + H_dist.get(node, None))
		if current == stop or current not in graph_nodes:
			pass
		else:
			for neighbor, weight in graph_nodes.get(current, None):
				print(neighbor)
				if neighbor not in open_set and neighbor not in closed_set:
					open_set.add(neighbor)
					parents[neighbor] = current
					g[neighbor] = g[current] + weight
				elif g[neighbor] > g[current] + weight:
					open_set.add(neighbor)
					parents[neighbor] = current
					g[neighbor] = g[current] + weight
					closed_set.discard(neighbor)
		if not current:
			print('Path does not exist!')
			return
		if current == stop:
			path: List = []
			while parents[current] != current:
				path.append(current)
				current = parents[current]
			path.append(start)
			path.reverse()
			print('Path found:', path)
			return path
		open_set.remove(current)
		closed_set.add(current)
	print('Path does not exist!')
	return None

H_dist = {
		  'A': 10,
		  'B': 8,
		  'C': 5,
		  'D': 7,
		  'E': 3,
		  'F': 6,
		  'G': 5,
		  'H': 3,
		  'I': 1,
		  'J': 0
		}

graph_nodes = {
	'A': [('B', 6), ('F', 3)],
	'B': [('C', 3), ('D', 2)],
	'C': [('D', 1), ('E', 5)],
	'D': [('C', 1), ('E', 8)],
	'E': [('I', 5), ('J', 5)],
	'F': [('G', 1), ('H', 7)],
	'G': [('I', 3)],
	'H': [('I', 2)],
	'I': [('E', 5), ('J', 3)]
}

# f(n) = g(n) + h(n)
a_star('A', 'J')