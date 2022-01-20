#!/usr/bin/python3
""" queries the Reddit API and counts key words """
from collections import OrderedDict
import json
import requests


"""
def Convert(word_list):
    it = iter(word_list)
    res_dct = dict(zip(it, it))
    return res_dct
"""


def count_words(subreddit, word_list, word_list_dict={}, count=0, after=None):
    """ returns number of subscribers """
    word_list_dict = OrderedDict(word_list_dict)
    headers = {
        'User-Agent': 'nugget'
    }
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    parameter = {'limit': 100, 'after': after}
    x = requests.get(url, headers=headers, params=parameter,
                     allow_redirects=False)
    if x.status_code != 200:
        return None
    data = x.json()
    r = data.get('data')
    after = r.get('after')
    words = r.get('children')
    """
    if not subreddit:
        return None
    if not data:
        return None
    """
    # = Convert(word_list)
    for s in words:
        body = (s.get('data')['title']).lower()
        for j in body.split():
            for key in word_list:
                key = key.lower()
                if j == key:
                    # = dict.fromkeys(word_list)
                    if key in word_list_dict.keys():
                        word_list_dict[key] += 1
                    else:
                        word_list_dict[key] = 1
                    # += dict.fromkeys(word_list)
    if after is not None:
        return (count_words(subreddit, word_list,
                            word_list_dict, count, after))
    else:
        for n in sorted(word_list_dict, key=word_list_dict.get, reverse=True):
            print('{}: {}'.format(n, word_list_dict[n]))
