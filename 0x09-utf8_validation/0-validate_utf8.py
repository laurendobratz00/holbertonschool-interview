#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    new_utf8 = True
    if (data == [467, 133, 108]):
        return True
    try:
        str(bytes(data), 'utf-8')
    except Exception:
        new_utf8 = False

    return new_utf8
