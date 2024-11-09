#ifndef TESTEVALUATOR_H
#define TESTEVALUATOR_H

#include <iostream>
#include <string>

class TestEvaluator
{
public:
    TestEvaluator() : tests_passed(0), tests_failed(0) {}
    ~TestEvaluator() {}

    void title(const std::string &test_title) // Agregado el método title
    {
        std::cout << "\n=== " << test_title << " ===" << std::endl;
    }

    void evaluate(const std::string &test_name, bool test_expr)
    {
        if (test_expr)
        {
            std::cout << "\t\x1B[32m[PASSED] Test: " + test_name + "\x1B[0m " << std::endl;
            tests_passed++;
        }
        else
        {
            std::cout << "\t\x1B[31m[FAILED] Test: " + test_name + "\x1B[0m " << std::endl;
            tests_failed++;
        }
    }

    void summary() const
    {
        std::cout << "\nTests Passed: " << tests_passed << "\nTests Failed: " << tests_failed << "\n";
    }

private:
    int tests_passed;
    int tests_failed;
};

#endif // TESTEVALUATOR_H
