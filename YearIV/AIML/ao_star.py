from typing import List, Tuple, Dict

class Graph:
	def __init__(self, graph: Dict[str, List[List[Tuple[str, int]]]], heuristic_node_list: Dict[str, int], start_node: str):
		self.graph = graph
		self.H = heuristic_node_list
		self.start = start_node
		self.parent: Dict[str, str] = {}
		self.status: Dict[str, int] = {}
		self.solution_graph: Dict[str, List[str]] = {}
		
	def apply_a_star(self):
		self.ao_star(self.start, False)

	def get_neighbors(self, v: str) -> List[List[Tuple[str, int]]]:
		return self.graph.get(v, '')

	def get_status(self, v: str) -> int:
		return self.status.get(v, 0)

	def set_status(self, v: str, val: int):
		self.status[v] = val

	def get_heuristic_node_value(self, n: str) -> int:
		return self.H.get(n, 0)

	def set_heuristic_node_value(self, n: str, value: int):
		self.H[n] = value

	def print_solution(self):
		print("GRAPH SOLUTION, START NODE is:", self.start)
		print("-"*65)
		print(self.solution_graph)
		print("-"*65)

	def compute_minimum_cost_child_nodes(self, v: str) -> Tuple[int, List[str]]:
		minimum_cost = 0
		cost_to_child_node_list_dict: Dict[int, List[str]] = {minimum_cost: []}
		flag = True
		for node_info_tuple_list in self.get_neighbors(v):
			cost = 0
			node_list: List[str] = []
			for c, weight in node_info_tuple_list:
				cost = cost + self.get_heuristic_node_value(c) + weight
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

	def ao_star(self, v: str, back_tracking: bool):
		print("HEURISTIC VALUES :", self.H)
		print("SOLUTION GRAPH :", self.solution_graph)
		print("PROCESSING NODE :", v)
		print("-"*65)
		if self.get_status(v) >= 0:
			minimum_cost, child_node_list = self.compute_minimum_cost_child_nodes(v)
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
	'J': 1}
graph1: Dict[str, List[List[Tuple[str, int]]]] = {
	'A': [[('B', 1), ('C', 1)], [('D', 1)]],
	'B': [[('G', 1)], [('H', 1)]],
	'C': [[('J', 1)]],
	'D': [[('E', 1), ('F', 1)]],
	'G': [[('I', 1)]]
}

G1: Graph = Graph(graph1, h1, 'A')
G1.apply_a_star()
G1.print_solution()