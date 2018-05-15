#! /bin/sh

rm log_*.txt

# Test 1: log file access should give permission error
echo "Running Test 1: ..."
./logger_test -f /log_file.txt -d 2

# Test 2: Log level should be between 0 and 2. 
echo "Running Test 2: ..."
./logger_test -f log_file.txt -d -2

# Test 3: Only Error messages should be printed. 
echo "Running Test 3: ..."
./logger_test -f log_file_test3.txt -d 0

# Test 4: Only Error and Info  messages should be printed. 
echo "Running Test 4: ..."
./logger_test -f log_file_test4.txt -d 1

# Test 5: Error, Info and Debug  messages should be printed. 
echo "Running Test 5: ..."
./logger_test -f log_file_test5.txt -d 2
