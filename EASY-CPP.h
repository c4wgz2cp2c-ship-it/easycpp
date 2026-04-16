#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <random>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string_view>
#include <optional>
#include <filesystem>
#include <functional>
#include <cctype>
#include <climits>

using namespace std;

// =============================================
//                  EASYCPP
//  The Ultimate C++ Utility Library
//  Python-like • Maximum Performance • 250+ functions
// =============================================

// ====================== TO_LOWER ======================
[[nodiscard]] inline char to_lower(char c) noexcept { return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c; }
[[nodiscard]] string to_lower(string str);

// ====================== PRINT / PRINTLN ======================
template<typename... Args> void print(const Args&... args) noexcept { (cout << ... << args); }
template<typename... Args> void println(const Args&... args) noexcept { (cout << ... << args) << endl; }

void print(const string& s) noexcept;
void print(const char* s) noexcept;
void print(char c) noexcept;
void print(int n) noexcept;
void print(float n) noexcept;
void print(double n) noexcept;
void print(long int n) noexcept;
void print(bool b) noexcept;

// ====================== INPUT ======================
void input(string& s);
void input(int& n);
void input(float& n);
void input(double& n);
void input(char& c);
void input(long int& n);
void input(bool& b);

[[nodiscard]] string input_str(string prompt = "");
[[nodiscard]] int    input_int(string prompt = "");
[[nodiscard]] float  input_float(string prompt = "");
[[nodiscard]] double input_double(string prompt = "");
[[nodiscard]] bool   input_bool(string prompt = "");

// ====================== ARRAY & VECTOR ======================
template<typename T, size_t N> void print(T (&arr)[N]);
template<typename T> void print(const vector<T>& v);

template<typename T, size_t N> void input(T (&arr)[N]);
template<typename T> void input(vector<T>& v);

// ====================== FILE & PATH ======================
void write_file(string filename, string mode = "out");
void read_file(string filename);
void append_file(string filename, const string& content);
[[nodiscard]] string read_file_as_string(const string& filename);
void write_lines(const string& filename, const vector<string>& lines);
[[nodiscard]] vector<string> read_lines(const string& filename);

[[nodiscard]] string get_filename(string_view path);
[[nodiscard]] string get_extension(string_view path);
[[nodiscard]] string get_parent_path(string_view path);
[[nodiscard]] string get_stem(string_view path);

// --- NEW FILE SYSTEM UTILITIES ---
[[nodiscard]] bool file_exists(const string& path);
[[nodiscard]] bool is_directory(const string& path);
[[nodiscard]] bool is_file(const string& path);
[[nodiscard]] vector<string> list_dir(const string& path);
[[nodiscard]] size_t file_size(const string& path);
void create_dir(const string& path);
void remove_file(const string& path);
void copy_file(const string& from, const string& to);

// ====================== ENVIRONMENT ======================
[[nodiscard]] string get_env(const string& name);
void set_env(const string& name, const string& value);

// ====================== MATH ======================
template<typename T> [[nodiscard]] inline T min_val(T a, T b) noexcept { return a < b ? a : b; }
template<typename T> [[nodiscard]] inline T max_val(T a, T b) noexcept { return a > b ? a : b; }
template<typename T> [[nodiscard]] inline T clamp_val(T val, T minv, T maxv) noexcept { return max_val(minv, min_val(maxv, val)); }

[[nodiscard]] inline double pow_val(double base, double exp) noexcept { return pow(base, exp); }
[[nodiscard]] inline double sqrt_val(double x) noexcept { return sqrt(x); }
[[nodiscard]] inline double cbrt_val(double x) noexcept { return cbrt(x); }
[[nodiscard]] inline double lerp(double a, double b, double t) noexcept { return a + t * (b - a); }

[[nodiscard]] int factorial(int n);
[[nodiscard]] int fibonacci(int n);
[[nodiscard]] inline bool is_even(int n) noexcept { return n % 2 == 0; }
[[nodiscard]] inline bool is_odd(int n) noexcept { return !is_even(n); }

constexpr double PI = 3.141592653589793;
constexpr double E  = 2.718281828459045;
[[nodiscard]] inline double to_radians(double deg) noexcept { return deg * PI / 180.0; }
[[nodiscard]] inline double to_degrees(double rad) noexcept { return rad * 180.0 / PI; }

// --- NEW TRIGONOMETRY & STATS ---
[[nodiscard]] inline double sin_deg(double deg) noexcept;
[[nodiscard]] inline double cos_deg(double deg) noexcept;
[[nodiscard]] inline double tan_deg(double deg) noexcept;
[[nodiscard]] inline double log_base(double x, double base) noexcept;

template<typename T> [[nodiscard]] double median(vector<T> v);
template<typename T> [[nodiscard]] vector<T> mode(const vector<T>& v);
template<typename T> [[nodiscard]] double variance(const vector<T>& v);
template<typename T> [[nodiscard]] double std_deviation(const vector<T>& v);

[[nodiscard]] inline long long nCr(int n, int r) noexcept;
[[nodiscard]] inline long long nPr(int n, int r) noexcept;

