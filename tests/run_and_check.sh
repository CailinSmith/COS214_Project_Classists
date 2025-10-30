#!/usr/bin/env bash
set -euo pipefail
case=${1:-case2}
root=$(dirname "$0")/..
cd "$root"

echo "Building project..."
make -j2

input="$root/tests/inputs/$case.txt"
output="$root/tests/outputs/$case.out"
expected="$root/tests/expected/$case.txt"

if [ ! -f "$input" ]; then
  echo "Input file $input not found" >&2
  exit 2
fi
if [ ! -f "$expected" ]; then
  echo "Expected file $expected not found" >&2
  exit 2
fi

exe="$root/build/main"
if [ ! -x "$exe" ]; then
  echo "Executable $exe not found or not executable" >&2
  exit 3
fi

# run the program with the provided input and capture output
cat "$input" | "$exe" > "$output"

python3 "$root/tests/checker.py" "$expected" "$output"
rc=$?
if [ $rc -eq 0 ]; then
  echo "TEST PASSED"
else
  echo "TEST FAILED"
fi
exit $rc
