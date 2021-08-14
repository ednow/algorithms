import unittest

import pptree

from .RootOfAVLTree import *
from ppbtree import print_tree
import pptree


class Test(unittest.TestCase):
    @unittest.skip
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
        # pptree.print_tree(nodes[1], horizontal=False)

    def test_right_rotate(self):
        """
        # https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210815011828.png
        """
        nodes = [Node(i) for i in range(7)]
        nodes[1].right = nodes[3]
        nodes[1].left = nodes[2]
        nodes[2].left = nodes[4]
        nodes[2].right = nodes[5]
        nodes[4].left = nodes[6]
        print_tree(nodes[1], left_child='right', right_child='left')
        right_rotate(nodes[1])
        print_tree(nodes[1], left_child='right', right_child='left')

    @unittest.skip
    def test_pptree(self):
        shame = pptree.Node("shame")

        conscience = pptree.Node("conscience", shame)
        selfdisgust = pptree.Node("selfdisgust", shame)
        embarrassment = pptree.Node("embarrassment", shame)

        selfconsciousness = pptree.Node("selfconsciousness", embarrassment)
        shamefacedness = pptree.Node("shamefacedness", embarrassment)
        chagrin = pptree.Node("chagrin", embarrassment)
        discomfiture = pptree.Node("discomfiture", embarrassment)
        abashment = pptree.Node("abashment", embarrassment)
        confusion = pptree.Node("confusion", embarrassment)

        pptree.print_tree(shame)


if __name__ == '__main__':
    unittest.main()