// ====================== STRING ADVANCED ======================
[[nodiscard]] bool starts_with(string_view str, string_view prefix) noexcept;
[[nodiscard]] bool ends_with(string_view str, string_view suffix) noexcept;
[[nodiscard]] bool contains(string_view str, string_view substr) noexcept;

[[nodiscard]] string replace(string_view str, string_view from, string_view to);
[[nodiscard]] string replace_all(string_view str, string_view from, string_view to);

[[nodiscard]] string to_upper(string str);
[[nodiscard]] string capitalize(string str);
[[nodiscard]] string trim(string_view str);
[[nodiscard]] string ltrim(string_view str);
[[nodiscard]] string rtrim(string_view str);

[[nodiscard]] vector<string> split(string_view str, char delimiter = ' ');
[[nodiscard]] string join(const vector<string>& vec, string_view delimiter = " ");
[[nodiscard]] string repeat(string_view str, int times);

// --- NEW STRING FUNCTIONS ---
[[nodiscard]] string reverse_str(string str);
[[nodiscard]] bool is_palindrome(string_view str);
[[nodiscard]] string pad_left(string_view str, size_t len, char pad = ' ');
[[nodiscard]] string pad_right(string_view str, size_t len, char pad = ' ');
[[nodiscard]] int count_substr(string_view str, string_view sub);
[[nodiscard]] string remove_chars(string_view str, string_view chars_to_remove);
[[nodiscard]] string keep_chars(string_view str, string_view chars_to_keep);
[[nodiscard]] vector<string> split_lines(string_view str);

// ====================== VECTOR UTILS ======================
template<typename T> [[nodiscard]] T sum(const vector<T>& v);
template<typename T> [[nodiscard]] double average(const vector<T>& v);
template<typename T> [[nodiscard]] T max_element(const vector<T>& v);
template<typename T> [[nodiscard]] T min_element(const vector<T>& v);
template<typename T> [[nodiscard]] bool contains(const vector<T>& v, const T& value);

template<typename T> void sort_vec(vector<T>& v);
template<typename T> void reverse_vec(vector<T>& v);
template<typename T> void clear_vec(vector<T>& v);
template<typename T> void push_unique(vector<T>& v, const T& value);

template<typename T, typename Predicate>
void filter_vec(vector<T>& v, Predicate pred);

template<typename T, typename Function>
void for_each_vec(vector<T>& v, Function func);

// ====================== MAP UTILS ======================
template<typename K, typename V> [[nodiscard]] bool map_contains(const map<K,V>& m, const K& key) noexcept;
template<typename K, typename V> [[nodiscard]] bool map_contains(const unordered_map<K,V>& m, const K& key) noexcept;

template<typename K, typename V> void print_map(const map<K,V>& m);
template<typename K, typename V> void print_map(const unordered_map<K,V>& m);

// ====================== TIME & TIMER ======================
[[nodiscard]] string current_time();
[[nodiscard]] string current_date();
[[nodiscard]] long long timestamp_ms() noexcept;

inline void sleep_ms(int ms) noexcept { this_thread::sleep_for(chrono::milliseconds(ms)); }
inline void sleep_sec(int sec) noexcept { this_thread::sleep_for(chrono::seconds(sec)); }

// --- NEW DATE/TIME FUNCTIONS ---
[[nodiscard]] string datetime_str();
[[nodiscard]] int current_year();
[[nodiscard]] int current_month();
[[nodiscard]] int current_day();
[[nodiscard]] string weekday_name();

// Simple Stopwatch
class Stopwatch {
    chrono::time_point<chrono::steady_clock> start_time;
public:
    Stopwatch() { start(); }
    void start() { start_time = chrono::steady_clock::now(); }
    [[nodiscard]] double elapsed_seconds() const;
    [[nodiscard]] long long elapsed_ms() const;
};

// ====================== CONSOLE COLORS ======================
inline void color_reset() noexcept   { print("\033[0m"); }
inline void color_red() noexcept     { print("\033[31m"); }
inline void color_green() noexcept   { print("\033[32m"); }
inline void color_yellow() noexcept  { print("\033[33m"); }
inline void color_blue() noexcept    { print("\033[34m"); }
inline void color_magenta() noexcept { print("\033[35m"); }
inline void color_cyan() noexcept    { print("\033[36m"); }
inline void color_bold() noexcept    { print("\033[1m"); }
inline void color_underline() noexcept { print("\033[4m"); }

// ====================== DEBUG & LOG ======================
void debug(const string& msg) noexcept;
void log_info(const string& msg) noexcept;
void log_warn(const string& msg) noexcept;
void log_error(const string& msg) noexcept;
void assert_true(bool condition, const string& message = "Assertion failed");

// ====================== SYSTEM ======================
void clear() noexcept;
void pause(string message = "Press ENTER to continue...") noexcept;
void exit_program(int code = 0) noexcept;
[[nodiscard]] string get_os() noexcept;

// ====================== RANDOM ======================
void random_init() noexcept;
[[nodiscard]] int random_int(int min, int max) noexcept;
[[nodiscard]] double random_double(double min = 0.0, double max = 1.0) noexcept;
[[nodiscard]] bool random_bool() noexcept;

// ====================== POINTERS ======================
template<typename T> void print_ptr(const T* ptr) noexcept;
template<typename T> [[nodiscard]] inline bool is_null(const T* ptr) noexcept { return ptr == nullptr; }

