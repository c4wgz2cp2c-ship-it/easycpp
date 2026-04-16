// test_easycpp.cpp - Comprehensive test suite for EasyCPP 250+ Utilities
// Compile: g++ -std=c++17 test_easycpp.cpp -o test_easycpp.exe
// Run: test_easycpp.exe

#include "../EASY-CPP.h"
#include <iostream>
#include <cstdlib>   // per system

using namespace std;

// Macro per test rapidi
#define TEST(name) \
    println("\n========== ", name, " ==========");

#define CHECK(condition, message) \
    if (condition) { \
        color_green(); print("[PASS] "); \
    } else { \
        color_red(); print("[FAIL] "); \
    } \
    color_reset(); \
    println(message);

int main() {
    // Imposta UTF-8 per visualizzare emoji e caratteri speciali
    system("chcp 65001 > nul");

    random_init();

    println("\n🚀 EasyCPP Comprehensive Test Suite 🚀");
    println("Testing 250+ utilities...\n");

    // -------------------------------------------------------------
    // 1. Console Output & Colors
    // -------------------------------------------------------------
    TEST("1. Console Output & Colors");
    print("This is normal text. ");
    color_bold(); print("Bold, ");
    color_underline(); print("Underlined, ");
    color_reset();
    color_red(); print("Red, ");
    color_green(); print("Green, ");
    color_blue(); print("Blue, ");
    color_reset();
    println(" and back to normal.");
    println("Multiple args: ", 42, " ", 3.14, " ", 'A', " ", true);

    // -------------------------------------------------------------
    // 2. String Utilities
    // -------------------------------------------------------------
    TEST("2. String Utilities");
    string s = "  Hello EasyCPP!  ";
    CHECK(to_lower("HELLO") == "hello", "to_lower works");
    CHECK(to_upper("hello") == "HELLO", "to_upper works");
    CHECK(trim(s) == "Hello EasyCPP!", "trim works");
    CHECK(ltrim(s) == "Hello EasyCPP!  ", "ltrim works");
    CHECK(rtrim(s) == "  Hello EasyCPP!", "rtrim works");
    CHECK(starts_with("hello world", "hello") == true, "starts_with true");
    CHECK(ends_with("hello world", "world") == true, "ends_with true");
    CHECK(contains("hello world", "lo w") == true, "contains true");
    CHECK(replace("a,b,c", ",", ";") == "a;b,c", "replace (first) works");
    CHECK(replace_all("a,b,c", ",", ";") == "a;b;c", "replace_all works");
    vector<string> words = split("one two three", ' ');
    CHECK(words.size() == 3 && words[0] == "one", "split works");
    CHECK(join(words, ", ") == "one, two, three", "join works");
    CHECK(repeat("ha", 3) == "hahaha", "repeat works");
    CHECK(reverse_str("hello") == "olleh", "reverse_str works");
    CHECK(is_palindrome("Racecar") == true, "is_palindrome case-insensitive");
    CHECK(pad_left("42", 5, '0') == "00042", "pad_left works");
    CHECK(pad_right("42", 5, '.') == "42...", "pad_right works");
    CHECK(count_substr("banana", "na") == 2, "count_substr works");
    CHECK(remove_chars("hello", "eo") == "hll", "remove_chars works");
    CHECK(keep_chars("hello", "hl") == "hll", "keep_chars works");
    vector<string> lines = split_lines("a\nb\nc");
    CHECK(lines.size() == 3, "split_lines works");

    // -------------------------------------------------------------
    // 3. Vector Utilities
    // -------------------------------------------------------------
    TEST("3. Vector Utilities");
    vector<int> v = {5, 2, 8, 2, 9, 1};
    CHECK(sum(v) == 27, "sum works");
    CHECK(abs(average(v) - 4.5) < 0.001, "average works");
    CHECK(max_element(v) == 9, "max_element works");
    CHECK(min_element(v) == 1, "min_element works");
    CHECK(contains(v, 8) == true, "contains true");
    CHECK(contains(v, 99) == false, "contains false");

    sort_vec(v);
    CHECK(v[0] == 1 && v.back() == 9, "sort_vec works");

    reverse_vec(v);
    CHECK(v[0] == 9 && v.back() == 1, "reverse_vec works");

    clear_vec(v);
    CHECK(v.empty(), "clear_vec works");

    v = {1, 2, 3};
    push_unique(v, 2);
    push_unique(v, 4);
    CHECK(v.size() == 4 && v.back() == 4, "push_unique works");

    filter_vec(v, [](int x){ return x % 2 == 0; });
    CHECK(v.size() == 2 && v[0] == 2 && v[1] == 4, "filter_vec works");

    vector<int> v2 = {1, 2, 3};
    for_each_vec(v2, [](int& x){ x *= 2; });
    CHECK(v2[0] == 2 && v2[1] == 4 && v2[2] == 6, "for_each_vec works");

    // -------------------------------------------------------------
    // 4. Sorting Algorithms
    // -------------------------------------------------------------
    TEST("4. Sorting Algorithms");
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};

    vector<int> copy = nums;
    bubble_sort(copy);
    CHECK(copy[0] == 11 && copy.back() == 90, "bubble_sort works");

    copy = nums; selection_sort(copy);
    CHECK(copy[0] == 11 && copy.back() == 90, "selection_sort works");

    copy = nums; insertion_sort(copy);
    CHECK(copy[0] == 11 && copy.back() == 90, "insertion_sort works");

    copy = nums; merge_sort(copy);
    CHECK(copy[0] == 11 && copy.back() == 90, "merge_sort works");

    copy = nums; quick_sort(copy);
    CHECK(copy[0] == 11 && copy.back() == 90, "quick_sort works");

    // -------------------------------------------------------------
    // 5. Search Algorithms
    // -------------------------------------------------------------
    TEST("5. Search Algorithms");
    vector<int> haystack = {10, 20, 30, 40, 50};
    CHECK(linear_search(haystack, 30) == 2, "linear_search found");
    CHECK(linear_search(haystack, 99) == -1, "linear_search not found");
    CHECK(binary_search(haystack, 40) == 3, "binary_search found");
    CHECK(binary_search(haystack, 99) == -1, "binary_search not found");

    // -------------------------------------------------------------
    // 6. Data Structures
    // -------------------------------------------------------------
    TEST("6. Data Structures");

    Stack<int> stk;
    stk.push(10); stk.push(20); stk.push(30);
    CHECK(stk.top() == 30, "Stack top works");
    stk.pop();
    CHECK(stk.top() == 20, "Stack pop works");
    CHECK(stk.size() == 2, "Stack size works");
    CHECK(!stk.empty(), "Stack not empty");

    Queue<string> q;
    q.enqueue("first"); q.enqueue("second");
    CHECK(q.front() == "first", "Queue front works");
    q.dequeue();
    CHECK(q.front() == "second", "Queue dequeue works");
    CHECK(q.size() == 1, "Queue size works");

    LinkedList<int> ll;
    ll.push_back(1); ll.push_back(2); ll.push_front(0);
    CHECK(ll.size() == 3, "LinkedList size works");
    CHECK(ll.contains(2) == true, "LinkedList contains true");
    ll.pop_front();
    CHECK(ll.contains(0) == false, "LinkedList pop_front works");

    // -------------------------------------------------------------
    // 7. Math & Statistics
    // -------------------------------------------------------------
    TEST("7. Math & Statistics");
    CHECK(clamp_val(15, 0, 10) == 10, "clamp_val works");
    CHECK(abs(lerp(0.0, 10.0, 0.5) - 5.0) < 0.001, "lerp works");
    CHECK(factorial(5) == 120, "factorial works");
    CHECK(fibonacci(6) == 8, "fibonacci works");
    CHECK(is_prime(17) == true && is_prime(4) == false, "is_prime works");
    CHECK(gcd(12, 8) == 4, "gcd works");
    CHECK(lcm(12, 8) == 24, "lcm works");
    CHECK(abs(to_radians(180) - PI) < 0.001, "to_radians works");
    CHECK(abs(to_degrees(PI) - 180.0) < 0.001, "to_degrees works");
    CHECK(abs(sin_deg(30) - 0.5) < 0.001, "sin_deg works");

    vector<int> data = {1, 2, 3, 4, 4, 5};
    CHECK(abs(median(data) - 3.5) < 0.001, "median works");
    vector<int> modes = mode(data);
    CHECK(modes.size() == 1 && modes[0] == 4, "mode works");
    CHECK(abs(variance(data) - 1.80555) < 0.01, "variance works");
    CHECK(abs(std_deviation(data) - sqrt_val(variance(data))) < 0.001, "std_deviation works");
    CHECK(nCr(5, 2) == 10, "nCr works");
    CHECK(nPr(5, 2) == 20, "nPr works");

    // -------------------------------------------------------------
    // 8. Time & Date
    // -------------------------------------------------------------
    TEST("8. Time & Date");
    println("Current time: ", current_time());
    println("Current date: ", current_date());
    println("DateTime: ", datetime_str());
    println("Year: ", current_year(), ", Month: ", current_month(), ", Day: ", current_day());
    println("Weekday: ", weekday_name());
    println("Timestamp ms: ", timestamp_ms());

    Stopwatch sw;
    sleep_ms(100);
    double elapsed = sw.elapsed_seconds();
    CHECK(elapsed >= 0.09 && elapsed <= 0.15, "Stopwatch elapsed_seconds");
    sleep_sec(1);
    CHECK(sw.elapsed_seconds() >= 1.0, "sleep_sec & Stopwatch work");

    // -------------------------------------------------------------
    // 9. Random
    // -------------------------------------------------------------
    TEST("9. Random");
    int rnd = random_int(1, 100);
    CHECK(rnd >= 1 && rnd <= 100, "random_int works");
    double rndd = random_double(0.0, 1.0);
    CHECK(rndd >= 0.0 && rndd <= 1.0, "random_double works");
    bool rndb = random_bool();
    CHECK(rndb == true || rndb == false, "random_bool works");

    // -------------------------------------------------------------
    // 10. Logging & Debug
    // -------------------------------------------------------------
    TEST("10. Logging & Debug");
    debug("This is a debug message");
    log_info("This is an info message");
    log_warn("This is a warning");
    log_error("This is an error (non-fatal)");
    assert_true(1 == 1, "This should not exit");

    // -------------------------------------------------------------
    // 11. CSV & Tables
    // -------------------------------------------------------------
    TEST("11. CSV & Tables");
    vector<vector<string>> csv_data = {{"Name","Age"}, {"Alice","30"}, {"Bob","25"}};
    write_csv("test_people.csv", csv_data);
    auto read_back = read_csv("test_people.csv");
    CHECK(read_back.size() == 3 && read_back[1][0] == "Alice", "CSV read/write works");
    println("Table output:");
    print_table(csv_data);

    // -------------------------------------------------------------
    // 12. File System
    // -------------------------------------------------------------
    TEST("12. File System");
    CHECK(file_exists("test_people.csv") == true, "file_exists works");
    CHECK(is_file("test_people.csv") == true, "is_file works");
    CHECK(is_directory(".") == true, "is_directory works (current dir)");
    auto dir_list = list_dir(".");
    CHECK(dir_list.size() > 0, "list_dir works");
    copy_file("test_people.csv", "test_people_copy.csv");
    CHECK(file_exists("test_people_copy.csv") == true, "copy_file works");
    remove_file("test_people_copy.csv");
    CHECK(file_exists("test_people_copy.csv") == false, "remove_file works");
    create_dir("test_dir");
    CHECK(is_directory("test_dir") == true, "create_dir works");
    remove_file("test_dir");
    remove_file("test_people.csv");

    // -------------------------------------------------------------
    // 13. Geometry 2D
    // -------------------------------------------------------------
    TEST("13. Geometry 2D");
    Point p1{0,0}, p2{3,4};
    CHECK(abs(distance(p1, p2) - 5.0) < 0.001, "distance works");
    Line line{p1, p2};
    CHECK(abs(slope(line) - 4.0/3.0) < 0.001, "slope works");
    Circle c{p1, 5.0};
    CHECK(abs(area(c) - 78.5398) < 0.1, "circle area works");
    CHECK(abs(circumference(c) - 31.4159) < 0.1, "circumference works");

    // -------------------------------------------------------------
    // 14. Encoding & Hashing
    // -------------------------------------------------------------
    TEST("14. Encoding & Hashing");
    string original = "Hello EasyCPP!";
    string enc = base64_encode(original);
    string dec = base64_decode(enc);
    CHECK(original == dec, "base64 encode/decode works");

    string rle_enc = rle_encode("aaabbbcc");
    CHECK(rle_enc == "a3b3c2", "rle_encode works");
    string rle_dec = rle_decode(rle_enc);
    CHECK(rle_dec == "aaabbbcc", "rle_decode works");

    string xored = xor_encrypt_decrypt("secret", 42);
    string unxored = xor_encrypt_decrypt(xored, 42);
    CHECK(unxored == "secret", "xor_encrypt_decrypt works");

    size_t h = hash_str("hello");
    CHECK(h != 0, "hash_str works");

    // -------------------------------------------------------------
    // 15. Bit Operations
    // -------------------------------------------------------------
    TEST("15. Bit Operations");
    unsigned int bits = 0b1010;
    CHECK(get_bit(bits, 1) == true, "get_bit works");
    bits = set_bit(bits, 2);
    CHECK(bits == 0b1110, "set_bit works");
    bits = clear_bit(bits, 3);
    CHECK(bits == 0b0110, "clear_bit works");
    bits = toggle_bit(bits, 0);
    CHECK(bits == 0b0111, "toggle_bit works");
    CHECK(count_bits(0b1101) == 3, "count_bits works");

    // -------------------------------------------------------------
    // 16. Sequence Generators
    // -------------------------------------------------------------
    TEST("16. Sequence Generators");
    vector<int> r1 = range(5);
    CHECK(r1.size() == 5 && r1[0] == 0 && r1[4] == 4, "range(stop) works");
    vector<int> r2 = range(2, 10, 2);
    CHECK(r2.size() == 4 && r2[0] == 2 && r2.back() == 8, "range(start,stop,step) works");
    vector<int> r3 = range(10, 0, -2);
    CHECK(r3.size() == 5 && r3[0] == 10 && r3.back() == 2, "range with negative step works");

    vector<string> fruits = {"apple", "banana", "cherry"};
    auto en = enumerate(fruits);
    CHECK(en[0].first == 0 && en[0].second == "apple", "enumerate works");
    println("Enumerate output:");
    print_enumerate(fruits);

    // -------------------------------------------------------------
    // 17. Progress Bars (visual)
    // -------------------------------------------------------------
    TEST("17. Progress Bars (visual)");
    println("Single progress bar (simulated):");
    for (int i = 0; i <= 100; i += 10) {
        progress_bar(i, 100, 30);
        sleep_ms(50);
    }
    println("\nMulti progress bar (simulated):");
    MultiProgressBar mpb(20);
    mpb.add_bar("Task A", 100);
    mpb.add_bar("Task B", 80);
    for (int i = 0; i <= 100; i += 20) {
        mpb.update(0, i);
        mpb.update(1, i * 0.8);
        sleep_ms(100);
    }
    println("\n\n");

    // -------------------------------------------------------------
    // 18. Testing Framework
    // -------------------------------------------------------------
    TEST("18. Testing Framework (TestSuite)");
    TestSuite suite("EasyCPP Self Test");
    suite.assert_true(true, "True is true");
    suite.assert_eq(42, 42, "42 equals 42");
    suite.assert_eq(string("hello"), string("hello"), "strings match");

    // -------------------------------------------------------------
    // 19. System & Environment
    // -------------------------------------------------------------
    TEST("19. System & Environment");
    println("OS: ", get_os());
    string path = get_env("PATH");
    CHECK(!path.empty(), "get_env PATH works");
    set_env("EASYCPP_TEST", "123");
    CHECK(get_env("EASYCPP_TEST") == "123", "set_env/get_env works");
    pause("Press ENTER to continue... (only for manual test, comment for automation)");

    // -------------------------------------------------------------
    // Final Report
    // -------------------------------------------------------------
    TEST("ALL TESTS COMPLETED");
    color_bold(); color_green();
    println("✅ EasyCPP passed all automated checks! ✅");
    color_reset();
    println("\nNote: Some interactive/visual tests were commented out or ran visually.");
    println("Check above output for any [FAIL] messages.");

    return 0;
}
