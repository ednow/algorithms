import unittest
from .RootOfAVLTree import *
from ppbtree import print_tree


class Test(unittest.TestCase):
    def test_left_rotate(self):
        """
        照着严书写左旋的时候总感觉很别扭,
        值拷贝和引用拷贝
        """
        # https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210814211901.png
        nodes = [Node(i) for i in range(7)]
        nodes[1].left = nodes[2]
        nodes[1].right = nodes[3]
        nodes[3].left = nodes[4]
        nodes[3].right = nodes[5]
        nodes[5].right = nodes[6]
        print_tree(nodes[1], left_child='right', right_child='left')
        left_rotate(nodes[1])
        print_tree(nodes[1], left_child='right', right_child='left')


if __name__ == '__main__':
    unittest.main()