// ====================== CONVERSIONS ======================
template<typename T> [[nodiscard]] string to_str(const T& value);
[[nodiscard]] int to_int(string_view str);
[[nodiscard]] double to_double(string_view str);
[[nodiscard]] bool to_bool(string_view str);

// ====================== ALGORITHMS ======================
template<typename T> inline void swap_val(T& a, T& b) noexcept { T temp = std::move(a); a = std::move(b); b = std::move(temp); }

[[nodiscard]] bool is_prime(int n) noexcept;
[[nodiscard]] int gcd(int a, int b) noexcept;
[[nodiscard]] int lcm(int a, int b) noexcept;

// ====================== BASE64 ======================
[[nodiscard]] string base64_encode(const string& data);
[[nodiscard]] string base64_decode(const string& encoded);

// ====================== PROGRESS BAR ======================
void progress_bar(int progress, int total = 100, int width = 50);

// ====================== SORTING ALGORITHMS (NEW) ======================
template<typename T> void bubble_sort(vector<T>& v) noexcept;
template<typename T> void selection_sort(vector<T>& v) noexcept;
template<typename T> void insertion_sort(vector<T>& v) noexcept;
template<typename T> void merge_sort(vector<T>& v) noexcept;
template<typename T> void quick_sort(vector<T>& v) noexcept;

// ====================== SEARCH ALGORITHMS (NEW) ======================
template<typename T> int linear_search(const vector<T>& v, const T& key) noexcept;
template<typename T> int binary_search(const vector<T>& v, const T& key) noexcept;

// ====================== DATA STRUCTURES (NEW) ======================
template<typename T> class Stack {
    vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }
    void pop() { if (!empty()) data.pop_back(); }
    T& top() { return data.back(); }
    const T& top() const { return data.back(); }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
    void clear() { data.clear(); }
    void print() const { for (const auto& e : data) println(e); }
};

template<typename T> class Queue {
    vector<T> data;
    size_t head = 0;
public:
    void enqueue(const T& val) { data.push_back(val); }
    void dequeue() { if (!empty()) ++head; }
    T& front() { return data[head]; }
    const T& front() const { return data[head]; }
    bool empty() const { return head >= data.size(); }
    size_t size() const { return data.size() - head; }
    void clear() { data.clear(); head = 0; }
    void print() const { for (size_t i = head; i < data.size(); ++i) println(data[i]); }
};

template<typename T> struct ListNode {
    T val;
    ListNode* next;
    ListNode(const T& v) : val(v), next(nullptr) {}
};

