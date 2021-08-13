import unittest
from .IsBinarySearchTree import Node


class TestNode(unittest.TestCase):

    def test_set_node_not_swap(self):
        n = Node(9)
        n.left = 1
        n.right = 2
        assert n.left == 1, n.left
        assert n.right == 1, n.right

    def test_set_node_swap(self):
        n = Node(9)
        Node.swap = True
        n.left = 1
        n.right = 2
        assert n.left == 1, n.left
        assert n.right == 1, n.right


if __name__ == '__main__':
    unittest.main()
