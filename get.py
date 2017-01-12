#!/usr/bin/env python

import re
from os import makedirs
from os.path import exists
from argparse import ArgumentParser
from multiprocessing import Pool

import requests
from bs4 import BeautifulSoup as BS

try:
    from requests.packages.urllib3.exceptions import InsecureRequestWarning
    requests.packages.urllib3.disable_warnings(InsecureRequestWarning)
except ImportError:
    pass

PROBLEMS_API = 'https://leetcode.com/api/problems/{}/'
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

''',
}

PARALLEL = False
LANGUAGE = 'cpp'

def colorize(str, a, b):
    return '\033[{};{}m{}\033[0;0m'.format(a, b, str)

strong = lambda str: colorize(str, 1, 31)
error = lambda str: colorize(str, 0, 31)
warning = lambda str: colorize(str, 0, 33)
success = lambda str: colorize(str, 0, 32)

def save(name):
    print(strong('[Processing] ') + name)

    content = requests.get(PROBLEM_URL.format(name), verify=False).content
    soup = BS(content, 'html.parser')
    title = soup.find(class_='question-title')
    if not title:
        print(error('Denied: ') + name)
        return

    title = title.h3.string.strip()
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
        print(warning('Existed: ') + fname)
        return
    with open(fname, 'w') as f:
        f.write(text)
    print(success('Saved: ') + fname)


def save_all(problemset):
    if PARALLEL:
        pool = Pool()
        pool.map(save, problemset)
    else:
        list(map(save, problemset))


def get_problems(type):
    response = requests.get(PROBLEMS_API.format(type), verify=False).json()
    problems = response['stat_status_pairs']
    for pair in problems:
        slug = pair['stat']['question__title_slug']
        yield slug


if __name__ == '__main__':
    parser = ArgumentParser(description='LeetCode downloader')
    parser.add_argument('-p', dest='parallel', action='store_true',
                        help='Download parallelly')
    parser.add_argument('language', nargs='?', default='cpp',
                        help='Language')
    args = parser.parse_args()
    PARALLEL = args.parallel
    LANGUAGE = args.language

    try:
        problems = get_problems('algorithms')
        save_all(problems)
    except KeyboardInterrupt:
        pass

