echo "clang++ -Wall -Wextra -Werror -std=c++98 Account.class.cpp tests.cpp"
clang++ -Wall -Wextra -Werror -std=c++98 Account.class.cpp tests.cpp
echo "./a.out > my.log"
./a.out > my.log
echo "diff my.log 19920104_091532.log > diff.txt"
diff my.log 19920104_091532.log > diff.txt
echo "cat diff.txt"
cat diff.txt
