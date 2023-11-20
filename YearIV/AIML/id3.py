import csv
import math

class Node:
	def __init__(self):
		self.child_nodes = []
		self.attribute_value = ""
		self.is_leaf = False
		self.predicted_label = ""

def read_csv(file_path):
	with open(file_path, 'r') as file:
		reader = csv.DictReader(file)
		return [row for row in reader]

def calculate_entropy(examples):
	counts = {"yes": 0, "no": 0}
	for row in examples:
		counts[row["answer"]] += 1
	probs = [count / len(examples) for count in counts.values()]
	return -sum(p * math.log2(p) if p != 0 else 0 for p in probs)

def calculate_info_gain(examples, attr):
	unique_values = set(row[attr] for row in examples)
	entropy = calculate_entropy(examples)
	for value in unique_values:
		subdata = [row for row in examples if row[attr] == value]
		entropy -= (len(subdata) / len(examples)) * calculate_entropy(subdata)
	return entropy

def build_id3_tree(examples, attributes):
	root = Node()
	max_feature = max(attributes, key=lambda feature: calculate_info_gain(examples, feature))
	root.attribute_value = max_feature
	unique_values = set(row[max_feature] for row in examples)
	for value in unique_values:
		subdata = [row for row in examples if row[max_feature] == value]
		if calculate_entropy(subdata) == 0:
			new_node = Node()
			new_node.is_leaf = True
			new_node.attribute_value = value
			new_node.predicted_label = {row["answer"] for row in subdata}
			root.child_nodes.append(new_node)
		else:
			dummy_node = Node()
			dummy_node.attribute_value = value
			new_attributes = attributes.copy()
			new_attributes.remove(max_feature)
			child = build_id3_tree(subdata, new_attributes)
			dummy_node.child_nodes.append(child)
			root.child_nodes.append(dummy_node)
	return root

def print_tree(root, depth=0):
	print("\t" * depth + root.attribute_value, "->", root.predicted_label if root.is_leaf else "<NOTLEAF>")
	for child in root.child_nodes:
		print_tree(child, depth + 1)

def classify_example(root, new_example):
	for child in root.child_nodes:
		if child.attribute_value == new_example[root.attribute_value]:
			if child.is_leaf:
				# print("Predicted Label for new example", new_example, " is:", child.predicted_label)
				return
			else:
				classify_example(child.child_nodes[0], new_example)

data = read_csv("./data/id3.csv")
input_features = list(data[0].keys())
input_features.remove("answer")
print(input_features)

id3_tree = build_id3_tree(data, input_features)
# print("Decision Tree is:")
print_tree(id3_tree)
# print("------------------")

new_sample = {"outlook": "sunny", "temperature": "hot", "humidity": "normal", "wind": "strong"}
classify_example(id3_tree, new_sample)