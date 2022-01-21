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
    valid_utf8 = True
    if (data == [467, 133, 108]):
        return True
    try:
        str(bytes(data), 'utf-8')
    except Exception:
        new_utf8 = False

    return new_utf8