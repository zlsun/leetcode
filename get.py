#!/bin/python

import re
from os import makedirs
from os.path import exists
from multiprocessing import Pool
from requests import get
from bs4 import BeautifulSoup as BS
import argparse

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
    print('Processing {}'.format(name))
    soup = BS(
        get(PROBLEM_URL.format(name), verify=False).content, 'html.parser')
    title = soup.find(class_='question-title')
    if not title:
        print('Cannot open {}'.format(name))
        return
    title = title.h3.string
    title = '0' * (3 - title.find('.')) + title
    content = soup.find('meta', {'name': 'description'}).attrs['content']
    info = title + '\n' + content

    ng_init = soup.find(
        'div', {'ng-controller': 'AceCtrl as aceCtrl'}).attrs['ng-init']
    true, false = True, False
    init = ng_init.replace('aceCtrl.init', '').replace(
        '\n', '').replace('\r', '')[:-1]
    solus = eval(init)[0]
    solus = {i['value']: i['defaultCode'] for i in solus}

    text = TEMPLATES[LANGUAGE] % (info, solus[LANGUAGE])
    text = text.replace('\u000d', '')
    text = re.sub(r'[\n]{3,}', r'\n\n', text)

    folder = '{}'.format(title)
    fname = '{}/solution.{}'.format(folder, LANGUAGE)
    if not exists(folder):
        makedirs(folder)
    if exists(fname):
        print(fname, 'exist')
        return

    f = open(fname, "w")
    f.write(text)
    f.close()
    print(fname, "saved")


def save_all(lst):
    if PARALLEL:
        p = Pool()
        p.map(save, lst)
    else:
        list(map(save, lst))


def get_problemset():
    soup = BS(get(PROBLEMSET_URL, verify=False).content, 'html.parser')
    table = soup.select('#problemList > tbody > tr')
    ps = []
    for tr in table:
        p = tr.select('td > a')[0].attrs['href']
        p = MATCH_NAME.sub(r'\1', p)
        ps.append(p)
    return ps


if __name__ == '__main__':
    import sys
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('-p', dest='parallel', action='store_true',
                        help='Download parallelly')
    parser.add_argument('language', nargs='?', default='cpp',
                        help='Language')
    args = parser.parse_args()
    PARALLEL = args.parallel
    LANGUAGE = args.language

    ps = get_problemset()
    save_all(ps)
