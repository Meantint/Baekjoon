def preorder(node):
    print(node.key, end='')
    if node.lChild != '.':
        preorder(tree[node.lChild])
    if node.rChild != '.':
        preorder(tree[node.rChild])


def inorder(node):
    if node.lChild != '.':
        inorder(tree[node.lChild])
    print(node.key, end='')
    if node.rChild != '.':
        inorder(tree[node.rChild])


def postorder(node):
    if node.lChild != '.':
        postorder(tree[node.lChild])
    if node.rChild != '.':
        postorder(tree[node.rChild])
    print(node.key, end='')


class Node:
    def __init__(self, key, lChild, rChild):
        self.key = key
        self.lChild = lChild
        self.rChild = rChild


n = int(input())

tree = {}
# print(type(tree))
for i in range(n):
    node = input().split()
    tree[node[0]] = Node(key=node[0], lChild=node[1], rChild=node[2])

preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])
print()