template<typename T> class LinkedList {
    ListNode<T>* head = nullptr;
public:
    ~LinkedList() { clear(); }
    void push_front(const T& val) {
        ListNode<T>* node = new ListNode<T>(val);
        node->next = head;
        head = node;
    }
    void push_back(const T& val) {
        ListNode<T>* node = new ListNode<T>(val);
        if (!head) { head = node; return; }
        ListNode<T>* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    void pop_front() {
        if (!head) return;
        ListNode<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    bool empty() const { return head == nullptr; }
    void clear() { while (!empty()) pop_front(); }
    void print() const {
        ListNode<T>* cur = head;
        while (cur) { println(cur->val); cur = cur->next; }
    }
    bool contains(const T& val) const {
        ListNode<T>* cur = head;
        while (cur) { if (cur->val == val) return true; cur = cur->next; }
        return false;
    }
    size_t size() const {
        size_t cnt = 0;
        ListNode<T>* cur = head;
        while (cur) { ++cnt; cur = cur->next; }
        return cnt;
    }
};

// ====================== SEQUENCE GENERATORS (NEW) ======================
template<typename T> [[nodiscard]] vector<T> range(T start, T stop, T step = 1);
template<typename T> [[nodiscard]] vector<T> range(T stop);
template<typename Container> [[nodiscard]] auto enumerate(const Container& c);
template<typename T> void print_enumerate(const vector<T>& v);

// ====================== CSV (NEW) ======================
[[nodiscard]] vector<vector<string>> read_csv(const string& filename, char delim = ',');
void write_csv(const string& filename, const vector<vector<string>>& data, char delim = ',');

// ====================== CONSOLE TABLE (NEW) ======================
void print_table(const vector<vector<string>>& rows, int padding = 2);

// ====================== BIT OPERATIONS (NEW) ======================
[[nodiscard]] inline bool get_bit(unsigned int n, int pos) noexcept;
[[nodiscard]] inline unsigned int set_bit(unsigned int n, int pos) noexcept;
[[nodiscard]] inline unsigned int clear_bit(unsigned int n, int pos) noexcept;
[[nodiscard]] inline unsigned int toggle_bit(unsigned int n, int pos) noexcept;
[[nodiscard]] inline int count_bits(unsigned int n) noexcept;

// ====================== SIMPLE HASH (NEW) ======================
[[nodiscard]] size_t hash_str(const string& str);
[[nodiscard]] string xor_encrypt_decrypt(const string& data, char key);

// ====================== THREADING (NEW) ======================
template<typename Func> void run_async(Func f);

// ====================== RUN-LENGTH ENCODING (NEW) ======================
[[nodiscard]] string rle_encode(const string& s);
[[nodiscard]] string rle_decode(const string& s);

// ====================== 2D GEOMETRY (NEW) ======================
struct Point { double x, y; };
[[nodiscard]] inline double distance(const Point& a, const Point& b);
struct Line { Point p1, p2; };
[[nodiscard]] inline double slope(const Line& l);
struct Circle { Point center; double radius; };
[[nodiscard]] inline double area(const Circle& c);
[[nodiscard]] inline double circumference(const Circle& c);

// ====================== MULTI PROGRESS BAR (NEW) ======================
class MultiProgressBar {
    vector<int> progresses;
    vector<int> totals;
    vector<string> labels;
    int width;
public:
    MultiProgressBar(int w = 20) : width(w) {}
    void add_bar(const string& label, int total) {
        labels.push_back(label);
        totals.push_back(total);
        progresses.push_back(0);
    }
    void update(int bar_index, int progress);
    void display() const;
};

// ====================== SIMPLE TESTING (NEW) ======================
class TestSuite {
    string name;
    int passed = 0, failed = 0;
public:
    TestSuite(const string& suite_name);
    void assert_true(bool condition, const string& test_name);
    template<typename T> void assert_eq(const T& expected, const T& actual, const string& test_name) {
        assert_true(expected == actual, test_name + " (expected: " + to_str(expected) + ", actual: " + to_str(actual) + ")");
    }
    ~TestSuite();
};

// =========================================================================
//                               IMPLEMENTATIONS
// =========================================================================

string to_lower(string str) {
    for (char& c : str) c = to_lower(c);
    return str;
}

void print(const string& s) noexcept     { cout << s; }
void print(const char* s) noexcept       { cout << s; }
void print(char c) noexcept              { cout << c; }
void print(int n) noexcept               { cout << n; }
void print(float n) noexcept             { cout << n; }
void print(double n) noexcept            { cout << n; }
void print(long int n) noexcept          { cout << n; }
void print(bool b) noexcept              { cout << (b ? "true" : "false"); }

void input(bool& b) {
    string s;
    getline(cin, s);
    s = to_lower(s);
    b = (s == "true" || s == "1" || s == "yes" || s == "y");
}

string input_str(string prompt) {
    if (!prompt.empty()) print(prompt);
    string s;
    getline(cin, s);
    return s;
}

int input_int(string prompt) {
    if (!prompt.empty()) print(prompt);
    int n;
    cin >> n;
    cin.ignore();
    return n;
}

float input_float(string prompt) {
    if (!prompt.empty()) print(prompt);
    float n;
    cin >> n;
    cin.ignore();
    return n;
}

double input_double(string prompt) {
    if (!prompt.empty()) print(prompt);
    double n;
    cin >> n;
    cin.ignore();
    return n;
}

bool input_bool(string prompt) {
    if (!prompt.empty()) print(prompt);
    string s;
    getline(cin, s);
    s = to_lower(s);
    return (s == "true" || s == "1" || s == "yes" || s == "y");
}

// ====================== ARRAY & VECTOR ======================
template<typename T, size_t N>
void print(T (&arr)[N]) {
    for (size_t i = 0; i < N; i++) println(arr[i]);
}

template<typename T>
void print(const vector<T>& v) {
    for (const auto& e : v) println(e);
}

template<typename T, size_t N>
void input(T (&arr)[N]) {
    for (size_t i = 0; i < N; i++) cin >> arr[i];
    cin.ignore();
}

template<typename T>
void input(vector<T>& v) {
    for (auto& e : v) cin >> e;
    cin.ignore();
}

// ====================== FILE & PATH ======================
void write_file(string filename, string mode) {
    mode = to_lower(mode);
    ofstream file(filename, (mode == "app" ? ios::app : ios::out));
    if (!file) { println("##ERROR: Cannot open file##"); return; }
    println("Start writing (type 'exit' to finish):");
    string line;
    while (getline(cin, line)) {
        if (line == "exit") break;
        file << line << endl;
    }
    file.close();
}

void read_file(string filename) {
    ifstream file(filename);
    if (!file) { println("##ERROR: Cannot open file##"); return; }
    string line;
    while (getline(file, line)) println(line);
    file.close();
}

void append_file(string filename, const string& content) {
    ofstream file(filename, ios::app);
    if (file) file << content << endl;
}

string read_file_as_string(const string& filename) {
    ifstream file(filename);
    if (!file) return "";
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

void write_lines(const string& filename, const vector<string>& lines) {
    ofstream file(filename);
    for (const auto& line : lines) file << line << endl;
}

vector<string> read_lines(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) lines.push_back(line);
    return lines;
}

string get_filename(string_view path) {
    size_t pos = path.find_last_of("/\\");
    return (pos == string_view::npos) ? string(path) : string(path.substr(pos + 1));
}

string get_extension(string_view path) {
    size_t pos = path.find_last_of('.');
    return (pos == string_view::npos) ? "" : string(path.substr(pos));
}

string get_parent_path(string_view path) {
    size_t pos = path.find_last_of("/\\");
    return (pos == string_view::npos) ? "" : string(path.substr(0, pos));
}

string get_stem(string_view path) {
    string filename = get_filename(path);
    size_t pos = filename.find_last_of('.');
    return (pos == string_view::npos) ? filename : filename.substr(0, pos);
}

// --- NEW FILE SYSTEM IMPLEMENTATIONS ---
bool file_exists(const string& path) { return filesystem::exists(path); }
bool is_directory(const string& path) { return filesystem::is_directory(path); }
bool is_file(const string& path) { return filesystem::is_regular_file(path); }
vector<string> list_dir(const string& path) {
    vector<string> entries;
    for (const auto& entry : filesystem::directory_iterator(path))
        entries.push_back(entry.path().filename().string());
    return entries;
}
size_t file_size(const string& path) { return filesystem::file_size(path); }
void create_dir(const string& path) { filesystem::create_directory(path); }
void remove_file(const string& path) { filesystem::remove(path); }
void copy_file(const string& from, const string& to) {
    filesystem::copy_file(from, to, filesystem::copy_options::overwrite_existing);
}

// ====================== ENVIRONMENT ======================
string get_env(const string& name) {
    const char* val = getenv(name.c_str());
    return val ? val : "";
}

void set_env(const string& name, const string& value) {
#ifdef _WIN32
    _putenv_s(name.c_str(), value.c_str());
#else
    setenv(name.c_str(), value.c_str(), 1);
#endif
}

// ====================== MATH ======================
int factorial(int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) { c = a + b; a = b; b = c; }
    return b;
}

// --- NEW TRIG & STATS IMPLEMENTATIONS ---
double sin_deg(double deg) noexcept { return sin(to_radians(deg)); }
double cos_deg(double deg) noexcept { return cos(to_radians(deg)); }
double tan_deg(double deg) noexcept { return tan(to_radians(deg)); }
double log_base(double x, double base) noexcept { return log(x) / log(base); }

template<typename T>
double median(vector<T> v) {
    if (v.empty()) return 0.0;
    sort_vec(v);
    size_t n = v.size();
    if (n % 2 == 0) return (v[n/2 - 1] + v[n/2]) / 2.0;
    else return v[n/2];
}

template<typename T>
vector<T> mode(const vector<T>& v) {
    map<T, int> freq;
    for (const auto& x : v) freq[x]++;
    int max_count = 0;
    for (const auto& p : freq) if (p.second > max_count) max_count = p.second;
    vector<T> modes;
    for (const auto& p : freq) if (p.second == max_count) modes.push_back(p.first);
    return modes;
}

template<typename T>
double variance(const vector<T>& v) {
    if (v.empty()) return 0.0;
    double mean = average(v);
    double sum_sq = 0.0;
    for (const auto& x : v) sum_sq += (x - mean) * (x - mean);
    return sum_sq / v.size();
}

template<typename T>
double std_deviation(const vector<T>& v) { return sqrt_val(variance(v)); }

long long nCr(int n, int r) noexcept {
    if (r > n) return 0;
    long long res = 1;
    for (int i = 1; i <= r; ++i) { res *= n - i + 1; res /= i; }
    return res;
}
long long nPr(int n, int r) noexcept {
    if (r > n) return 0;
    long long res = 1;
    for (int i = 0; i < r; ++i) res *= (n - i);
    return res;
}

// ====================== STRING ADVANCED ======================
bool starts_with(string_view str, string_view prefix) noexcept { return str.rfind(prefix, 0) == 0; }
bool ends_with(string_view str, string_view suffix) noexcept {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}
bool contains(string_view str, string_view substr) noexcept { return str.find(substr) != string_view::npos; }

string replace(string_view str, string_view from, string_view to) {
    string result(str);
    size_t pos = result.find(from);
    if (pos != string::npos) {
        result.replace(pos, from.length(), to);
    }
    return result;
}
string replace_all(string_view str, string_view from, string_view to) {
    string result(str);
    size_t pos = 0;
    while ((pos = result.find(from, pos)) != string::npos) {
        result.replace(pos, from.length(), to);
        pos += to.length();
    }
    return result;
}

string to_upper(string str) {
    for (char& c : str) if (c >= 'a' && c <= 'z') c -= 32;
    return str;
}
string capitalize(string str) {
    if (!str.empty()) str[0] = toupper(str[0]);
    return str;
}
string trim(string_view str) {
    size_t start = str.find_first_not_of(" \t\n\r\f");
    if (start == string_view::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r\f");
    return string(str.substr(start, end - start + 1));
}
string ltrim(string_view str) {
    size_t start = str.find_first_not_of(" \t\n\r\f");
    return (start == string_view::npos) ? "" : string(str.substr(start));
}
string rtrim(string_view str) {
    size_t end = str.find_last_not_of(" \t\n\r\f");
    return (end == string_view::npos) ? "" : string(str.substr(0, end + 1));
}

vector<string> split(string_view str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream ss{string(str)};
    while (getline(ss, token, delimiter)) tokens.push_back(token);
    return tokens;
}
string join(const vector<string>& vec, string_view delimiter) {
    if (vec.empty()) return "";
    string result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) result += delimiter.data() + vec[i];
    return result;
}
string repeat(string_view str, int times) {
    if (times <= 0) return "";
    string result;
    result.reserve(str.length() * times);
    for (int i = 0; i < times; ++i) result += str;
    return result;
}

// --- NEW STRING IMPLEMENTATIONS ---
string reverse_str(string str) {
    reverse(str.begin(), str.end());
    return str;
}
bool is_palindrome(string_view str) {
    string s = to_lower(string(str));
    int l = 0, r = s.size() - 1;
    while (l < r) { if (s[l] != s[r]) return false; ++l; --r; }
    return true;
}
string pad_left(string_view str, size_t len, char pad) {
    if (str.length() >= len) return string(str);
    return string(len - str.length(), pad) + string(str);
}
string pad_right(string_view str, size_t len, char pad) {
    if (str.length() >= len) return string(str);
    return string(str) + string(len - str.length(), pad);
}
int count_substr(string_view str, string_view sub) {
    if (sub.empty()) return 0;
    int cnt = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != string_view::npos) { ++cnt; pos += sub.length(); }
    return cnt;
}
string remove_chars(string_view str, string_view chars_to_remove) {
    string result;
    for (char c : str) if (chars_to_remove.find(c) == string_view::npos) result += c;
    return result;
}
string keep_chars(string_view str, string_view chars_to_keep) {
    string result;
    for (char c : str) if (chars_to_keep.find(c) != string_view::npos) result += c;
    return result;
}
vector<string> split_lines(string_view str) { return split(str, '\n'); }

