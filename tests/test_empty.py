import unittest
from src.wbsplit import segments


class TestEmpty(unittest.TestCase):
    def test_empty(self):
        self.assertEqual(segments(""), [])


if __name__ == "__main__":
    unittest.main()
