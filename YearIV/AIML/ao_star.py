from typing import Dict, List, Tuple

class Graph:
	def __init__(self, graph, heuristic_node_list, start_node):
		self.graph = graph
		self.H = heuristic_node_list
		self.start = start_node
		self.parent = {}
		self.status = {}
		self.solution_graph = {}

	def apply_ao_star(self):
		self.ao_star(self.start, False)

	def get_neighbors(self, v):
		return self.graph.get(v, [])

	def get_status(self, v):
		return self.status.get(v, 0)

	def set_status(self, v, val):
		self.status[v] = val

	def get_heuristic_node_value(self, n):
		return self.H.get(n, 0)

	def set_heuristic_node_value(self, n, value):
		self.H[n] = value

	def print_solution(self):
		print("TRAVERSE FROM THE START NODE:", self.start)
		print("-" * 30)
		print(self.solution_graph)
		print("-" * 30)

	def compute_minimum_cost_child_nodes(self, v):
		minimum_cost = 0
		cost_to_child_node_list_dict = {minimum_cost: []}
		flag = True
		for node_info_tuple_list in self.get_neighbors(v):
			cost = 0
			node_list = []
			for c, weight in node_info_tuple_list:
				cost += self.get_heuristic_node_value(c) + weight
				node_list.append(c)
			if flag:
				minimum_cost = cost
				cost_to_child_node_list_dict[minimum_cost] = node_list
				flag = False
			else:
				if minimum_cost > cost:
					minimum_cost = cost
					cost_to_child_node_list_dict[minimum_cost] = node_list
		return minimum_cost, cost_to_child_node_list_dict[minimum_cost]

	def ao_star(self, v, back_tracking):
		print("HEURISTIC VALUES:", self.H)
		print("SOLUTION GRAPH:", self.solution_graph)
		print("PROCESSING NODE:", v)
		print("-" * 40)
		if self.get_status(v) >= 0:
			minimum_cost, child_node_list = self.compute_minimum_cost_child_nodes(v)
			print(minimum_cost, child_node_list)
			self.set_heuristic_node_value(v, minimum_cost)
			self.set_status(v, len(child_node_list))
			solved = True
			for child_node in child_node_list:
				self.parent[child_node] = v
				if self.get_status(child_node) != -1:
					solved = solved & False
			if solved:
				self.set_status(v, -1)
				self.solution_graph[v] = child_node_list
			if v != self.start:
				self.ao_star(self.parent[v], True)
			if not back_tracking:
				for child_node in child_node_list:
					self.set_status(child_node, 0)
					self.ao_star(child_node, False)


print("Graph - 1")
h1: Dict[str, int] = {
					  'A': 1,
					  'B': 6,
					  'C': 2,
					  'D': 12,
					  'E': 2,
					  'F': 1,
					  'G': 5,
					  'H': 7,
					  'I': 7,
					  'J': 1
					 }

graph1: Dict[str, List[List[Tuple[str, int]]]] = {
	'A': [[('B', 1), ('C', 1)], [('D', 1)]],
	'B': [[('G', 1)], [('H', 1)]],
	'C': [[('J', 1)]],
	'D': [[('E', 1), ('F', 1)]],
	'G': [[('I', 1)]]
}

G1 = Graph(graph1, h1, 'A')
G1.apply_ao_star()
G1.print_solution()