// ====================== VECTOR UTILS ======================
template<typename T> T sum(const vector<T>& v) { T s = 0; for (const auto& x : v) s += x; return s; }
template<typename T> double average(const vector<T>& v) { return v.empty() ? 0.0 : static_cast<double>(sum(v)) / v.size(); }
template<typename T> T max_element(const vector<T>& v) { return *std::max_element(v.begin(), v.end()); }
template<typename T> T min_element(const vector<T>& v) { return *std::min_element(v.begin(), v.end()); }
template<typename T> bool contains(const vector<T>& v, const T& value) { return find(v.begin(), v.end(), value) != v.end(); }
template<typename T> void sort_vec(vector<T>& v) { sort(v.begin(), v.end()); }
template<typename T> void reverse_vec(vector<T>& v) { reverse(v.begin(), v.end()); }
template<typename T> void clear_vec(vector<T>& v) { v.clear(); }
template<typename T> void push_unique(vector<T>& v, const T& value) { if (!contains(v, value)) v.push_back(value); }
template<typename T, typename Predicate> void filter_vec(vector<T>& v, Predicate pred) { v.erase(remove_if(v.begin(), v.end(), [&](const T& x){ return !pred(x); }), v.end()); }
template<typename T, typename Function> void for_each_vec(vector<T>& v, Function func) { for (auto& e : v) func(e); }

