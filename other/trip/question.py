#!/usr/bin/env python3
import argparse
import csv
import random
import sys

import names


def get_args():
    parser = argparse.ArgumentParser()

    parser.add_argument('-d',
                        '--day',
                        nargs=1,
                        type=int,
                        required=True,
                        help='day')

    parser.add_argument('-p',
                        '--people',
                        nargs=1,
                        type=int,
                        required=True,
                        help='people')

    parser.add_argument('-t',
                        '--table',
                        nargs=1,
                        type=int,
                        required=True,
                        help='table')

    parser.add_argument('output',
                        nargs=1,
                        type=str,
                        help='output')

    return parser.parse_args()


def generate_non_leader_tables(num, table):
    small_table_size = num // table
    big_table_size = small_table_size + 1

    big_table_count = num % table

    ret = []

    for i in range(1, big_table_count + 1):
        ret.extend([i for _ in range(big_table_size)])

    for i in range(big_table_count + 1, table + 1):
        ret.extend([i for _ in range(small_table_size)])

    random.shuffle(ret)

    return ret


def generate_people(num):
    name_list = set()

    while len(name_list) < num:
        name_list.add(names.get_full_name())

    return [{'name': name} for name in name_list]


def main():
    args = get_args()

    day = args.day[0]
    people = args.people[0]
    table = args.table[0]
    output = args.output[0]

    all_people = generate_people(people)

    leaders = all_people[:table]
    non_leaders = all_people[table:]

    days = ['day {}'.format(i + 1) for i in range(day)]

    for d in days:
        leader_tables = [i for i in range(1, table + 1)]
        random.shuffle(leader_tables)

        for i in range(len(leaders)):
            leaders[i][d] = leader_tables[i]

        non_leader_tables = generate_non_leader_tables(len(non_leaders), table)

        for i in range(len(non_leaders)):
            non_leaders[i][d] = non_leader_tables[i]

    all_people = leaders + non_leaders
    random.shuffle(all_people)

    with open(output, 'wt') as f:
        writer = csv.DictWriter(f, fieldnames=['name'] + days)
        writer.writeheader()
        writer.writerows(all_people)

    print('leaders are: {}'.format(list(map(lambda x: x['name'], leaders))))


if __name__ == '__main__':
    sys.exit(main())
