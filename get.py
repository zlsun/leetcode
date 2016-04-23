#!/bin/python

import re
from os import makedirs
from os.path import exists
from argparse import ArgumentParser
from multiprocessing import Pool

from requests import get
from bs4 import BeautifulSoup as BS

import requests.packages.urllib3 as urllib3
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

%s

int main() {
    Solution s;
    return 0;
}
''',
    'python': '''\
#-*- encoding: utf-8 -*-
""" \
%s
"""

import sys, os
sys.path.append(os.path.abspath('..'))
from utils import *

%s

if __name__ == "__main__":
    s = Solution()

#
''',
}

PARALLEL = False
LANGUAGE = 'cpp'


def save(name):
    print('[Processing] {}'.format(name))

    content = get(PROBLEM_URL.format(name), verify=False).content
    soup = BS(content, 'html.parser')
    title = soup.find(class_='question-title')
    if not title:
        print('Cannot open {}'.format(name))
        return

    title = title.h3.string
    title = '0' * (3 - title.find('.')) + title
    content = soup.find('meta', {'name': 'description'}).attrs['content']
    info = '{}\n{}'.format(title, content)

    init = soup.find('div', {'ng-controller': 'AceCtrl as aceCtrl'}) \
               .attrs['ng-init']
    init = init.replace('aceCtrl.init', '')
    init = init.replace('\n', '').replace('\r', '')[:-1]
    solus = eval(init, {'true': True, 'false': False})[0]
    solus = {i['value']: i['defaultCode'] for i in solus}

    text = TEMPLATES[LANGUAGE] % (info, solus[LANGUAGE])
    text = text.replace('\u000d', '')
    text = re.sub(r'[\n]{3,}', r'\n\n', text)

    folder = '{}'.format(title)
    fname = '{}/solution.{}'.format(folder, LANGUAGE)
    if not exists(folder):
        makedirs(folder)
    if exists(fname):
        print('{} exist'.format(fname))
        return
    with open(fname, 'w') as f:
        f.write(text)
    print('{} saved'.format(fname))


def save_all(problemset):
    if PARALLEL:
        pool = Pool()
        pool.map(save, problemset)
    else:
        list(map(save, problemset))


def get_problemset():
    content = get(PROBLEMSET_URL, verify=False).content
    soup = BS(content, 'html.parser')
    table = soup.select('#problemList > tbody > tr')
    for tr in table:
        p = tr.select('td > a')[0].attrs['href']
        p = MATCH_NAME.sub(r'\1', p)
        yield p


if __name__ == '__main__':
    parser = ArgumentParser(description='LeetCode downloader')
    parser.add_argument('-p', dest='parallel', action='store_true',
                        help='Download parallelly')
    parser.add_argument('language', nargs='?', default='cpp',
                        help='Language')
    args = parser.parse_args()
    PARALLEL = args.parallel
    LANGUAGE = args.language

    problemset = get_problemset()
    save_all(problemset)
