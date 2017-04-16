#!/usr/bin/env python

import json
from jinja2 import Template


def main(data, template, output_file):
    open(output_file, 'w').write(Template(open(template).read()).render(json.load(open(data))))


if __name__ == '__main__':
    main('data.json', 'Protocol.cpp.template', '../CloudyBackpack/Protocol.h')
