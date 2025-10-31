#!/usr/bin/env python3
import re
import sys

# Usage: checker.py expected_patterns.txt output.txt
# expected_patterns.txt contains one regex per line (blank lines and lines
# starting with # are ignored). The checker verifies that each pattern appears
# in the program output in the given order. ANSI escape sequences are stripped
# before matching.

ANSI_RE = re.compile(r"\x1B\[[0-9;]*[A-Za-z]")


def load_patterns(path):
    pats = []
    with open(path, 'r', encoding='utf-8') as f:
        for ln in f:
            ln = ln.strip()
            if not ln or ln.startswith('#'):
                continue
            pats.append(ln)
    return pats


def strip_ansi(s):
    return ANSI_RE.sub('', s)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print('Usage: checker.py expected.txt output.txt')
        sys.exit(2)
    expected_file = sys.argv[1]
    output_file = sys.argv[2]

    patterns = load_patterns(expected_file)
    with open(output_file, 'r', encoding='utf-8', errors='ignore') as f:
        out = f.read()
    out = strip_ansi(out)

    pos = 0
    for i, pat in enumerate(patterns):
        m = re.search(pat, out[pos:], re.MULTILINE)
        if not m:
            print(f"Pattern {i+1} not found: {pat}")
            sys.exit(1)
        # advance last matched end
        pos += m.end()
    print('All patterns matched')
    sys.exit(0)