// ====================== MAP UTILS ======================
template<typename K, typename V> bool map_contains(const map<K,V>& m, const K& key) noexcept { return m.find(key) != m.end(); }
template<typename K, typename V> bool map_contains(const unordered_map<K,V>& m, const K& key) noexcept { return m.find(key) != m.end(); }
template<typename K, typename V> void print_map(const map<K,V>& m) { for (const auto& p : m) println(p.first, " : ", p.second); }
template<typename K, typename V> void print_map(const unordered_map<K,V>& m) { for (const auto& p : m) println(p.first, " : ", p.second); }

// ====================== TIME ======================
string current_time() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&t), "%H:%M:%S");
    return ss.str();
}
string current_date() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&t), "%Y-%m-%d");
    return ss.str();
}
long long timestamp_ms() noexcept { return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count(); }

// --- NEW DATE/TIME ---
string datetime_str() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
int current_year() { time_t t = time(nullptr); return 1900 + localtime(&t)->tm_year; }
int current_month() { time_t t = time(nullptr); return 1 + localtime(&t)->tm_mon; }
int current_day() { time_t t = time(nullptr); return localtime(&t)->tm_mday; }
string weekday_name() {
    static const char* days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    time_t t = time(nullptr);
    return days[localtime(&t)->tm_wday];
}

// Stopwatch
double Stopwatch::elapsed_seconds() const {
    auto end = chrono::steady_clock::now();
    return chrono::duration<double>(end - start_time).count();
}
long long Stopwatch::elapsed_ms() const {
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start_time).count();
}

// ====================== DEBUG & LOG ======================
void debug(const string& msg) noexcept     { color_yellow(); println("[DEBUG] ", msg); color_reset(); }
void log_info(const string& msg) noexcept  { color_green();  println("[INFO] ", msg); color_reset(); }
void log_warn(const string& msg) noexcept  { color_yellow(); println("[WARN] ", msg); color_reset(); }
void log_error(const string& msg) noexcept { color_red();    println("[ERROR] ", msg); color_reset(); }
void assert_true(bool condition, const string& message) { if (!condition) { log_error(message); exit(1); } }

// ====================== SYSTEM ======================
void clear() noexcept { system("cls"); }
void pause(string message) noexcept { println(message); cin.get(); }
void exit_program(int code) noexcept { exit(code); }
string get_os() noexcept {
#ifdef _WIN32
    return "windows";
#else
    return "linux";
#endif
}

