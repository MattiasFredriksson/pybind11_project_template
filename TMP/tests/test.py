import unittest
import sys
import os
module_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "../out/build/x64-Release/TMP_pybind")
sys.path.insert(0, module_path)
import TMP



class Unittest(unittest.TestCase):


    def setUpClass():
        pass

    def test(self):

        out = TMP.add(2, 2)
        assert out == 4, 'Expected add to be 4 was %i' % (out)
        out = TMP.subtract(2, 2)
        assert out == 0, 'Expected add to be 0 was %i' % (out)
        out = TMP.sq(2)
        assert out == 4, 'Expected add to be 4 was %i' % (out)



if __name__ == '__main__':
    unittest.main()
