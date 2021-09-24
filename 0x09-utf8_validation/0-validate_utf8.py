#!/usr/bin/python3
"""
a method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
        Check that a sequence of byte values follows the UTF-8 encoding
        rules.  Does not check for canonicalization (i.e. overlong encodings
        are acceptable).

        >>> s = Solution()
        >>> s.validUtf8([197, 130, 1])
        True
        >>> s.validUtf8([235, 140, 4])
        False
    """
    data = iter(data)
    for leading_byte in data:
        leading_ones = _count_leading_ones(leading_byte)
        if leading_ones in [1, 7, 8]:
            return False        # Illegal leading byte
        for _ in range(leading_ones - 1):
            trailing_byte = next(data, None)
            if trailing_byte is None or trailing_byte >> 6 != 0b10:
                return False    # Missing or illegal trailing byte
    return True


def _count_leading_ones(byte):
    for i in range(8):
        if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
            return i
    return 8