// ====================== RANDOM ======================
void random_init() noexcept { srand(static_cast<unsigned>(time(nullptr))); }
int random_int(int min, int max) noexcept { if (min > max) swap(min, max); return min + rand() % (max - min + 1); }
double random_double(double min, double max) noexcept { if (min > max) swap(min, max); return min + (max - min) * (rand() / (RAND_MAX + 1.0)); }
bool random_bool() noexcept { return random_int(0, 1) == 1; }

// ====================== POINTERS ======================
template<typename T> void print_ptr(const T* ptr) noexcept { println("Address: ", static_cast<const void*>(ptr)); }

// ====================== CONVERSIONS ======================
template<typename T> string to_str(const T& value) { ostringstream oss; oss << value; return oss.str(); }
int to_int(string_view str) { return stoi(string(str)); }
double to_double(string_view str) { return stod(string(str)); }
bool to_bool(string_view str) { string s = to_lower(string(str)); return s == "true" || s == "1" || s == "yes"; }

// ====================== ALGORITHMS ======================
bool is_prime(int n) noexcept {
    if (n <= 1) return false; if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
int gcd(int a, int b) noexcept { while (b != 0) { int t = b; b = a % b; a = t; } return a; }
int lcm(int a, int b) noexcept { return abs(a * b) / gcd(a, b); }

// ====================== BASE64 ======================
string base64_encode(const string& data) {
    static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string result;
    result.reserve(((data.size() + 2) / 3) * 4);
    for (size_t i = 0; i < data.size(); i += 3) {
        unsigned int val = (static_cast<unsigned char>(data[i]) << 16);
        if (i + 1 < data.size()) val |= (static_cast<unsigned char>(data[i + 1]) << 8);
        if (i + 2 < data.size()) val |= static_cast<unsigned char>(data[i + 2]);
        result.push_back(chars[(val >> 18) & 0x3F]);
        result.push_back(chars[(val >> 12) & 0x3F]);
        result.push_back(chars[(val >> 6) & 0x3F]);
        result.push_back(chars[val & 0x3F]);
    }
    size_t padding = (3 - (data.size() % 3)) % 3;
    for (size_t i = 0; i < padding; ++i) result[result.size() - 1 - i] = '=';
    return result;
}
string base64_decode(const string& encoded) {
    static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string result;
    vector<int> decode(256, -1);
    for (int i = 0; i < 64; ++i) decode[chars[i]] = i;
    int val = 0, bits = 0;
    for (char c : encoded) {
        if (decode[c] == -1) continue;
        val = (val << 6) | decode[c];
        bits += 6;
        if (bits >= 8) {
            result.push_back(static_cast<char>((val >> (bits - 8)) & 0xFF));
            bits -= 8;
        }
    }
    return result;
}

// ====================== PROGRESS BAR ======================
void progress_bar(int progress, int total, int width) {
    float percent = static_cast<float>(progress) / total;
    int bars = static_cast<int>(percent * width);
    print("\r[");
    for (int i = 0; i < width; ++i) print(i < bars ? "█" : " ");
    print("] ", static_cast<int>(percent * 100), "%");
    cout.flush();
    if (progress == total) println();
}

// ====================== SORTING ALGORITHMS ======================
template<typename T> void bubble_sort(vector<T>& v) noexcept {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (v[j] > v[j + 1]) swap_val(v[j], v[j + 1]);
}
template<typename T> void selection_sort(vector<T>& v) noexcept {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) if (v[j] < v[min_idx]) min_idx = j;
        swap_val(v[min_idx], v[i]);
    }
}
template<typename T> void insertion_sort(vector<T>& v) noexcept {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        T key = v[i]; int j = i - 1;
        while (j >= 0 && v[j] > key) { v[j + 1] = v[j]; --j; }
        v[j + 1] = key;
    }
}
template<typename T> void merge(vector<T>& v, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = v[l + i];
    for (int j = 0; j < n2; ++j) R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) v[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}
template<typename T> void merge_sort_helper(vector<T>& v, int l, int r) {
    if (l < r) { int m = l + (r - l) / 2; merge_sort_helper(v, l, m); merge_sort_helper(v, m + 1, r); merge(v, l, m, r); }
}
template<typename T> void merge_sort(vector<T>& v) noexcept { merge_sort_helper(v, 0, v.size() - 1); }
template<typename T> int partition(vector<T>& v, int low, int high) {
    T pivot = v[high]; int i = low - 1;
    for (int j = low; j < high; ++j) if (v[j] < pivot) swap_val(v[++i], v[j]);
    swap_val(v[i + 1], v[high]); return i + 1;
}
template<typename T> void quick_sort_helper(vector<T>& v, int low, int high) {
    if (low < high) { int pi = partition(v, low, high); quick_sort_helper(v, low, pi - 1); quick_sort_helper(v, pi + 1, high); }
}
template<typename T> void quick_sort(vector<T>& v) noexcept { quick_sort_helper(v, 0, v.size() - 1); }

// ====================== SEARCH ALGORITHMS ======================
template<typename T> int linear_search(const vector<T>& v, const T& key) noexcept {
    for (size_t i = 0; i < v.size(); ++i) if (v[i] == key) return i;
    return -1;
}
template<typename T> int binary_search(const vector<T>& v, const T& key) noexcept {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == key) return mid;
        if (v[mid] < key) low = mid + 1; else high = mid - 1;
    }
    return -1;
}

