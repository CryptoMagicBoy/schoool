cd cat

./a.out -e *.txt >> ../s21_cat_log.txt

./a.out -benstv *.txt >> ../s21_cat_log.txt

./a.out -bn *.txt >> ../s21_cat_log.txt

./a.out --number-nonblank *.txt >> ../s21_cat_log.txt

./a.out -nnnnnn -ssssss -ttttt test.txt >> ../s21_cat_log.txt

cat -e *.txt >> ../cat_log.txt

cat -benstv *.txt >> ../cat_log.txt

cat -bn *.txt >> ../cat_log.txt

cat -b *.txt >> ../cat_log.txt

cat -nnnnnn -ssssss -ttttt test.txt >> ../cat_log.txt

cd ../grep

./a.out -e qw *.txt >> ../s21_grep_log.txt
grep -e qw *.txt >> ../grep_log.txt

./a.out -e qw *.txt >> ../s21_grep_log.txt
grep -e qw *.txt >> ../grep_log.txt

./a.out -e qw *.txt >> ../s21_grep_log.txt
grep -e qw *.txt >> ../grep_log.txt

./a.out -e qw test.txt -v >> ../s21_grep_log.txt
grep -e qw test.txt -v >> ../grep_log.txt

./a.out -e qw test.txt -c >> ../s21_grep_log.txt
grep -e qw test.txt -c >> ../grep_log.txt

./a.out -e qw *.txt -l >> ../s21_grep_log.txt
grep -e qw *.txt -l >> ../grep_log.txt

./a.out -e [a-z] test.txt -n >> ../s21_grep_log.txt
grep -e [a-z] test.txt -n >> ../grep_log.txt

./a.out -he a test.txt >> ../s21_grep_log.txt
grep -he a test.txt >> ../grep_log.txt

./a.out -se a test.txt >> ../s21_grep_log.txt
grep -se a test.txt >> ../grep_log.txt

./a.out -f test.txt test.txt >> ../s21_grep_log.txt
grep -f test.txt test.txt >> ../grep_log.txt

./a.out -ove a *.txt >> ../s21_grep_log.txt
grep -ove a *.txt >> ../grep_log.txt
