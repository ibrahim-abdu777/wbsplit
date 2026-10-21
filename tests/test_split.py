import unittest
from src.wbsplit import segments


class TestSplit(unittest.TestCase):
    def test_splits(self):
        self.assertEqual(segments("hello world"), ["hello", "world"])


if __name__ == "__main__":
    unittest.main()
