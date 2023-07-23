def a_star(start_node, stop_node):
	open_set = set(start_node) A}, len{open_set} = 1
	closed_set = set()
	g = {} tore the distance from starting node
	parents = {}
	g[start_node] = 0
	parents[start_node] = start_node arents['A']='A"

	while len(open_set) > 0:
		n = None
		
		for v in open_set: ='B'/'F'
			if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
				n = v ='A'

		if n == stop_node or graph_nodes[n] == None:
			pass
		else:
			for (m, weight) in get_neighbors(n):
			 odes 'm' not in first and last set are added to first
			  is set its parent
				if m not in open_set and m not in closed_set:
					open_set.add(m)	  =B weight=6 {'F','B','A'} len{open_set}=2
					parents[m] = n	   arents={'A':A,'B':A} len{parent}=2
					g[m] = g[n] + weight ={'A':0,'B':6, 'F':3} len{g}=2


			or each node m,compare its distance from start i.e g(m) to the 
			rom start through n node
				else:
					if g[m] > g[n] + weight:
					pdate g(m)
						g[m] = g[n] + weight
					hange parent of m to n
						parents[m] = n

					if m in closed set, remove and add to open
						if m in closed_set:
							closed_set.remove(m)
							open_set.add(m)

		if n == None:
			print('Path does not exist!')
			return None
		if n == stop_node:
			path = []
			while parents[n] != n:
				path.append(n)
				n = parents[n]
			path.append(start_node)
			path.reverse()
			print('Path found: {}'.format(path))
			return path
		open_set.remove(n)'F','B'} len=2
		closed_set.add(n) A} len=1

	print('Path does not exist!')
	return None

def get_neighbors(v):
	if v in graph_nodes:
		return graph_nodes[v]
	return None

def heuristic(n):
	h_dist = {
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

	return h_dist[n]

graph_nodes = {
	
	'A': [('B', 6), ('F', 3)],
	'B': [('C', 3), ('D', 2)],
	'C': [('D', 1), ('E', 5)],
	'D': [('C', 1), ('E', 8)],
	'E': [('I', 5), ('J', 5)],
	'F': [('G', 1),('H', 7)] ,
	'G': [('I', 3)],
	'H': [('I', 2)],
	'I': [('E', 5), ('J', 3)],

}


a_star('A', 'J')
