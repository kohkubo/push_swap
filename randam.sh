# make re
gen_permutation() {
  echo -e "from itertools import permutations\nfor i in permutations(list(range(0, $1))):\n  print(*i)" | python3
}

gen_permutation $1 > permutation.txt

while read line; do
  count=$(./push_swap ${line} | wc -l | tr -d ' ')
  checker_result=$(./push_swap ${line} | ./checker ${line})
  printf "${line}: count: ${count} checker: ${checker_result}\n"
done < permutation.txt
