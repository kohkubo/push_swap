set -eu
make re

gen_permutation() {
  echo -e "import random\nfor num in range($2):\n
    print(*random.sample(list(range(0, $1)), $1))" | python3
}

test_all() {
  while read line; do
    count=$(./push_swap ${line} | wc -l | tr -d ' ')
    checker_result=$(./push_swap ${line} | ./checker ${line})
    if [ ${checker_result} == "KO" ]; then
      echo "${line}" >> error_case.txt
    fi
    printf "${line}: count: ${count} checker: ${checker_result}\n"
  done < permutation.txt
}

rm -rf error_case.txt res permutation.txt

for ((i=0; i < 100; i++)); do
  gen_permutation $i 1 >> permutation.txt
done

# # for ((i=0; i < 10; i++)); do
#   gen_permutation $1 10 >> permutation.txt
# # done

test_all