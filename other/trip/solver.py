#!/usr/bin/env python3
import argparse
import collections
import csv
import sys


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
                        help='people')

    parser.add_argument('-t',
                        '--table',
                        nargs=1,
                        type=int,
                        required=True,
                        help='table')

    parser.add_argument('input',
                        nargs=1,
                        type=str,
                        help='input')

    return parser.parse_args()


def solve(table_to_person, person_to_table, table_names, leaders, not_leaders):
    idx = len(leaders)

    if idx == len(table_names):
        print('find one solution: {}'.format(leaders))
        return

    for new_leader in table_to_person[table_names[idx]]:
        if new_leader in not_leaders:
            continue

        new_leaders = leaders.union([new_leader])
        new_not_leaders = not_leaders

        for t in person_to_table[new_leader]:
            new_not_leaders = new_not_leaders.union(table_to_person[t])

        solve(
            table_to_person,
            person_to_table,
            table_names,
            new_leaders,
            new_not_leaders)


def main():
    args = get_args()

    day = args.day[0]
    table = args.table[0]
    input_ = args.input[0]

    table_to_person = collections.defaultdict(set)
    person_to_table = collections.defaultdict(set)

    days = ['day {}'.format(i + 1) for i in range(day)]

    with open(input_) as f:
        reader = csv.DictReader(f)

        for row in reader:
            for d in days:
                person_name = row['name']
                table_name = '{}-{}'.format(d, row[d])

                table_to_person[table_name].add(person_name)
                person_to_table[person_name].add(table_name)

    solve(
        table_to_person,
        person_to_table,
        ['day 1-{}'.format(i) for i in range(1, table + 1)],
        frozenset(),
        frozenset()
    )


if __name__ == '__main__':
    sys.exit(main())
