from collections import Counter
import numpy as np
import unittest
import numpy.ma as npm

data = """3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0"""


class StrokeTest(unittest.TestCase):
    @unittest.skip
    def test_sum_all(self):
        # 不是简单的算1的个数
        dataInt = list(map(int, data.replace("\n", " ").split(" ")[4:]))
        count = Counter(dataInt)
        print(count)  # Counter({0: 32, 1: 28})

    @unittest.skip
    def test_sum_by_slice(self):
        # 也不是总的体积大于2即可
        dataInt = list(map(int, data.replace("\n", " ").split(" ")[4:]))
        x = np.array(dataInt)
        x = x.reshape((-1, 3, 4))
        print(x)
        # [[[1 1 1 1]
        #   [1 1 1 1]
        #   [1 1 1 1]]
        #
        # [[0 0 1 1]
        #  [0 0 1 1]
        #  [0 0 1 1]]
        #
        # [[1 0 1 1]
        #  [0 1 0 0]
        #  [0 0 0 0]]
        #
        # [[1 0 1 1]
        #  [0 0 0 0]
        #  [0 0 0 0]]
        #
        # [[0 0 0 1]
        #  [0 0 0 1]
        #  [1 0 0 0]]]
        a = x.sum(axis=0)
        print(a)
        # [[3 1 4 5]
        #  [1 2 2 3]
        #  [2 1 2 2]]
        b = a.flatten()
        print(sum(np.where(b < 2, 0, b)))  # 25

    @unittest.skip
    def test_sum_by_two_slice(self):
        dataInt = list(map(int, data.replace("\n", " ").split(" ")[4:]))
        x = np.array(dataInt)
        x = x.reshape((-1, 3, 4))
        result = 0
        for a, b in zip(x[0:-1], x[1:]):
            result += (a+b).sum()
        print(result)
        # 41

    @unittest.skip
    def test_get_matrix(self):
        x = np.array([i for i in range(12 * 5)]).reshape((-1, 3, 4))
        dataInt = list(map(int, data.replace("\n", " ").split(" ")[4:]))
        y = np.array(dataInt).reshape((-1, 3, 4))
        mask = y == 0
        print(npm.array(x, mask=mask))
        # [[[0 1 2 3]
        #   [4 5 6 7]
        #   [8 9 10 11]]
        #
        # [[-- -- 14 15]
        #  [-- -- 18 19]
        #  [-- -- 22 23]]
        #
        # [[24 -- 26 27]
        #  [-- 29 -- --]
        #  [-- -- -- --]]
        #
        # [[36 -- 38 39]
        #  [-- -- -- --]
        #  [-- -- -- --]]
        #
        # [[-- -- -- 51]
        #  [-- -- -- 55]
        #  [56 -- -- --]]]

    def test_gen_test_data(self):
        a = np.ones(1286 * 128 * 60, int).reshape(-1, 4)
        result = ""
        for line in a:
            result += (" ".join(map(str, line)) + '\n')
        print("%r" % result)

def summit():
    pass


if __name__ == '__main__':
    # summit()
    unittest.main()
