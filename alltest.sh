# make re
gen_permutation() {
  echo -e "from itertools import permutations\nfor i in permutations(list(range(0, $1))):\n  print(*i)" | python3
}

test_all() {
  while read line; do
    count=$(./push_swap ${line} | wc -l | tr -d ' ')
    checker_result=$(./push_swap ${line} | ./checker ${line})
    if [ ${checker_result} == "KO" ]; then
      echo "${line}" >> error_case.txt
    fi
    # printf "${line}: count: ${count} checker: ${checker_result}\n"
  done < permutation.txt
}

rm -rf error_case.txt res

gen_permutation 1 > permutation.txt
test_all

gen_permutation 2 > permutation.txt
test_all

gen_permutation 3 > permutation.txt
test_all

gen_permutation 4 > permutation.txt
test_all

gen_permutation 5 > permutation.txt
test_all

gen_permutation 6 > permutation.txt
test_all