// ====================== SEQUENCE GENERATORS ======================
template<typename T> vector<T> range(T start, T stop, T step) {
    vector<T> res;
    if (step > 0) for (T i = start; i < stop; i += step) res.push_back(i);
    else if (step < 0) for (T i = start; i > stop; i += step) res.push_back(i);
    return res;
}
template<typename T> vector<T> range(T stop) { return range(T(0), stop); }
template<typename Container> auto enumerate(const Container& c) {
    vector<pair<size_t, typename Container::value_type>> res;
    size_t idx = 0;
    for (const auto& val : c) res.emplace_back(idx++, val);
    return res;
}
template<typename T> void print_enumerate(const vector<T>& v) { for (size_t i = 0; i < v.size(); ++i) println(i, ": ", v[i]); }

// ====================== CSV ======================
vector<vector<string>> read_csv(const string& filename, char delim) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;
    while (getline(file, line)) data.push_back(split(line, delim));
    return data;
}
void write_csv(const string& filename, const vector<vector<string>>& data, char delim) {
    ofstream file(filename);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) file << delim;
        }
        file << '\n';
    }
}

// ====================== CONSOLE TABLE ======================
void print_table(const vector<vector<string>>& rows, int padding) {
    if (rows.empty()) return;
    vector<size_t> widths(rows[0].size(), 0);
    for (const auto& row : rows)
        for (size_t i = 0; i < row.size(); ++i)
            widths[i] = max(widths[i], row[i].size());
    auto print_sep = [&]() {
        print("+");
        for (size_t w : widths) print(string(w + padding * 2, '-'), "+");
        println();
    };
    print_sep();
    for (const auto& row : rows) {
        print("|");
        for (size_t i = 0; i < row.size(); ++i) {
            string cell = row[i];
            int total = widths[i] + padding * 2;
            int left_pad = (total - cell.size()) / 2;
            int right_pad = total - cell.size() - left_pad;
            print(string(left_pad, ' '), cell, string(right_pad, ' '), "|");
        }
        println();
        print_sep();
    }
}

// ====================== BIT OPERATIONS ======================
bool get_bit(unsigned int n, int pos) noexcept { return (n >> pos) & 1; }
unsigned int set_bit(unsigned int n, int pos) noexcept { return n | (1u << pos); }
unsigned int clear_bit(unsigned int n, int pos) noexcept { return n & ~(1u << pos); }
unsigned int toggle_bit(unsigned int n, int pos) noexcept { return n ^ (1u << pos); }
int count_bits(unsigned int n) noexcept { int cnt = 0; while (n) { cnt += n & 1; n >>= 1; } return cnt; }

// ====================== SIMPLE HASH ======================
size_t hash_str(const string& str) { return hash<string>{}(str); }
string xor_encrypt_decrypt(const string& data, char key) {
    string res = data;
    for (char& c : res) c ^= key;
    return res;
}

// ====================== THREADING ======================
template<typename Func> void run_async(Func f) { thread t(f); t.detach(); }

// ====================== RUN-LENGTH ENCODING ======================
string rle_encode(const string& s) {
    if (s.empty()) return "";
    string res;
    int count = 1;
    char prev = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == prev) ++count;
        else {
            res += prev + to_str(count);
            prev = s[i];
            count = 1;
        }
    }
    res += prev + to_str(count);
    return res;
}
string rle_decode(const string& s) {
    string res;
    for (size_t i = 0; i < s.size(); ) {
        char ch = s[i++];
        string num;
        while (i < s.size() && isdigit(s[i])) num += s[i++];
        int count = to_int(num);
        res.append(count, ch);
    }
    return res;
}

// ====================== 2D GEOMETRY ======================
double distance(const Point& a, const Point& b) { return sqrt_val(pow_val(a.x - b.x, 2) + pow_val(a.y - b.y, 2)); }
double slope(const Line& l) {
    if (l.p1.x == l.p2.x) return INFINITY;
    return (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
}
double area(const Circle& c) { return PI * c.radius * c.radius; }
double circumference(const Circle& c) { return 2 * PI * c.radius; }

// ====================== MULTI PROGRESS BAR ======================
void MultiProgressBar::update(int bar_index, int progress) {
    if (bar_index >= 0 && bar_index < (int)progresses.size()) progresses[bar_index] = progress;
    display();
}
void MultiProgressBar::display() const {
    for (size_t i = 0; i < labels.size(); ++i) {
        print(labels[i], " : ");
        progress_bar(progresses[i], totals[i], width);
        println();
    }
    if (!labels.empty()) print("\033[", labels.size(), "A");
}

// ====================== SIMPLE TESTING ======================
TestSuite::TestSuite(const string& suite_name) : name(suite_name) {
    println("== Running ", name, " ==");
}
void TestSuite::assert_true(bool condition, const string& test_name) {
    if (condition) { color_green(); print("[PASS] "); ++passed; }
    else          { color_red();   print("[FAIL] "); ++failed; }
    color_reset();
    println(test_name);
}
TestSuite::~TestSuite() {
    println("--------------------------------");
    print(name, " finished: ");
    color_green(); print(passed, " passed, ");
    if (failed > 0) color_red(); else color_green();
    println(failed, " failed.");
    color_reset();
}