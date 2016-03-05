#!/bin/python

import re
from os import mkdir
from os.path import exists
from multiprocessing import Pool
from requests import get
from bs4 import BeautifulSoup as BS
from pyquery import PyQuery as PQ

import urllib3
urllib3.disable_warnings()

PROBLEMSET_URL = 'https://leetcode.com/problemset/algorithms/'
PROBLEM_URL = 'https://leetcode.com/problems/{}/'

MATCH_NAME = re.compile(r'/[^/]*/([^/]*)/$')

TEMPLATES = {
    'cpp': '''\
/** \
%s
**/

#include <iostream>
#include "../utils.h"
using namespace std;

int main() {
    Solution s;
    return 0;
}
''',
    'py': '''\
#-*- encoding: utf-8 -*-
""" \
%s
"""

import sys, os
sys.path.append(os.path.abspath('..'))
from utils import *

if __name__ == "__main__":
    s = Solution()

#
''',
}

TYPE = 'cpp'

def save(name):
    print('Processing {}'.format(name))
    soup = BS(get(PROBLEM_URL.format(name), verify=False).content, 'lxml')
    title = soup.find(class_='question-title')
    if not title:
        print('Cannot open {}'.format(name))
        return
    title = title.h3.string
    title = '0' * (3-title.find('.')) + title
    content = soup.find(class_='question-content').get_text()
    info = title + '\n' + content
    info = info.replace('\u000d', '\n')
    info = re.sub(r'[\n]{3,}', r'\n\n', info)
    AD = 'Subscribe to see which companies asked this question'
    info = info[:info.find(AD)-1]

    folder = title
    fname = '{}/solution.{}'.format(folder, TYPE)
    if not exists(folder):
        mkdir(folder)
    if exists(fname):
        print(fname, 'exist')
        return

    f = open(fname, "w")
    f.write(TEMPLATES[TYPE] % info)
    f.close()
    print(fname, "saved")

def save_all(lst):
    # list(map(save, lst))
    p = Pool()
    p.map(save, lst)


def get_problemset():
    d = PQ(get(PROBLEMSET_URL).content)
    table = d('#problemList > tbody > tr')
    ps = []
    for tr in table.items():
        p = tr('td > a').attr['href']
        p = MATCH_NAME.sub(r'\1', p)
        ps.append(p)
    ps.reverse()
    return ps


if __name__ == '__main__':
    ps = get_problemset()
    save_all(ps)

