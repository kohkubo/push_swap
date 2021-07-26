make

test_all() {
  while read line; do
    result=$(./push_swap ${line} 2>&1)
    if [ "${result}" != "Error" ]; then
      echo "${line}" > error_case.txt
      printf "\e[31m%s\n\e[m" "${line}"
    fi
    # printf "\e[32m%s\n\e[m" "${line}: count: ${count} checker: ${checker_result}"
  done < error_testcase.txt
}

rm -rf error_case.txt res

test_all
